#include "Patches.h"
#include "INI.h"
#include "Game.h"
#include <MemoryMgr.h>

using namespace INI;
using namespace Game;
using namespace Memory::VP;

const char* JFSPath = "\\EDHUNTER.JFS";

int Patches::SkipIntros;
int Patches::PauseOnFocusLoss;

void __declspec(naked) WriteAdditional() { // this patch assures the values will be saved to the ini when you quit the game
	static int Continue = 0x4025F0;
	__asm {
		mov edx, 0x4113C0
		call edx
	}

	WriteInt("Audio", "RandomPlay", *RandomPlay);
	WriteInt("Gameplay", "ControllerType", *ControllerType);
	WriteInt("Gameplay", "DifficultyLevel", *DifficultyLevel);
	WriteInt("StageTracks", "Stage1", *Stage1Track);
	WriteInt("StageTracks", "Stage2", *Stage2Track);
	WriteInt("StageTracks", "Stage3", *Stage3Track);
	WriteInt("StageTracks", "Stage4", *Stage4Track);
	WriteInt("StageTracks", "Stage5", *Stage5Track);
	WriteInt("StageTracks", "Stage6", *Stage6Track);
	WriteInt("StageTracks", "Stage7", *Stage7Track);

	__asm {
		jmp Continue
	}
}

void __declspec(naked) SetJFSDir() {
	static int Continue = 0x401E4A;
	__asm {
		lea edx, [esp + 164]
		push edx
		push 260
		call GetCurrentDirectoryA
		lea edi, [esp + 164]
		jmp Continue
	}
}

void __stdcall FocusLossPause(HWND hWnd, UINT Msg, WPARAM wParam, unsigned int lParam) {
	static bool HasBeenPaused;
	if (Msg == WM_KILLFOCUS && !HasBeenPaused && *InGame) {
		*Paused = true;
		HasBeenPaused = true;
	}
	else if (Msg == WM_SETFOCUS && HasBeenPaused) {
		HasBeenPaused = false;
	}
	WNDProc(hWnd, Msg, wParam, lParam);
}

void __declspec(naked) FakeSuccess() {
	__asm {
		mov eax, 1
		retn 4
	}
}

void Patches::Init() {
	if (SkipIntros == 1) {
		Patch<unsigned char>(0x407110, 0xC3); // skip intro videos
	}

	if (PauseOnFocusLoss == 1) {
		Patch(0x00401F56, &FocusLossPause);
	}

	Patch<unsigned char>(0x00401D62, 0xEB); // skip the CD check
	strcpy_s((char*)0x004596DC, strlen(JFSPath) + 1, JFSPath); // replacing the path (adding \ to it)
	InjectHook(0x401E43, &SetJFSDir, HookType::Jump); // since we're skipping the CD check entirely, we must also correct the directory for this JFS (the idea is to never rely on reading the path externally)
	InjectHook(0x4114C0, &ReadInt, HookType::Jump);
	InjectHook(0x4113C0, &WriteInt, HookType::Jump);
	InjectHook(0x411540, &ReadString, HookType::Jump);
	InjectHook(0x411430, &WriteString, HookType::Jump);
	InjectHook(0x4025EB, &WriteAdditional, HookType::Jump);
	InjectHook(0x4112F0, &FakeSuccess, HookType::Jump); // the best workaround i could think of for skipping the registry directory check, which is useless now
}