#pragma once
#include "stdafx.h"

void WNDProc(HWND hWnd, UINT Msg, WPARAM wParam, unsigned int lParam);

namespace Game {
	extern bool* InGame;
	extern bool* Paused;

	extern LPBYTE RandomPlay;
	extern LPBYTE ControllerType;
	extern LPBYTE DifficultyLevel;
	extern LPBYTE Stage1Track;
	extern LPBYTE Stage2Track;
	extern LPBYTE Stage3Track;
	extern LPBYTE Stage4Track;
	extern LPBYTE Stage5Track;
	extern LPBYTE Stage6Track;
	extern LPBYTE Stage7Track;
}