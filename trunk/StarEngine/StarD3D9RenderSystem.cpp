#include "StarD3D9RenderSystem.h"
#include "StarD3D9RenderWindow.h"

namespace Star
{
	CD3D9RenderSystem::CD3D9RenderSystem(HINSTANCE hInst):m_hInstance(hInst),m_pD3D(0),m_pD3DDevice(0)
	{
		if (FAILED(m_pD3D=Direct3DCreate9(D3D_SDK_VERSION)))		
		{
			//log
		}
	}

	CD3D9RenderSystem::~CD3D9RenderSystem()
	{

	}

	CRenderWindow* CD3D9RenderSystem::CreateRenderWindow(std::string title, int nWidth, int nHeight, bool bFullscreen)
	{
		m_pRenderWindow = new CD3D9RenderWindow(m_hInstance, m_pD3D, &m_pD3DDevice);
		m_pRenderWindow->Create(title, nWidth, nHeight, bFullscreen);

		return m_pRenderWindow;
	}

	void CD3D9RenderSystem::CalcPojectectMatrix(float fov, float aspect, float near, float far)
	{
		if (!m_pD3DDevice)
			return;

		D3DXMATRIX projection;

		D3DXMatrixPerspectiveFovLH(&projection, fov, aspect, near, far);

		m_pD3DDevice->SetTransform(D3DTS_PROJECTION, &projection);
		
	}

	void CD3D9RenderSystem::CalcOrthoMatrix(float fov, float aspect, float near, float far)
	{

	}

	void CD3D9RenderSystem::BeginFrame()
	{

	}

	void CD3D9RenderSystem::EndFrame()
	{

	}

	void CD3D9RenderSystem::Render()
	{
		if (m_pD3DDevice)
		{
			m_pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,255,0), 1, 0);
			
			m_pD3DDevice->BeginScene();
			m_pD3DDevice->EndScene();
			m_pD3DDevice->Present(NULL, NULL, NULL, NULL);
		}
	}
}