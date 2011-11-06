#include "StarD3D9RenderWindow.h"

namespace Star
{
	CD3D9RenderWindow::CD3D9RenderWindow(HINSTANCE hInst, LPDIRECT3D9 pD3D, LPDIRECT3DDEVICE9* ppD3DDevice):
	m_hInstance(hInst), m_pD3D(pD3D), m_ppD3DDevice(ppD3DDevice)
	{

	}

	CD3D9RenderWindow::~CD3D9RenderWindow()
	{
	}

	bool CD3D9RenderWindow::CreateD3DDevice()
	{
		D3DDISPLAYMODE dispMode;
		D3DCAPS9 caps;
		D3DPRESENT_PARAMETERS d3dpp;
		ZeroMemory(&d3dpp, sizeof(d3dpp));

		if (FAILED(m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &dispMode)))
			return false;

		if (FAILED(m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps)))
			return false;

		DWORD processing = 0;
		if (caps.VertexProcessingCaps != 0)
			processing = D3DCREATE_HARDWARE_VERTEXPROCESSING|D3DCREATE_PUREDEVICE;
		else
			processing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

		if (m_bIsFullscreen)
		{
			d3dpp.FullScreen_RefreshRateInHz = dispMode.RefreshRate;
			d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
		}
		else
			d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

		d3dpp.Windowed = !m_bIsFullscreen;
		d3dpp.BackBufferWidth = m_nWidth;
		d3dpp.BackBufferHeight = m_nHeight;
		d3dpp.hDeviceWindow = m_hWnd;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.BackBufferFormat = dispMode.Format;
		d3dpp.BackBufferCount = 1;
		d3dpp.EnableAutoDepthStencil = TRUE;
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

		if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
			m_hWnd, processing, &d3dpp, m_ppD3DDevice)))
			return false;

		if (NULL == *m_ppD3DDevice)
			return false;

		return true;
	}


	void CD3D9RenderWindow::Create(std::string title, int nWidth, int nHeight, bool bFullscreen)
	{
		WNDCLASSEX wc = {sizeof(WNDCLASSEX), CS_CLASSDC, CD3D9RenderWindow::MsgProc, 0L, 0L, 
						GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
						"D3DWnd", NULL};

		RegisterClassEx(&wc);

		m_hWnd = CreateWindow("D3DWnd", title.c_str(), WS_OVERLAPPEDWINDOW, 
							 100, 100, nWidth, nHeight, NULL, NULL, 
							 m_hInstance,this);

		m_bIsFullscreen = bFullscreen;
		m_nWidth = nWidth;
		m_nHeight = nHeight;
		ShowWindow(m_hWnd, SW_SHOWDEFAULT);

		CreateD3DDevice();
	}

	LRESULT CALLBACK CD3D9RenderWindow::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch(uMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
			break;
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

