#include "StarD3D9VertexBuffer.h"
#include "StarD3D9Mappings.h"

namespace Star
{
	CD3D9VertexBuffer::CD3D9VertexBuffer(LPDIRECT3DDEVICE9 pDev, CVertexDeclaration declaration, size_t numVertices):
	CVertexBuffer(declaration, numVertices),m_dwFVF(0),m_pD3DDev(pDev), m_pD3DVB(NULL)
	{
		// Convert DeclarationList to D3DFVF
		DeclarationToFVF();

		// Create D3D VertexBuffer
		assert(m_pD3DDev&&"D3D Device is NULL");
		HRESULT hr = m_pD3DDev->CreateVertexBuffer(GetTotalSize(), 0,  m_dwFVF, 
					 D3DPOOL_DEFAULT, &m_pD3DVB, NULL);

		assert(SUCCEEDED(hr) && "CD3D9VertexBuffer::CD3D9VertexBuffer - Failed to create d3d vertex buffer.");
		
	}

	CD3D9VertexBuffer::~CD3D9VertexBuffer()
	{

	}

	void* CD3D9VertexBuffer::Lock(size_t offset, size_t length,ELockOption lockOption)
	{
		void* pBuff;
		HRESULT hr = m_pD3DVB->Lock(static_cast<UINT>(offset), static_cast<UINT>(length),
					&pBuff, CD3D9Mappings::Get(lockOption));

		assert(SUCCEEDED(hr) && "CD3D9VertexBuffer::Lock Failed to Lock D3D VB");

		return pBuff;
	}

	void CD3D9VertexBuffer::Unlock()
	{
		m_pD3DVB->Unlock();
	}

	// Convert DeclarationList to D3DFVF
	DWORD CD3D9VertexBuffer::DeclarationToFVF()
	{
		m_dwFVF = 0;
		CVertexDeclaration::VertexElementList elementList = m_Declaration.GetElementList();

		CVertexDeclaration::VertexElementList::iterator itr;
		for (itr = elementList.begin(); itr != elementList.end(); itr++)
		{
			switch(itr->GetUsage())
			{
			case VEU_POSITION:
				m_dwFVF |= D3DFVF_XYZ;
				break;
			case VEU_POSITION_RHW:
				m_dwFVF |= D3DFVF_XYZRHW;
				break;
			case VEU_NORMAL:
				m_dwFVF |= D3DFVF_NORMAL;
				break;
			case VEU_DIFFUSE:
				m_dwFVF |= D3DFVF_DIFFUSE;
				break;
			case VEU_SPECULAR:
				m_dwFVF |= D3DFVF_SPECULAR;
				break;
			case VEU_TEXTURE_COORDINATES:
				m_dwFVF |= D3DFVF_TEX1<<(itr->GetTexNum()-1);
				break;
			default:
				assert(FALSE && 
					"CD3D9VertexBuffer::DeclartionToFVF - \
					D3D9 Pipeline's FVF doesn't support all the elements \
					in this vertex declaration.");
				break;
			}
		}

		return m_dwFVF;
	}

	
}
