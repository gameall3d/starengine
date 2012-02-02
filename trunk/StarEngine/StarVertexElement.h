/************************************************************************/
/* Filename: StarVertexElement.h
/* Author: Star
/* Created: [11/11/06]
/* Describe:                                            
/************************************************************************/

#ifndef _ZH_STARVERTEXELEMENT_H_
#define _ZH_STARVERTEXELEMENT_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarPrerequisites.h"

namespace Star
{

	enum EVertexElementUsage
	{
		// Position
		VEU_POSITION,
		// Sepcial for DX
		VEU_POSITION_RHW,
		// Normal
		VEU_NORMAL,
		// Diffuse
		VEU_DIFFUSE,
		// Specular
		VEU_SPECULAR,
		// Texture Coordinate
		VEU_TEXTURE_COORDINATES,
		// Blending weights
		VEU_BLEND_WEIGHTS,
		// Blending indices
		VEU_BLEND_INDICES,
		// Binormal
		VEU_BINORMAL,
		// Tangent
		VEU_TANGENT
	};


	// Vertex Element Type
	enum EVertexElementType
	{
		VET_FLOAT1 = 0,
		VET_FLOAT2 = 1,
		VET_FLOAT3 = 2,
		VET_FLOAT4 = 3,
		/// alias to more specific colour type - use the current rendersystem's colour packing
		VET_COLOUR = 4,
		VET_SHORT1 = 5,
		VET_SHORT2 = 6,
		VET_SHORT3 = 7,
		VET_SHORT4 = 8,
		VET_UBYTE4 = 9,
		/// D3D style compact colour
		VET_COLOUR_ARGB = 10,
		/// GL style compact colour
		VET_COLOUR_ABGR = 11
	};


	class _StarExport CVertexElement
	{
	public:
		CVertexElement(unsigned short source, size_t offset, EVertexElementType type,
						EVertexElementUsage usage, unsigned short texNum = 0);
		~CVertexElement();

		unsigned short      GetSource(void) const { return m_uSource; }
		size_t		        GetOffset(void) const { return m_Offset; }
		EVertexElementType  GetType(void) const { return m_eType; }
		EVertexElementUsage GetUsage(void) const { return m_eUsage; }
		unsigned short      GetTexNum(void) const { return m_TexNum; }
		
		// Utility method for helping to calculate offsets
		static size_t GetTypeSize(EVertexElementType);

	protected:
		unsigned short m_uSource;
		// the offset in the buffer that this element starts at
		size_t m_Offset;
		EVertexElementType m_eType;
		EVertexElementUsage m_eUsage;

		// get Texture count
		unsigned short m_TexNum;
	};
}

#endif // end of _ZH_STARVERTEXELEMENT_H_