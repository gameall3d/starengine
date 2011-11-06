/************************************************************************/
/* Filename: StarD3D9RenderSystem.h
/* Author: Star
/* Created: [11/10/20]
/* Describe: Direct3D9 render                                           
/************************************************************************/

#include "StarPrerequisites.h"
#include "StarRenderSystem.h"
#include <d3d9.h>

namespace Star
{
	class _StarExport CD3D9RenderSystem:public CRenderSystem
	{
	public:
		CD3D9RenderSystem(HINSTANCE hInst);
		~CD3D9RenderSystem();

		CRenderWindow* CreateRenderWindow(std::string title, int nWidth, int nHeight, bool bFullscreen);

		// transform
		void CalcPojectectMatrix(float fov, float aspect, float near, float far);
		void CalcOrthoMatrix(float fov, float aspect, float near, float far);

		// render
		void BeginFrame();
		void Render();
		void EndFrame();
	private:
		HINSTANCE m_hInstance;
		LPDIRECT3D9 m_pD3D;
		LPDIRECT3DDEVICE9 m_pD3DDevice;
	};
}