/************************************************************************/
/* Filename: StarD3D9Mappings.h
/* Author: Star
/* Created: [12/1/4]
/* Describe: Convert the StarEngine type to D3D type                                          
/************************************************************************/

#ifndef _ZH_STARD3D9MAPPINGS_H_
#define _ZH_STARD3D9MAPPINGS_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarD3D9Prerequisites.h"
#include "StarVertexBuffer.h"
#include "StarOperationOnData.h"

namespace Star
{
	class CD3D9Mappings
	{
	public:
		CD3D9Mappings();
		~CD3D9Mappings();


		static DWORD Get(CVertexBuffer::ELockOption lockop);
		static D3DPRIMITIVETYPE Get(COperationOnData::EOperationType op);
	};
}

#endif // end of _ZH_STARD3D9MAPPINGS_H_