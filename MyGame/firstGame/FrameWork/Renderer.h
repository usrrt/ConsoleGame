#pragma once

#include "Type.h"

// ������ �ʱ�ȭ
// �ʱ�ȭ�����ϸ� true, �ƴϸ� false
bool Renderer_Init(void);

//������ ����
void Renderer_Cleanup(void);

// ȭ��ٲٱ�
void Renderer_Flip(void);

//�ؽ�Ʈ�� ����Ѵ� ���ٸ�
void  Renderer_DrawText(const char* text, int32 numberOfChar);