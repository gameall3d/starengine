/************************************************************************/
/* Filename: StarOperationOnData.h
/* Author: Star
/* Created: [12/1/4]
/* Describe: Operation on the vertexbuffer or indexbuffer                                            
/************************************************************************/

#ifndef _ZH_STAROPERATIONONDATA_H_
#define _ZH_STAROPERATIONONDATA_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarPrerequisites.h"
#include "StarVertexBuffer.h"

namespace Star
{
	class _StarExport COperationOnData
	{
	public:
		COperationOnData():
		m_pVertexBuffer(NULL),m_eOperationType(OT_TRIANGLE_LIST),m_bUseIndex(false),
		m_nVertexStart(0), m_nVertexCount(0)
		{};
		~COperationOnData(){};

		enum EOperationType
		{
			OT_POINT_LIST = 1,
			OT_LINE_LIST,
			OT_LINE_STRIP,
			OT_TRIANGLE_LIST,
			OT_TRIANGLE_STRIP,
			OT_TRIANGLE_FAN,
		};

	public:
		CVertexBuffer* m_pVertexBuffer;
		EOperationType m_eOperationType;
		bool m_bUseIndex;

		// start pos
		size_t m_nVertexStart;
		// number of vertices used in this operation
		size_t m_nVertexCount;
	
	};
}

#endif // end of _ZH_STAROPERATIONONDATA_H_