#include "FrameWork/App.h"

int main()
{
	if (false == App_Init())
	{
		return 1;
	}
	
	return App_Run();
}

/*
	GetAsyncKeyState?
	가상키코드
*/