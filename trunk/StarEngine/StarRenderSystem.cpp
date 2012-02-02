#include "StarRenderSystem.h"

namespace Star
{
	CRenderSystem::CRenderSystem():m_pRenderWindow(0)
	{

	}

	CRenderSystem::~CRenderSystem()
	{

	}

// 	CRenderWindow* CRenderSystem::CreateRenderWindow(std::string title, int nWidth, int nHeight, bool bFullscreen)
// 	{
// 		return NULL;
// 	}

	void CRenderSystem::Shutdown()
	{
		if (m_pRenderWindow)
			delete m_pRenderWindow;
	}
}
