/************************************************************************/
/* Filename: StarFramelistener.h
/* Author: Star
/* Created: [12/1/4]
/* Describe: listen the event of every frame                                            
/************************************************************************/

#ifndef _ZH_STARFRAMELISTENER_H_
#define _ZH_STARFRAMELISTENER_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

namespace Star
{
	class _StarExport CFrameListener
	{
	public:
		CFrameListener(){};
		~CFrameListener(){};

		virtual bool OnFrameStarted() = 0;
		virtual bool OnFrameEnded() = 0;
	};
}

#endif // end of _ZH_STARFRAMELISTENER_H_