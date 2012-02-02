#include "StarD3D9Mappings.h"

namespace Star
{
	CD3D9Mappings::CD3D9Mappings()
	{

	}

	CD3D9Mappings::~CD3D9Mappings()
	{

	}

	DWORD CD3D9Mappings::Get(CVertexBuffer::ELockOption lockop)
	{
		DWORD ret = 0;
		switch(lockop)
		{
		case CVertexBuffer::VTL_NORMAL:
			ret |= D3DLOCK_DISCARD;
			break;
		case CVertexBuffer::VTL_DISCARD:
			ret |= D3DLOCK_DISCARD;
			break;
		case CVertexBuffer::VTL_READ_ONLY:
			ret |= D3DLOCK_READONLY;
			break;
		case CVertexBuffer::VTL_NO_OVERWRITE:
			ret |= D3DLOCK_NOOVERWRITE;
			break;
		}

		return ret;
	}

	D3DPRIMITIVETYPE CD3D9Mappings::Get(COperationOnData::EOperationType op)
	{
		D3DPRIMITIVETYPE primType = D3DPT_TRIANGLELIST;

		switch(op)
		{
		case COperationOnData::OT_POINT_LIST:
			primType = D3DPT_POINTLIST;
			break;
		case COperationOnData::OT_LINE_LIST:
			primType = D3DPT_LINELIST;
			break;
		case COperationOnData::OT_LINE_STRIP:
			primType = D3DPT_LINESTRIP;
			break;
		case COperationOnData::OT_TRIANGLE_LIST:
			primType = D3DPT_TRIANGLELIST;
			break;
		case COperationOnData::OT_TRIANGLE_STRIP:
			primType = D3DPT_TRIANGLESTRIP;
			break;
		case COperationOnData::OT_TRIANGLE_FAN:
			primType = D3DPT_TRIANGLEFAN;
			break;
		}

		return primType;
	}
}