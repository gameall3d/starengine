#include "StarVertexElement.h"


namespace Star
{
	CVertexElement::CVertexElement(unsigned short source, size_t offset, EVertexElementType type,
		EVertexElementUsage usage, unsigned short texNum /* = 0*/)
	:m_uSource(source),m_Offset(offset),m_eType(type),m_eUsage(usage),m_TexNum(texNum)
	{

	}

	CVertexElement::~CVertexElement()
	{

	}

	size_t CVertexElement::GetTypeSize(EVertexElementType eType)
	{
		switch(eType)
		{
		case VET_COLOUR:
		case VET_COLOUR_ABGR:
		case VET_COLOUR_ARGB:
			return sizeof(unsigned long);
		case VET_FLOAT1:
			return sizeof(float);
		case VET_FLOAT2:
			return sizeof(float)*2;
		case VET_FLOAT3:
			return sizeof(float)*3;
		case VET_FLOAT4:
			return sizeof(float)*4;
		case VET_SHORT1:
			return sizeof(short);
		case VET_SHORT2:
			return sizeof(short)*2;
		case VET_SHORT3:
			return sizeof(short)*3;
		case VET_SHORT4:
			return sizeof(short)*4;
		case VET_UBYTE4:
			return sizeof(unsigned char)*4;
		}

		return 0;
	}
}
