/************************************************************************/
/* Filename:StarLogManager.h
/* Author: Star
/* Created: [11/10/27]
/* Describe: manager the log                                           
/************************************************************************/

#ifndef _ZH_STARLOGMANAGER_H_
#define _ZH_STARLOGMANAGER_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarPrerequisites.h"
#include "StarSingleton.h"
#include "StarLog.h"

namespace Star
{
	class _StarExport CLogManager:CSingleton<CLogManager>
	{
	public:
		CLogManager();
		~CLogManager();

		static CLogManager* GetSingletonPtr();
		static CLogManager& GetSingleton();

		CLog* CreateLog(const String& filename);
		void LogMessage(const String& message);

	protected:
		CLog * m_pDefaultLog;
	};

	template<> CLogManager* CSingleton<CLogManager>::m_spSingleton = NULL;
}

#endif // end of _ZH_STARLOGMANAGER_H_