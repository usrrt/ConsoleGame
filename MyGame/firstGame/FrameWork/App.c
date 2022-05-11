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
//	// 비례식
//	// 프레임 : 시간
//	// 1 : deltaTime = fps : 1
//	// 1 = deltaTime * fps
//	// fps = 1 / deltaTime
//	/*char str[128] = "";
//	sprintf_s(str, sizeof(str), "현재 FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
//	Renderer_DrawText(str, strlen(str));*/
//
//	//0.5초마다 깜빡이는 텍스트는?
//	char str[128] = "";
//	sprintf_s(str, sizeof(str), "현재 FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
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
//	// Game Loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
//	while (true)
//	{
//		Timer_Update();
//		processInput();      // 입력 처리
//		update();         // 게임 업데이트
//		render();         // 게임 출력
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
		Renderer_DrawText("깜빡이는 텍스트", sizeof("깜빡이는 텍스트"));
	}*/

	// 비례식
	// 프레임 : 시간
	// 1 : detaTime = fps : 1 
	// 1 = deltaTime * fps
	// fps = 1 / deltaTime
	/*char str[128] = "";
	sprintf_s(str, sizeof(str), "현재 FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
	Renderer_DrawText(str, strlen(str));*/

	//Renderer_DrawText("Hello Game", sizeof("Hello Game")); //더이상 화면 깜빡임없음
	//0.5초마다 깜빡이는문구만들기

	// 위쪽화살표가 눌렸는지 안눌렸는지 체크
	// 키가 떼진 상태 → 0x0000
	// 키가 눌린 상태 → 0x8000
	if (0x8000 & GetAsyncKeyState(VK_UP))
	{
		sprintf_s(str, sizeof(str), "up");
	}
	else
	{
		sprintf_s(str, sizeof(str), "no up");
	}
	// 눌렀다면 "위쪽화살표 눌림"
	// 놀리지 않았다면 "위쪽화살표 뗌"
	//short : 2바이트
	//0000 0000 0000 0000 : 키가 떼진 상태 → 0x0000
	//1000 0000 0000 0000 : 키가 눌린 상태 → 0x8000
	//1000 0000 0000 0001 : 키가 계속 눌린 상태 → 0x8001 사실상 이부분은 필요없음
	
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
	//게임루프 : 게임들동작시키는 루프. 프레임이라한다 게임루프는 싱글코어로 돌아간다 그래서 게임은 인텔
	while (true)
	{
		// 시간이 업데이트 됐을때만 게임루프실행
		if (Timer_Update())
		{
			//델타타임 : 전프레임으로부터 얼마나 시간이 흘렀나? 가상세계에서의 시간
			processInput();		// 입력처리
			update();			// 게임업데이트
			render();			// 게임출력 

		}
	}

	return 0;
}

