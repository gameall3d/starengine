/************************************************************************/
/* Filename: StarD3D9RenderWindow.h
/* Author: Star
/* Created: [11/10/20]
/* Describe:direct3d render window                                            
/************************************************************************/

#ifndef _ZH_STARD3DRENDERWINDOW_H_
#define _ZH_STARD3DRENDERWINDOW_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarPrerequisites.h"
#include "StarRenderWindow.h"


#include <d3d9.h>

namespace Star
{
	class _StarExport CD3D9RenderWindow:public CRenderWindow
	{
	public:
		CD3D9RenderWindow(HINSTANCE hInst, LPDIRECT3D9 pD3D, LPDIRECT3DDEVICE9* ppD3DDevice);
		~CD3D9RenderWindow();

		static LRESULT CALLBACK MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		void Create(std::string title, int nWidth, int nHeight, bool bFullscreen);
		bool CreateD3DDevice();
	private:
		HWND m_hWnd;
		HINSTANCE m_hInstance;
		LPDIRECT3D9 m_pD3D;
		LPDIRECT3DDEVICE9* m_ppD3DDevice;
	};
}

#endif // end of _ZH_STARD3DRENDERWINDOW_H_


