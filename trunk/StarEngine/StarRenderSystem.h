/************************************************************************/
/* Filename:StarRenderSystem.h
/* Author: Star
/* Created:[11/10/20]
/* Describe:base class of render system                                            
/************************************************************************/

#ifndef _ZH_STARRENDERSYSTEM_H_
#define _ZH_STARRENDERSYSTEM_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarPrerequisites.h"
#include "StarVertexBuffer.h"
#include "StarOperationOnData.h"

#include <string>

namespace Star
{
	class _StarExport CRenderSystem
	{
	public:
		CRenderSystem();
		virtual ~CRenderSystem();

		virtual CRenderWindow* CreateRenderWindow(std::string title, int nWidth, int nHeight, bool bFullscreen) = 0;

		void Shutdown();

		// transform
		virtual void CalcPojectectMatrix(float fov, float aspect, float near, float far) = 0;
		virtual void CalcOrthoMatrix(float fov, float aspect, float near, float far) = 0;

		// for render
		virtual CVertexBufferPtr CreateVertexBuffer(CVertexDeclaration& declaration, size_t nNumVertices) = 0;
		virtual void RenderVertexBuffer(CVertexBufferPtr pVertexBuffer) = 0;
		virtual void RenderOnData(const COperationOnData& op) = 0;
		virtual void BeginFrame() = 0;
		virtual void Render() = 0;
		virtual void EndFrame() = 0;
		virtual void SwapBuffers() = 0;

	protected:
		CRenderWindow* m_pRenderWindow;
	};
}

#endif // end of _ZH_STARRENDERSYSTEM_H_