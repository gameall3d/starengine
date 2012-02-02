/************************************************************************/
/* Filename: StarD3DVertexBuffer.h
/* Author: Star
/* Created:[11/12/31]
/* Describe: D3D buffer                                           
/************************************************************************/

#ifndef _ZH_STARD3DVERTEXBUFFER_H_
#define _ZH_STARD3DVERTEXBUFFER_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarD3D9Prerequisites.h"
#include "StarVertexBuffer.h"

namespace Star
{
	class _StarExport CD3D9VertexBuffer : public CVertexBuffer
	{
	public:
		CD3D9VertexBuffer(LPDIRECT3DDEVICE9 pDev,CVertexDeclaration declaration, size_t numVertices);
		~CD3D9VertexBuffer();

		DWORD DeclarationToFVF(void);

		DWORD GetFVF(void) const { return m_dwFVF; }
		LPDIRECT3DVERTEXBUFFER9 GetD3DVB(void) const { return m_pD3DVB; }
		size_t GetStride(void) const { return m_Declaration.GetStride(); }

		virtual void* Lock(size_t offset, size_t length,ELockOption lockOption); 
		virtual void Unlock();

	private:
		LPDIRECT3DDEVICE9 m_pD3DDev;
		LPDIRECT3DVERTEXBUFFER9 m_pD3DVB;
		DWORD m_dwFVF;
	};
}


#endif // end of _ZH_STARD3DVERTEXBUFFER_H_