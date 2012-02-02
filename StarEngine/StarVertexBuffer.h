/************************************************************************/
/* Filename:StarVertexBuffer.h
/* Author: Star
/* Created: [11/11/06]
/* Describe:                                            
/************************************************************************/

#ifndef _ZH_STARVERTEXBUFFER_H_
#define _ZH_STARVERTEXBUFFER_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarPrerequisites.h"
#include "StarVertexDeclaration.h"

namespace Star
{
	class _StarExport CVertexBuffer
	{
	public:

		enum EUsage
		{
			VTU_STATIC,
			VTU_DYNAMIC,
			VTU_WRITE_ONLY,
			VTU_DISCARDABLE
		};

		enum ELockOption
		{
			VTL_NORMAL,
			VTL_DISCARD,
			VTL_READ_ONLY,
			VTL_NO_OVERWRITE
		};

		CVertexBuffer(CVertexDeclaration decalaration, size_t numVertices);
		~CVertexBuffer();

		virtual void* Lock(size_t offset, size_t length,ELockOption lockOption); 
		virtual void Unlock(void);

		size_t GetSizeInBytes() { return m_nSizeInBytes; }
		size_t GetTotalSize() { return m_nTotalSize; }

		// Gets the size in bytes of a single vertex in this buffer
		size_t GetVertexSize() { return m_nVertexSize; }
		// Get the number of vertices in this buffer
		size_t GetNumVertices() { return m_nNumVertices; }
	protected:
		size_t m_nTotalSize;
		size_t m_nSizeInBytes;
		EUsage m_usage;
		size_t m_nLockStart;
		size_t m_nLockSize;

		// for the vertex
		size_t m_nVertexSize;
		size_t m_nNumVertices;

		// Declaration of this buffer
		CVertexDeclaration m_Declaration;
	};

	typedef CVertexBuffer* CVertexBufferPtr;
}

#endif // end of _ZH_STARVERTEXBUFFER_H_