#include "..\StarEngine\Star.h"
#include "..\StarEngine\StarD3D9RenderSystem.h"
#include "..\StarEngine\StarFrameListener.h"
#include <Windows.h>

using namespace Star;
CStarEngine* pStar = new CStarEngine();

class MyListener : public CFrameListener
{
public:
	MyListener()
	{
		CD3D9RenderSystem* pRs = dynamic_cast<CD3D9RenderSystem*>(CStarEngine::GetSingletonPtr()->GetRenderSystem());

		

		CVertexDeclaration decl;
		decl.AddElement(CVertexElement(0, 0, VET_FLOAT4, VEU_POSITION_RHW));
		decl.AddElement(CVertexElement(0, 0, VET_COLOUR, VEU_DIFFUSE));
		m_pVB = pRs->CreateVertexBuffer(decl, 3);

		float* ptr = static_cast<float*>(m_pVB->Lock(0, m_pVB->GetTotalSize(), CVertexBuffer::VTL_DISCARD));
		*ptr++ = 320;
		*ptr++ = 150;
		*ptr++ = 0.5;
		*ptr++ = 1;
		*((DWORD*)ptr++) = 0xff00ffff;
		*ptr++ = 420;
		*ptr++ = 350;
		*ptr++ = 0.5;
		*ptr++ = 1;
		*((DWORD*)ptr++) = 0xffff00ff;
		*ptr++ = 220;
		*ptr++ = 350;
		*ptr++ = 0.5;
		*ptr++ = 1;
		*((DWORD*)ptr++) = 0xffffff00;

		m_pVB->Unlock();

		op.m_pVertexBuffer = m_pVB;
		op.m_eOperationType = COperationOnData::OT_LINE_LIST;

	}

	~MyListener()
	{
		delete m_pVB;
	}

	bool OnFrameStarted()
	{
		CD3D9RenderSystem* pRs = dynamic_cast<CD3D9RenderSystem*>(CStarEngine::GetSingletonPtr()->GetRenderSystem());

		pRs->BeginFrame();
		//pRs->RenderVertexBuffer(m_pVB);
		pRs->RenderOnData(op);
		pRs->EndFrame();
		pRs->SwapBuffers();

		return true;
	}

	bool OnFrameEnded()
	{
		return true;
	}

private:
	CVertexBufferPtr m_pVB;
	COperationOnData op;
};

//int WINAPI WinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
int main()
{
	//CStarEngine* pStar = new CStarEngine();
	CD3D9RenderSystem* pRs = new CD3D9RenderSystem(GetModuleHandle(NULL));
	pRs->CreateRenderWindow("Draw Primitive", 800, 600, false);
	CStarEngine::GetSingletonPtr()->SetRenderSystem(pRs);
	CStarEngine::GetSingletonPtr()->SetFrameListener(new MyListener());

	CStarEngine::GetSingletonPtr()->StartRendering();


	return 0;
}