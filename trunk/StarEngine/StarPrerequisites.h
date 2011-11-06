/************************************************************************/
/* Filename: StarPrerequisites.h
/* Author: Star
/* Created:[11/10/18]
/* Describe:all prerequisites                                            
/************************************************************************/

#ifndef _ZH_STARPREREQUISITES_H_
#define _ZH_STARPREREQUISITES_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER


#include <iostream>
#include <assert.h>
#include <string>

namespace Star
{
#	define _StarExport __declspec( dllexport )

	typedef std::string _StringBase;

	typedef _StringBase String;

	class CStarEngine;
	class CRenderSystem;
	class CRenderWindow;
	class CLogManager;
}

#include "StarStdHeaders.h"

#endif // end of _ZH_STARPREREQUISITES_H_