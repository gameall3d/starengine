#include "StarVertexDeclaration.h"

namespace Star
{
	CVertexDeclaration::CVertexDeclaration():
	m_nStride(0)
	{

	}

	CVertexDeclaration::~CVertexDeclaration()
	{

	}

	bool CVertexDeclaration::AddElement(CVertexElement element)
	{
		m_ElementList.push_back(element);

		m_nStride += CVertexElement::GetTypeSize(element.GetType());
		return true;
	}
}