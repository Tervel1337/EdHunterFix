#include "INI.h"
#include "Game.h"
#include "Patches.h"

using namespace Patches;
using namespace Game;

const char* INI::Path = ".\\EDHUNTERFIX.INI";

DWORD __stdcall INI::ReadInt(CONST CHAR * lpSubKey, LPCSTR lpValueName, LPBYTE lpData) {
	*(DWORD*)lpData = GetPrivateProfileIntA(lpSubKey, lpValueName, -1, Path);
	return 1;
}

DWORD __stdcall INI::WriteInt(CONST CHAR* lpSubKey, LPCSTR lpValueName, DWORD dwValue) {
	CHAR Value[4];
	snprintf(Value, sizeof(Value), "%d", dwValue);
	WritePrivateProfileStringA(lpSubKey, lpValueName, Value, Path);
	return 1;
}

DWORD __stdcall INI::ReadString(CONST CHAR* lpSubKey, LPCSTR lpValueName, LPSTR lpData, DWORD cbData) {
	GetPrivateProfileStringA(lpSubKey, lpValueName, "", lpData, cbData, Path);
	return 1;
}

DWORD __stdcall INI::WriteString(CONST CHAR* lpSubKey, LPCSTR lpValueName, LPCSTR lpValue) {
	WritePrivateProfileStringA(lpSubKey, lpValueName, lpValue, Path);
	return 1;
}

void INI::Parse() {
	SkipIntros = GetPrivateProfileIntA("QoL", "SkipIntros", -1, Path);
	PauseOnFocusLoss = GetPrivateProfileIntA("QoL", "PauseOnFocusLoss", -1, Path);
	ReadInt("Audio", "RandomPlay", RandomPlay);
	ReadInt("Gameplay", "DifficultyLevel", DifficultyLevel);
	ReadInt("Gameplay", "ControllerType", ControllerType);
	ReadInt("StageTracks", "Stage1", Stage1Track);
	ReadInt("StageTracks", "Stage2", Stage2Track);
	ReadInt("StageTracks", "Stage3", Stage3Track);
	ReadInt("StageTracks", "Stage4", Stage4Track);
	ReadInt("StageTracks", "Stage5", Stage5Track);
	ReadInt("StageTracks", "Stage6", Stage6Track);
	ReadInt("StageTracks", "Stage7", Stage7Track);
}