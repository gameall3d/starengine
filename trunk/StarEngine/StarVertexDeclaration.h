/************************************************************************/
/* Filename: StarVertexDeclaration.h
/* Author: Star
/* Created: [11/11/06]
/* Describe: about the declaration of vertex                                           
/************************************************************************/

#ifndef _ZH_STARVERTEXDECLARATION_H_
#define _ZH_STARVERTEXDECLARATION_H_

#if _MSC_VER > 1000
#pragma once
#endif // end of _MSC_VER

#include "StarPrerequisites.h"
#include "StarVertexElement.h"

namespace Star
{
	class _StarExport CVertexDeclaration
	{
	public:
		typedef std::list<CVertexElement> VertexElementList;

	public:
		CVertexDeclaration();
		~CVertexDeclaration();

		// Get the stride of this Declaration
		size_t GetStride(void) const { return m_nStride; }
		// Get the number of elements in the declaration
		size_t GetElementCount(void) const { return m_ElementList.size(); }
		// Get Read-only access to the element list
		const VertexElementList& GetElementList(void) const { return m_ElementList;}

		// Add Element
		bool AddElement(CVertexElement element);


	protected:
		VertexElementList m_ElementList;

	private:
		size_t m_nStride;
	};
}

#endif // end of _ZH_STARVERTEXDECLARATION_H_