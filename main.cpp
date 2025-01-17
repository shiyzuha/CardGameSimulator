#include <DxLib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <random>

/* ���C�� */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/* DX���C�u�����̑O���� */
	// �^�C�g���ݒ�
	SetMainWindowText("DIGITAL CARD GAME");

	// �E�B���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);

	// ��ʂ̊g�嗦�ύX������
	SetWindowSizeChangeEnableFlag(TRUE);

	// ��ʂ̉𑜓x�ݒ�
	SetGraphMode(1920, 1080, 32);

	/* DX���C�u�����̏����� */
	if (DxLib_Init() == -1) return -1;

	/* DX���C�u�����̌㏈�� */

	// �`���𗠉�ʂ�
	SetDrawScreen(DX_SCREEN_BACK);


	/* ���C�����[�v */
	while (1)
	{

		/* ������ */

		// ��ʂ̃N���A
		ClearDrawScreen();

		/* �㏈�� */

		// ����ʂ̕`����e��\��ʂɔ��f
		ScreenFlip();

		// Windows �V�X�e�����炭�������������
		if (ProcessMessage() == -1) break;

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
	}

	/* �㏈�� */

	// �I��
	DxLib_End();

	return 0;
}