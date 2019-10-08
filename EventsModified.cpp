// EventsModified.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "EventsModified.h"
//#include <string>
#include <cstring>


#define MAX_LOADSTRING 100
typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;
typedef std::chrono::duration<float> fsec;

extern int currentProfile;
int currentProfile = 999;

extern int lastHeldTime;
int lastHeldTime = 999;

std::string sN = "AutoHotkey v1.1.30.03";
LPCSTR scriptName = sN.c_str(); // method is the way..

int* pointerToCurrentProfile = &currentProfile;
int* pointerToLHT = &lastHeldTime;

extern bool buckyMode;
bool buckyMode = false;




const std::unordered_map<CorsairKeyId, std::string> keyIdStrings = {
	{CorsairKey_Invalid, "CorsairKey_Invalid"},
	{CorsairKeyKb_G1, "CorsairKeyKb_G1"},
	{CorsairKeyKb_G2, "CorsairKeyKb_G2"},
	{CorsairKeyKb_G3, "CorsairKeyKb_G3"},
	{CorsairKeyKb_G4, "CorsairKeyKb_G4"},
	{CorsairKeyKb_G5, "CorsairKeyKb_G5"},
	{CorsairKeyKb_G6, "CorsairKeyKb_G6"},
	{CorsairKeyKb_G7, "CorsairKeyKb_G7"},
	{CorsairKeyKb_G8, "CorsairKeyKb_G8"},
	{CorsairKeyKb_G9, "CorsairKeyKb_G9"},
	{CorsairKeyKb_G10, "CorsairKeyKb_G10"},
	{CorsairKeyKb_G11, "CorsairKeyKb_G11"},
	{CorsairKeyKb_G12, "CorsairKeyKb_G12"},
	{CorsairKeyKb_G13, "CorsairKeyKb_G13"},
	{CorsairKeyKb_G14, "CorsairKeyKb_G14"},
	{CorsairKeyKb_G15, "CorsairKeyKb_G15"},
	{CorsairKeyKb_G16, "CorsairKeyKb_G16"},
	{CorsairKeyKb_G17, "CorsairKeyKb_G17"},
	{CorsairKeyKb_G18, "CorsairKeyKb_G18"},

	{CorsairKeyMouse_M1, "CorsairKeyMouse_M1"},
	{CorsairKeyMouse_M2, "CorsairKeyMouse_M2"},
	{CorsairKeyMouse_M3, "CorsairKeyMouse_M3"},
	{CorsairKeyMouse_M4, "CorsairKeyMouse_M4"},
	{CorsairKeyMouse_M5, "CorsairKeyMouse_M5"},
	{CorsairKeyMouse_M6, "CorsairKeyMouse_M6"},
	{CorsairKeyMouse_M7, "CorsairKeyMouse_M7"},
	{CorsairKeyMouse_M8, "CorsairKeyMouse_M8"},
	{CorsairKeyMouse_M9, "CorsairKeyMouse_M9"},
	{CorsairKeyMouse_M10, "CorsairKeyMouse_M10"},
	{CorsairKeyMouse_M11, "CorsairKeyMouse_M11"},
	{CorsairKeyMouse_M12, "CorsairKeyMouse_M12"}
};

const char* toString(CorsairError error)
{
	switch (error) {
	case CE_Success:
		return "CE_Success";
	case CE_ServerNotFound:
		return "CE_ServerNotFound";
	case CE_NoControl:
		return "CE_NoControl";
	case CE_ProtocolHandshakeMissing:
		return "CE_ProtocolHandshakeMissing";
	case CE_IncompatibleProtocol:
		return "CE_IncompatibleProtocol";
	case CE_InvalidArguments:
		return "CE_InvalidArguments";
	default:
		return "unknown error";
	}
}
auto startTimeG1 = Time::now();
auto startTimeG2 = Time::now();
auto startTimeG3 = Time::now();
auto startTimeG4 = Time::now();
auto startTimeG5 = Time::now();
auto startTimeG6 = Time::now();
auto startTimeG7 = Time::now();
auto startTimeG8 = Time::now();
auto startTimeG9 = Time::now();
auto startTimeG10 = Time::now();
auto startTimeG11 = Time::now();
auto startTimeG12 = Time::now();
auto startTimeG13 = Time::now();
auto startTimeG14 = Time::now();
auto startTimeG15 = Time::now();
auto startTimeG16 = Time::now();
auto startTimeG17 = Time::now();
auto startTimeG18 = Time::now();
auto startTimeM1 = Time::now();
auto startTimeM2 = Time::now();
auto startTimeM3 = Time::now();
auto startTimeM4 = Time::now();
auto startTimeM5 = Time::now();
auto startTimeM6 = Time::now();
auto startTimeM7 = Time::now();
auto startTimeM8 = Time::now();
auto startTimeM9 = Time::now();
auto startTimeM10 = Time::now();
auto startTimeM11 = Time::now();
auto startTimeM12 = Time::now();
//
auto endTimeG1 = Time::now();
auto endTimeG2 = Time::now();
auto endTimeG3 = Time::now();
auto endTimeG4 = Time::now();
auto endTimeG5 = Time::now();
auto endTimeG6 = Time::now();
auto endTimeG7 = Time::now();
auto endTimeG8 = Time::now();
auto endTimeG9 = Time::now();
auto endTimeG10 = Time::now();
auto endTimeG11 = Time::now();
auto endTimeG12 = Time::now();
auto endTimeG13 = Time::now();
auto endTimeG14 = Time::now();
auto endTimeG15 = Time::now();
auto endTimeG16 = Time::now();
auto endTimeG17 = Time::now();
auto endTimeG18 = Time::now();
auto endTimeM1 = Time::now();
auto endTimeM2 = Time::now();
auto endTimeM3 = Time::now();
auto endTimeM4 = Time::now();
auto endTimeM5 = Time::now();
auto endTimeM6 = Time::now();
auto endTimeM7 = Time::now();
auto endTimeM8 = Time::now();
auto endTimeM9 = Time::now();
auto endTimeM10 = Time::now();
auto endTimeM11 = Time::now();
auto endTimeM12 = Time::now();
//
auto lastHeldCountG1 = 0;
auto lastHeldCountG2 = 0;
auto lastHeldCountG3 = 0;
auto lastHeldCountG4 = 0;
auto lastHeldCountG5 = 0;
auto lastHeldCountG6 = 0;
auto lastHeldCountG7 = 0;
auto lastHeldCountG8 = 0;
auto lastHeldCountG9 = 0;
auto lastHeldCountG10 = 0;
auto lastHeldCountG11 = 0;
auto lastHeldCountG12 = 0;
auto lastHeldCountG13 = 0;
auto lastHeldCountG14 = 0;
auto lastHeldCountG15 = 0;
auto lastHeldCountG16 = 0;
auto lastHeldCountG17 = 0;
auto lastHeldCountG18 = 0;
auto lastHeldCountM1 = 0;
auto lastHeldCountM2 = 0;
auto lastHeldCountM3 = 0;
auto lastHeldCountM4 = 0;
auto lastHeldCountM5 = 0;
auto lastHeldCountM6 = 0;
auto lastHeldCountM7 = 0;
auto lastHeldCountM8 = 0;
auto lastHeldCountM9 = 0;
auto lastHeldCountM10 = 0;
auto lastHeldCountM11 = 0;
auto lastHeldCountM12 = 0;

auto diff = std::chrono::milliseconds::zero();
//

HWND hWnd = FindWindowA(NULL, "AutoHotkey v1.1.30.03");
int profileGetter(CorsairLedColor ledColor) {
	if (ledColor.r == 20 && ledColor.b == 0)
	{
		currentProfile = 0;
	}
	else if (ledColor.r == 238 && ledColor.b == 255)
	{
		currentProfile = 1;
	}
	else if (ledColor.r == 155 && ledColor.g == 255 && ledColor.b == 0)
	{
		currentProfile = 2;
	}
	else if (ledColor.r == 43)
	{
		currentProfile = 3;
	}
	else if (ledColor.r == 98 && ledColor.g == 255)
	{
		currentProfile = 4;
	}
	else if (ledColor.b == 1)
	{
		currentProfile = 5;
	}
	else if (ledColor.g == 13 && ledColor.b == 60)
	{
		currentProfile = 6;
	}
	else if (ledColor.r == 53 && ledColor.b == 255)
	{
		currentProfile = 7;
	}
	else if (ledColor.r == 255 && ledColor.b == 165)
	{
		currentProfile = 8;
	}
	else if (ledColor.r == 255 && ledColor.g == 170 && ledColor.b == 0)
	{
		currentProfile = 9;
	}
	else if (ledColor.g == 255)
	{
		currentProfile = 10;
	}
	else if (ledColor.g == 254 || (ledColor.r == 5 && ledColor.g == 5 && ledColor.b == 5))
	{ //k63 acts funny here didnt read docs tho
		currentProfile = 11;
	}
	else
	{

	}
	//return for future / old compatibility, we are assigning a global or a wider scope variable above
	return currentProfile;
}
void otherCallBack() {
	auto ledId = CLK_Q;
	CorsairLedColor ledColor = { ledId, 0, 0, 0 };
	CorsairGetLedsColors(1, &ledColor);
	currentProfile = profileGetter(ledColor);
}
void presserFunc(CorsairKeyId keyId)
{
	if (keyId == CLK_ScanNextTrack)
	{
		std::cout << "here";
	}
	else if (keyId == CorsairKeyKb_G1)
	{
		startTimeG1 = Time::now();
		keybd_event(VK_KANA, 0xC1, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G2)
	{
		startTimeG2 = Time::now();
		keybd_event(VK_KANA, 0xC2, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G3)
	{
		startTimeG3 = Time::now();
		keybd_event(VK_KANA, 0xC3, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G4)
	{
		startTimeG4 = Time::now();
		keybd_event(VK_KANA, 0xC4, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G5)
	{
		startTimeG5 = Time::now();
		keybd_event(VK_KANA, 0xC5, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G6)
	{
		startTimeG6 = Time::now();
		keybd_event(VK_KANA, 0xC6, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G7)
	{
		startTimeG7 = Time::now();
		keybd_event(VK_KANA, 0xC7, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G8)
	{
		startTimeG8 = Time::now();
		keybd_event(VK_KANA, 0xC8, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G9)
	{
		startTimeG9 = Time::now();
		keybd_event(VK_KANA, 0xC9, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G10)
	{
		startTimeG10 = Time::now();
		keybd_event(VK_KANA, 0xCA, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G11)
	{
		startTimeG11 = Time::now();
		keybd_event(VK_KANA, 0xCB, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G12)
	{
		startTimeG12 = Time::now();
		keybd_event(VK_KANA, 0xCC, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G13)
	{
		startTimeG13 = Time::now();
		keybd_event(VK_KANA, 0xCD, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G14)
	{
		startTimeG14 = Time::now();
		keybd_event(VK_KANA, 0xCE, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G15)
	{
		startTimeG15 = Time::now();
		keybd_event(VK_KANA, 0xCF, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G16)
	{
		startTimeG16 = Time::now();
		keybd_event(VK_KANA, 0xD0, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G17)
	{
		startTimeG17 = Time::now();
		keybd_event(VK_KANA, 0xD1, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G18)
	{
		startTimeG18 = Time::now();
		keybd_event(VK_KANA, 0xD2, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M1)
	{
		startTimeM1 = Time::now();
		keybd_event(VK_KANA, 0xD3, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M2)
	{
		startTimeM2 = Time::now();
		keybd_event(VK_KANA, 0xD4, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M3)
	{
		startTimeM3 = Time::now();
		keybd_event(VK_KANA, 0xD5, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M4)
	{
		startTimeM4 = Time::now();
		keybd_event(VK_KANA, 0xD6, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M5)
	{
		startTimeM5 = Time::now();
		keybd_event(VK_KANA, 0xD7, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M6)
	{
		startTimeM6 = Time::now();
		keybd_event(VK_KANA, 0xD8, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M7)
	{
		startTimeM7 = Time::now();
		keybd_event(VK_KANA, 0xD9, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M8)
	{
		startTimeM8 = Time::now();
		keybd_event(VK_KANA, 0xDA, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M9)
	{
		startTimeM9 = Time::now();
		keybd_event(VK_KANA, 0xE9, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M10)
	{
		startTimeM10 = Time::now();
		keybd_event(VK_KANA, 0xEA, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M11)
	{
		startTimeM11 = Time::now();
		keybd_event(VK_KANA, 0xEB, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M12)
	{
		startTimeM12 = Time::now();
		keybd_event(VK_KANA, 0xEC, 0, 0);
	}
	else {
		//dont for now
	}
	return;
}

void releaseFunc(CorsairKeyId keyId)
{
	if (keyId == CLK_ScanNextTrack)
	{
		//endTimeG1 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G1)
	{
		endTimeG1 = Time::now();
		std::chrono::duration<double, std::milli> diff = endTimeG1 - startTimeG1;
		lastHeldCountG1 = diff.count();
		//std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xC1, KEYEVENTF_KEYUP, 0);
		startTimeG1 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G2)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG2;
		lastHeldCountG2 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xC2, KEYEVENTF_KEYUP, 0);
		startTimeG2 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G3)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG3;
		lastHeldCountG3 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xC3, KEYEVENTF_KEYUP, 0);
		startTimeG3 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G4)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG4;
		lastHeldCountG4 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xC4, KEYEVENTF_KEYUP, 0);
		startTimeG4 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G5)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG5;
		lastHeldCountG5 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xC5, KEYEVENTF_KEYUP, 0);
		startTimeG5 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G6)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG6;
		lastHeldCountG6 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xC6, KEYEVENTF_KEYUP, 0);
		startTimeG6 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G7)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG7;
		lastHeldCountG7 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xC7, KEYEVENTF_KEYUP, 0);
		startTimeG7 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G8)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG8;
		lastHeldCountG8 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xC8, KEYEVENTF_KEYUP, 0);
		startTimeG8 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G9)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG9;
		lastHeldCountG9 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xC9, KEYEVENTF_KEYUP, 0);
		startTimeG9 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G10)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG10;
		lastHeldCountG10 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xCA, KEYEVENTF_KEYUP, 0);
		startTimeG10 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G11)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG11;
		lastHeldCountG11 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xCB, KEYEVENTF_KEYUP, 0);
		startTimeG11 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G12)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG12;
		lastHeldCountG12 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xCC, KEYEVENTF_KEYUP, 0);
		startTimeG12 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G13)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG13;
		lastHeldCountG13 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xCD, KEYEVENTF_KEYUP, 0);
		startTimeG13 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G14)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG14;
		lastHeldCountG14 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xCE, KEYEVENTF_KEYUP, 0);
		startTimeG14 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G15)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG15;
		lastHeldCountG15 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xCF, KEYEVENTF_KEYUP, 0);
		startTimeG15 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G16)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG16;
		lastHeldCountG16 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xD0, KEYEVENTF_KEYUP, 0);
		startTimeG16 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G17)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG17;
		lastHeldCountG17 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xD1, KEYEVENTF_KEYUP, 0);
		startTimeG17 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G18)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG18;
		lastHeldCountG18 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xD2, KEYEVENTF_KEYUP, 0);
		startTimeG18 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M1)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM1;
		lastHeldCountM1 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xD3, KEYEVENTF_KEYUP, 0);
		startTimeM1 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M2)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM2;
		lastHeldCountM2 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xD4, KEYEVENTF_KEYUP, 0);
		startTimeM2 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M3)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM3;
		lastHeldCountM3 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xD5, KEYEVENTF_KEYUP, 0);
		startTimeM3 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M4)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM4;
		lastHeldCountM4 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xD6, KEYEVENTF_KEYUP, 0);
		startTimeM4 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M5)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM5;
		lastHeldCountM5 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xD7, KEYEVENTF_KEYUP, 0);
		startTimeM5 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M6)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM6;
		lastHeldCountM6 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xD8, KEYEVENTF_KEYUP, 0);
		startTimeM6 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M7)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM7;
		lastHeldCountM7 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xD9, KEYEVENTF_KEYUP, 0);
		startTimeM7 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M8)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM8;
		lastHeldCountM8 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xDA, KEYEVENTF_KEYUP, 0);
		startTimeM8 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M9)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM9;
		lastHeldCountM9 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xE9, KEYEVENTF_KEYUP, 0);
		startTimeM9 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M10)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM10;
		lastHeldCountM10 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xEA, KEYEVENTF_KEYUP, 0);
		startTimeM10 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M11)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM11;
		lastHeldCountM10 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xEB, KEYEVENTF_KEYUP, 0);
		startTimeM11 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M12)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM12;
		lastHeldCountM11 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xEC, KEYEVENTF_KEYUP, 0);
		startTimeM12 = Time::now();
	}
	else {
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG1;
		lastHeldCountM12 = diff.count();
		//std::cout << "Time: " << lastHeldCountG << " ms\n";
		keybd_event(VK_KANA, 0xC1, KEYEVENTF_KEYUP, 0);
	}
	return;
}

void sendingAnotherMessage()
{
	HWND hWnd = FindWindowA(NULL, scriptName);
	PostMessageA(hWnd, 0x5556, (WPARAM)pointerToCurrentProfile, (WPARAM)pointerToLHT);
	return;
}

bool errorCheck(const std::string& msg) {
	auto error = CorsairGetLastError();
	if (error != CorsairError::CE_Success) {
		std::cerr << msg << " (Error: " << toString(error) << ')' << std::endl;
		return true;
	}

	return false;
}

class EventPrinter
{
public:
	void print(const CorsairEvent* e)
	{
		std::cout << "Event #" << std::to_string(++m_eventCounter) << std::endl;
		if (e->id == CEI_DeviceConnectionStatusChangedEvent) {
			printConnectionEvent(e->deviceConnectionStatusChangedEvent);
		}
		else if (e->id == CEI_KeyEvent) {
			handleKeyEvent(e->keyEvent);
			//printKeyEvent(e->keyEvent);
		}
		else {
			std::cout << "Invalid event!" << std::endl;
		}
	}

private:
	void printConnectionEvent(const CorsairDeviceConnectionStatusChangedEvent* e) const
	{
		std::cout << "Device id: " << e->deviceId << "   Status: " << (e->isConnected ? "connected" : "disconnected") << std::endl;
	}

	void printKeyEvent(const CorsairKeyEvent* e) const
	{
		std::cout << " Device id: " << e->deviceId
			<< "    Key id: " << keyIdStrings.at(e->keyId)
			<< " Key state: " << (e->isPressed ? "pressed" : "released") << std::endl;
	}
	void handleKeyEvent(const CorsairKeyEvent* e) const
	{
		//auto ledIdGM = keyIdToLedId.at(keyId);
		//CorsairLedColor ledColorGM = { ledIdGM, 0, 0 };
		//CorsairGetLedsColors(1, &ledColorGM);
		//Context* ctx = static_cast<Context*>(context);
		
		auto ledId = CLK_Q;
		CorsairLedColor ledColor = { ledId, 0, 0, 0 };
		CorsairGetLedsColors(1, &ledColor);
		profileGetter(ledColor);

		//ctx->m_lastPressedKey = keyId;
		///if press = run preser function and pass key id
		//CorsairGetLedsColors(
		
		//if skip where ? ? ? here
		if (!buckyMode) 
		{
			e->isPressed ? presserFunc(e->keyId) : releaseFunc(e->keyId);
		}
	}

private:
	int m_eventCounter = 0;
};

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    //UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


//The hecvk
//MessageBox(NULL, &lpCmdLine[0], L"Arglist contents", MB_OK);

	//scriptName = &lpCmdLine[0];
	LPCTSTR scriptName = (LPCTSTR)(&lpCmdLine[0]);

	//std::cout << lpCmdLine << std::endl;
    // TODO: Place code here.
	
	using namespace std::chrono_literals;
	currentProfile = 999;
	CorsairPerformProtocolHandshake();
	while (const auto error = CorsairGetLastError()) {
		CorsairPerformProtocolHandshake();
		std::cout << "Handshake failed: " << toString(error) << "\nWe will be retrying every 10 seconds, until the process is killed or is otherwise successful." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(10));
	}

	HWND hWnd = FindWindowA(NULL, (LPCSTR)scriptName);

	int* pointerToCurrentProfile = &currentProfile;
	int* pointerToLHT = &lastHeldTime;

	/*std::cout << "We are sending the hWnd:  " << hWnd << std::endl
		<< " to " << scriptName << std::endl
		<< " and we are about to send it the pointer message, which is:  " << pointerToCurrentProfile << std::endl
		<< " and also the LHT pointer:  " << pointerToLHT << std::endl;*/

	PostMessageA(hWnd, 0x5556, (WPARAM)pointerToCurrentProfile, (WPARAM)pointerToLHT);

	
	//CorsairPerformProtocolHandshake();
	//if (errorCheck("Handshake error")) {
	//	//getchar();
	//	//retry? see what i did elsewhere

	//	return -1;
	//}

	const auto callback = [](void* context, const CorsairEvent* e) {
		EventPrinter* eventPrinter = static_cast<EventPrinter*>(context);
		eventPrinter->print(e);
		sendingAnotherMessage();
	};

	//Context could be any class instance or any pointer. Client must ensure context is valid during callback execution
	EventPrinter context;
	CorsairSubscribeForEvents(callback, &context);
	//CorsairUnsubscribeFromEvents();

	// Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EVENTSMODIFIED, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EVENTSMODIFIED));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EVENTSMODIFIED));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EVENTSMODIFIED);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	const UINT t = 0x5557;
	const UINT t2 = 0x5559;
	
	/*if (message == t)
	{
		HWND hWnd2 = FindWindowA(NULL, scriptName);
		PostMessageA(hWnd2, 0x5556, (WPARAM)pointerToCurrentProfile, (WPARAM)pointerToLHT);
	}*/
	switch (message)
	{
	case t:
	{
		HWND hWnd2 = FindWindowA(NULL, (LPCSTR)scriptName);
		PostMessageA(hWnd2, 0x5556, (WPARAM)pointerToCurrentProfile, (WPARAM)pointerToLHT);
	}
	break;
	/*case t2:
		{
			//take an action by not sending the default
			//toggle???? add logic above?  shouldnt slow down since the only time this happens is limited
			buckyMode = !buckyMode; //leave for now shouldnt make a difference ever really
			break;
		}
	break;*/
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		CorsairUnsubscribeFromEvents();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
