/************************************************************************/
/* Filename:StarRenderWindow.h
/* Author: Star
/* Created: [11/10/20]
/* Describe: base render window class                                           
/************************************************************************/

#ifndef _ZH_STARRENDERWINDOW_H_
#define _ZH_STARRENDERWINDOW_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarPrerequisites.h"

namespace Star
{
	class _StarExport CRenderWindow
	{
	public:
		CRenderWindow(void);
		~CRenderWindow(void);

		virtual void Create(std::string title, int nWidth, int nHeight, bool bFullscreen) = 0;
		bool IsFullscreen();

	protected:
		bool m_bIsFullscreen;
		int m_nWidth;
		int m_nHeight;
		
	};
}




#endif // end of _ZH_STARRENDERWINDOW_H_
