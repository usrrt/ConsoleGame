//#include "App.h"
//#include "Common.h"
//#include "Renderer.h"
//#include "Timer.h"
//
//bool App_Init()
//{
//	if (false == Renderer_Init())
//	{
//		return false;
//	}
//
//	return true;
//}
//
//void processInput()
//{
//
//}
//
//void update()
//{
//	// ��ʽ�
//	// ������ : �ð�
//	// 1 : deltaTime = fps : 1
//	// 1 = deltaTime * fps
//	// fps = 1 / deltaTime
//	/*char str[128] = "";
//	sprintf_s(str, sizeof(str), "���� FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
//	Renderer_DrawText(str, strlen(str));*/
//
//	//0.5�ʸ��� �����̴� �ؽ�Ʈ��?
//	char str[128] = "";
//	sprintf_s(str, sizeof(str), "���� FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
//	Renderer_DrawText(str, strlen(str));
//}
//
//void render()
//{
//	Renderer_Flip();
//}
//
//void cleanup()
//{
//	Renderer_Cleanup();
//}
//
//int32 App_Run()
//{
//	atexit(cleanup);
//
//	Timer_Init(60);
//
//	// Game Loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
//	while (true)
//	{
//		Timer_Update();
//		processInput();      // �Է� ó��
//		update();         // ���� ������Ʈ
//		render();         // ���� ���
//	}
//
//	return 0;
//}

#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"


bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}

	return true;
}

void processInput()
{

}

//float elapsedTime;
//bool canShow = false;
char str[128];
void update()
{
	/*elapsedTime += DELTA_TIME;

	if (elapsedTime >= 0.5)
	{
		elapsedTime = 0.0f;
		canShow = !canShow;
	}

	if (canShow)
	{
		Renderer_DrawText("�����̴� �ؽ�Ʈ", sizeof("�����̴� �ؽ�Ʈ"));
	}*/

	// ��ʽ�
	// ������ : �ð�
	// 1 : detaTime = fps : 1 
	// 1 = deltaTime * fps
	// fps = 1 / deltaTime
	/*char str[128] = "";
	sprintf_s(str, sizeof(str), "���� FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
	Renderer_DrawText(str, strlen(str));*/

	//Renderer_DrawText("Hello Game", sizeof("Hello Game")); //���̻� ȭ�� �����Ӿ���
	//0.5�ʸ��� �����̴¹��������

	// ����ȭ��ǥ�� ���ȴ��� �ȴ��ȴ��� üũ
	// Ű�� ���� ���� �� 0x0000
	// Ű�� ���� ���� �� 0x8000
	if (0x8000 & GetAsyncKeyState(VK_UP))
	{
		sprintf_s(str, sizeof(str), "up");
	}
	else
	{
		sprintf_s(str, sizeof(str), "no up");
	}
	// �����ٸ� "����ȭ��ǥ ����"
	// ��� �ʾҴٸ� "����ȭ��ǥ ��"
	//short : 2����Ʈ
	//0000 0000 0000 0000 : Ű�� ���� ���� �� 0x0000
	//1000 0000 0000 0000 : Ű�� ���� ���� �� 0x8000
	//1000 0000 0000 0001 : Ű�� ��� ���� ���� �� 0x8001 ��ǻ� �̺κ��� �ʿ����
	
}

void render()
{
	Renderer_DrawText(str, strlen(str));
	Renderer_Flip();

}

void cleanup()
{
	Renderer_Cleanup();
}

int32 App_Run()
{
	atexit(cleanup);

	Timer_Init(60);

	const int32 FIXED_FPS = 50;
	const float FIXED_TIME = 1.0f / FIXED_FPS;
	//���ӷ��� : ���ӵ鵿�۽�Ű�� ����. �������̶��Ѵ� ���ӷ����� �̱��ھ�� ���ư��� �׷��� ������ ����
	while (true)
	{
		// �ð��� ������Ʈ �������� ���ӷ�������
		if (Timer_Update())
		{
			//��ŸŸ�� : �����������κ��� �󸶳� �ð��� �귶��? ���󼼰迡���� �ð�
			processInput();		// �Է�ó��
			update();			// ���Ӿ�����Ʈ
			render();			// ������� 

		}
	}

	return 0;
}

