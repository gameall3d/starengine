#include "StarEngine.h"

#include <Windows.h>
#include "StarLogManager.h"

namespace Star
{
	
	//CStarEngine* CStarEngine::m_spSingleton = 0;



	CStarEngine* CStarEngine::GetSingletonPtr()
	{
		return m_spSingleton;
	}

	CStarEngine& CStarEngine::GetSingleton()
	{
		assert(m_spSingleton);
		return (*m_spSingleton);
	}

	CStarEngine::CStarEngine(const String& logName):m_bEndRender(false),m_pLogManager(0)
	{
		if (CLogManager::GetSingletonPtr() == NULL)
		{
			m_pLogManager = new CLogManager();
			m_pLogManager->CreateLog(logName);
		}

		CLogManager::GetSingletonPtr()->LogMessage("StarEngine Initialing");
	}

	CStarEngine::~CStarEngine()
	{
		delete m_pRenderSystem;
		delete m_pLogManager;
	}

	void CStarEngine::SetRenderSystem(CRenderSystem* renderSystem)
	{
		m_pRenderSystem = renderSystem;
	}

	void CStarEngine::StartRendering()
	{
		while (!m_bEndRender)
		{
			MSG  msg;
			ZeroMemory(&msg, sizeof(msg));
			
			while( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
			{

				if (msg.message == WM_QUIT)
					return;
				TranslateMessage( &msg );
				DispatchMessage( &msg );

			}

			if (!RenderOneFrame())
				break;
		}
		
	}

	bool CStarEngine::RenderOneFrame()
	{
		m_pRenderSystem->Render();
		return true;
	}
}
