#pragma once
#include "stdafx.h"

namespace INI {
	DWORD __stdcall ReadInt(CONST CHAR* lpSubKey, LPCSTR lpValueName, LPBYTE lpData);
	DWORD __stdcall WriteInt(CONST CHAR* lpSubKey, LPCSTR lpValueName, DWORD dwValue);
	DWORD __stdcall ReadString(CONST CHAR* lpSubKey, LPCSTR lpValueName, LPSTR lpData, DWORD cbData);
	DWORD __stdcall WriteString(CONST CHAR* lpSubKey, LPCSTR lpValueName, LPCSTR lpValue);
	extern const char* Path;
	void Parse();
}