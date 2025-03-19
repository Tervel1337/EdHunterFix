#include "Game.h"

void WNDProc(HWND hWnd, UINT Msg, WPARAM wParam, unsigned int lParam) {
	((void(__stdcall*)(HWND, UINT, WPARAM, unsigned int))0x406010)(hWnd, Msg, wParam, lParam);
}

bool* Game::InGame = (bool*)0x461AA4;
bool* Game::Paused = (bool*)0x462AA4;

LPBYTE Game::RandomPlay = (LPBYTE)0x468630;
LPBYTE Game::ControllerType = (LPBYTE)0x468634;
LPBYTE Game::DifficultyLevel = (LPBYTE)0x468638;
LPBYTE Game::Stage1Track = (LPBYTE)0x45A3FC;
LPBYTE Game::Stage2Track = (LPBYTE)0x45A400;
LPBYTE Game::Stage3Track = (LPBYTE)0x45A404;
LPBYTE Game::Stage4Track = (LPBYTE)0x45A408;
LPBYTE Game::Stage5Track = (LPBYTE)0x45A40C;
LPBYTE Game::Stage6Track = (LPBYTE)0x45A410;
LPBYTE Game::Stage7Track = (LPBYTE)0x45A414;