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
#include <string>

namespace Star
{
	class _StarExport CRenderSystem
	{
	public:
		CRenderSystem();
		virtual ~CRenderSystem();

		virtual CRenderWindow* CreateRenderWindow(std::string title, int nWidth, int nHeight, bool bFullscreen);

		void Shutdown();

		// transform
		void CalcPojectectMatrix(float fov, float aspect, float near, float far) = 0;
		void CalcOrthoMatrix(float fov, float aspect, float near, float far) = 0;

		// for render
		virtual void BeginFrame()=0;
		virtual void Render()=0;
		virtual void EndFrame()=0;

	protected:
		CRenderWindow* m_pRenderWindow;
	};
}

#endif // end of _ZH_STARRENDERSYSTEM_H_