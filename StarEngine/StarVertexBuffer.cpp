#include "StarVertexBuffer.h"

namespace Star
{
	CVertexBuffer::CVertexBuffer(CVertexDeclaration decalaration, size_t numVertices):
	m_Declaration(decalaration),m_nNumVertices(numVertices)
	{
		m_nTotalSize = numVertices * decalaration.GetStride();
		m_nVertexSize = decalaration.GetStride();
	}

	CVertexBuffer::~CVertexBuffer()
	{

	}

	void* CVertexBuffer::Lock(size_t offset, size_t length, CVertexBuffer::ELockOption lockOption)
	{
		return NULL;
	}

	void CVertexBuffer::Unlock()
	{

	}
}