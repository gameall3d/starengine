#include "StarLogManager.h"

namespace Star
{
	CLogManager* CLogManager::GetSingletonPtr()
	{
		return m_spSingleton;
	}

	CLogManager& CLogManager::GetSingleton()
	{
		assert(m_spSingleton);
		return (*m_spSingleton);
	}

	CLogManager::CLogManager():m_pDefaultLog(0)
	{

	}

	CLogManager::~CLogManager()
	{
		delete m_pDefaultLog;
	}

	CLog* CLogManager::CreateLog(const Star::String& filename)
	{
		CLog* newLog = new CLog(filename);

		if (!m_pDefaultLog)
			m_pDefaultLog = newLog;

		return newLog;
	}

	void CLogManager::LogMessage(const String& message)
	{
		if (m_pDefaultLog)
			m_pDefaultLog->LogMessage(message);
	}
}