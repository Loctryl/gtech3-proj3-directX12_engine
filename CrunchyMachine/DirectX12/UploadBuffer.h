#pragma once
#include "Resources/framework.h"

struct ConstantBuffer {
};

class UploadBufferBase {
public:
	UploadBufferBase() {}
	virtual ~UploadBufferBase() {}

	ID3D12Resource* Resource() {
		return mUpload;
	}

	void CopyData(ConstantBuffer* pCB) {
		memcpy(mData, pCB, mElementByteSize);
	}

protected:
	ID3D12Resource* mUpload;
	BYTE* mData;
	UINT mElementByteSize;
	bool mIsConstantBuffer;
};

template<typename T>
class UploadBuffer : public UploadBufferBase
{
public:
	UploadBuffer(ID3D12Device* device, UINT elementCount, bool isConstantBuffer) 
	{
		mIsConstantBuffer = isConstantBuffer;
		mElementByteSize = sizeof(T);

		if (isConstantBuffer)
			mElementByteSize = (sizeof(T) + 255) & ~255;

		device->CreateCommittedResource(
			&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD),
			D3D12_HEAP_FLAG_NONE,
			&CD3DX12_RESOURCE_DESC::Buffer(mElementByteSize * elementCount),
			D3D12_RESOURCE_STATE_GENERIC_READ,
			nullptr,
			IID_PPV_ARGS(&mUpload));

		mUpload->Map(0, nullptr, reinterpret_cast<void**>(&mData));
	}

	UploadBuffer(const UploadBuffer& rhs) = delete;

	UploadBuffer& operator=(const UploadBuffer& rhs) = delete;

	~UploadBuffer()
	{
		if (mUpload != nullptr)
			mUpload->Unmap(0, nullptr);

		mData = nullptr;
	}

	ID3D12Resource* GetResource()const
	{
		return mUpload;
	}

	BYTE* GetMappedData()
	{
		return mData;
	}

	void CopyData(int elementIndex, const T& data)
	{
		memcpy(&mData[elementIndex * mElementByteSize], &data,
			sizeof(T));
	}

};

