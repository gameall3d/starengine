/************************************************************************/
/* Filename: StarLog.h
/* Author: Star
/* Created: [11/10/27]
/* Describe: log for the engine                                           
/************************************************************************/

#ifndef _ZH_STARLOG_H_
#define _ZH_STARLOG_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarPrerequisites.h"

namespace Star
{
	class CLog
	{
	public:
		CLog(const String& filename);
		~CLog();

		void LogMessage(const String& message);

	protected:
		std::ofstream m_pfLog;
	};
}

#endif // end of _ZH_STARLOG_H_