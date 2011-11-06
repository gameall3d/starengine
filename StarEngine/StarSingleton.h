/************************************************************************/
/* Filename: Singleton.h
/* Author: Star
/* Created: [11/10/18]
/* Describe:                                            
/************************************************************************/

#ifndef _ZH_SINGLETON_H_
#define _ZH_SINGLETON_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER


namespace Star
{
	template<typename T>
	class CSingleton
	{
	protected:
		static T* m_spSingleton;
	public:
		CSingleton()
		{
			assert(NULL == m_spSingleton);

			m_spSingleton = static_cast<T*>(this);
		}

		~CSingleton()
		{
			assert(m_spSingleton);
			m_spSingleton = NULL;
		}

		static T& GetSingleton(void)
		{
			assert(m_spSingleton);
			return (*m_spSingleton);
		}

		static T* GetSingletonPtr(void)
		{
			return m_spSingleton;
		}
	};

// 	template<typename T>
// 	T CSingleton<T>::m_spSingleton = T();

}

#endif // end of _ZH_SINGLETON_H_