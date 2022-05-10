#include "App.h"
#include "Common.h"
#include "Renderer.h"

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}
}

void processInput()
{

}

void update()
{
	//Renderer_DrawText("Hello Game", sizeof("Hello Game")); //���̻� ȭ�� �����Ӿ���
}

void render()
{
	Renderer_Flip();

}

void cleanup()
{
	Renderer_Cleanup();
}

int32 App_Run()
{
	atexit(cleanup);

	//���ӷ��� : ���ӵ鵿�۽�Ű�� ����. �������̶��Ѵ� ���ӷ����� �̱��ھ�� ���ư��� �׷��� ������ ����
	while (true)
	{
		processInput();		// �Է�ó��
		update();			// ���Ӿ�����Ʈ
		render();			// ������� 
	}

	return 0;
}