/************************************************************************/
/* Filename: StarD3D9Prerequisites.h
/* Author: Star
/* Created: [11/12/30]
/* Describe: for the requisites of using d3d9                                            
/************************************************************************/

#ifndef _ZH_STARD3D9PREREQUISITES_H_
#define _ZH_STARD3D9PREREQUISITES_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarPrerequisites.h"

// Define D3D version
#define DIRECT3D_VERSION 0x0900

// some D3D commonly use macro
#define SAFE_DELETE(p)		 { if(p) { delete (p);	   (p) = NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[](p);    (p) = NULL; } }
#define SAFE_RELEASE(p)		 { if(p) { (p)->Release(); (p) = NULL; } }

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <d3d9.h>
#include <d3dx9.h>
#include <dxerr9.h>

namespace Star
{
	// predefine class
	class CD3D9RenderSystem;
	class CD3D9RenderWindow;
	class CD3D9VertexBuffer;
	class CD3D9Mappings;
}


#endif // end of _ZH_STARD3D9PREREQUISITES_H_