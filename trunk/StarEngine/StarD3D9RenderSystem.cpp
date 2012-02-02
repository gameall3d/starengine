#include "StarD3D9RenderSystem.h"
#include "StarD3D9RenderWindow.h"
#include "StarD3D9VertexBuffer.h"
#include "StarD3D9Mappings.h"

namespace Star
{
	CD3D9RenderSystem::CD3D9RenderSystem(HINSTANCE hInst):m_hInstance(hInst),m_pD3D(0),m_pD3DDevice(0)
	{
		if (FAILED(m_pD3D=Direct3DCreate9(D3D_SDK_VERSION)))		
		{
			//log
		}
	}

	CD3D9RenderSystem::~CD3D9RenderSystem()
	{

	}

	CRenderWindow* CD3D9RenderSystem::CreateRenderWindow(std::string title, int nWidth, int nHeight, bool bFullscreen)
	{
		m_pRenderWindow = new CD3D9RenderWindow(m_hInstance, m_pD3D, &m_pD3DDevice);
		m_pRenderWindow->Create(title, nWidth, nHeight, bFullscreen);

		return m_pRenderWindow;
	}

	void CD3D9RenderSystem::CalcPojectectMatrix(float fov, float aspect, float near, float far)
	{
		if (!m_pD3DDevice)
			return;

		D3DXMATRIX projection;

		//D3DXMatrixPerspectiveFovLH(&projection, fov, aspect, near, far);

		m_pD3DDevice->SetTransform(D3DTS_PROJECTION, &projection);
		
	}

	void CD3D9RenderSystem::CalcOrthoMatrix(float fov, float aspect, float near, float far)
	{
		if (!m_pD3DDevice)
			return;

	}

	CVertexBufferPtr CD3D9RenderSystem::CreateVertexBuffer(Star::CVertexDeclaration &declaration, size_t nNumVertices)
	{
		return new CD3D9VertexBuffer(m_pD3DDevice, declaration, nNumVertices);
	}

	void CD3D9RenderSystem::BeginFrame()
	{
		m_pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,255,0), 1, 0);
		HRESULT hr = m_pD3DDevice->BeginScene();

		assert(SUCCEEDED(hr) && "CD3D9RenderSystem::BeginFrame Failed D3D BeginScene");
	}

	void CD3D9RenderSystem::EndFrame()
	{
		HRESULT hr = m_pD3DDevice->EndScene();
		assert(SUCCEEDED(hr) && "CD3D9RenderSystem::BeginFrame Failed D3D EndScene");
	}

	void CD3D9RenderSystem::SwapBuffers()
	{
		m_pD3DDevice->Present(NULL, NULL, NULL, NULL);
	}

	void CD3D9RenderSystem::RenderVertexBuffer(Star::CVertexBufferPtr pVertexBuffer)
	{
		CD3D9VertexBuffer* pD3DVB = dynamic_cast<CD3D9VertexBuffer*>(pVertexBuffer);
		m_pD3DDevice->SetFVF(pD3DVB->GetFVF());
		m_pD3DDevice->SetStreamSource(0, pD3DVB->GetD3DVB(), 0, pD3DVB->GetStride());
		m_pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, pD3DVB->GetNumVertices()/3);
	}

	void CD3D9RenderSystem::RenderOnData(const COperationOnData& op)
	{

		// Set source
		CD3D9VertexBuffer* pD3DVB = dynamic_cast<CD3D9VertexBuffer*>(op.m_pVertexBuffer);
		m_pD3DDevice->SetStreamSource(0,pD3DVB->GetD3DVB(), 0, pD3DVB->GetStride());
		m_pD3DDevice->SetFVF(pD3DVB->GetFVF());


		D3DPRIMITIVETYPE primType = CD3D9Mappings::Get(op.m_eOperationType);
		DWORD numVertices = op.m_pVertexBuffer->GetNumVertices();
		DWORD primCount = 0;

		switch(primType)
		{
		case D3DPT_POINTLIST:
			primCount = numVertices;
			break;
		case D3DPT_LINELIST:
			primCount = numVertices/2;
			break;
		case D3DPT_LINESTRIP:
			primCount = numVertices - 1;
			break;
		case D3DPT_TRIANGLELIST:
			primCount = numVertices/3;
			break;
		case D3DPT_TRIANGLESTRIP:
			primCount = numVertices - 2;
			break;
		case D3DPT_TRIANGLEFAN:
			primCount = numVertices - 2;
			break;
		}

		if (!op.m_bUseIndex)
		{	
			m_pD3DDevice->DrawPrimitive(primType, op.m_nVertexStart, primCount);
		}
		else
		{

		}

	}

	void CD3D9RenderSystem::Render()
	{
// 		BeginFrame();
// 		EndFrame();
// 		SwapBuffers();
	}
}