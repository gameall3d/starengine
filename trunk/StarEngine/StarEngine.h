/************************************************************************/
/* Filename:StarEngine.h
/* Author: Star
/* Created:[11/10/18]
/* Describe: the root of engine                                            
/************************************************************************/

#ifndef _ZH_STARENGINE_H_
#define _ZH_STARENGINE_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarPrerequisites.h"
#include "StarSingleton.h"
#include "StarRenderSystem.h"

namespace Star
{
	class _StarExport CStarEngine:CSingleton<CStarEngine>
	{
	public:
		CStarEngine(const String& logName = "Star.log");
		~CStarEngine();

		static CStarEngine* GetSingletonPtr();
		static CStarEngine& GetSingleton();

		void SetRenderSystem(CRenderSystem* renderSystem);
		void StartRendering();
		bool RenderOneFrame();

	private:
		//static CStarEngine* m_spSingleton;
		CRenderSystem* m_pRenderSystem;
		
		// singletons
		CLogManager* m_pLogManager;

		bool m_bEndRender;
	};

	template<> CStarEngine* CSingleton<CStarEngine>::m_spSingleton = NULL;
}

#endif // end of _ZH_STARENGINE_H_