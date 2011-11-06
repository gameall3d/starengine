#include "..\StarEngine\StarEngine.h"
#include "..\StarEngine\StarD3D9RenderSystem.h"
#include <Windows.h>



using namespace Star;
int WINAPI WinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	CStarEngine* pStar = new CStarEngine();
	CD3D9RenderSystem* pRs = new CD3D9RenderSystem(hInstance);
	pRs->CreateRenderWindow("First Window", 800, 600, false);
	CStarEngine::GetSingletonPtr()->SetRenderSystem(pRs);

	CStarEngine::GetSingletonPtr()->StartRendering();


	return 0;
}