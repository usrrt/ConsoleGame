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
	//Renderer_DrawText("Hello Game", sizeof("Hello Game")); //더이상 화면 깜빡임없음
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

	//게임루프 : 게임들동작시키는 루프. 프레임이라한다 게임루프는 싱글코어로 돌아간다 그래서 게임은 인텔
	while (true)
	{
		processInput();		// 입력처리
		update();			// 게임업데이트
		render();			// 게임출력 
	}

	return 0;
}