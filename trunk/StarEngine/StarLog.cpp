#include "StarLog.h"

namespace Star
{
	CLog::CLog(const String& filename)
	{
		m_pfLog.open(filename.c_str());
	}

	CLog::~CLog()
	{
		m_pfLog.close();
	}

	void CLog::LogMessage(const String& message)
	{
		struct tm* pTime;
		time_t ctTime;
		time(&ctTime);
		pTime = localtime(&ctTime);
		m_pfLog<<std::setw(2) << std::setfill('0') << pTime->tm_hour
			<< ":" << std::setw(2) << std::setfill('0') << pTime->tm_min
			<< ":" << std::setw(2) << std::setfill('0') << pTime->tm_sec
			<< ":" << message << std::endl;

		m_pfLog.flush();
	}
}