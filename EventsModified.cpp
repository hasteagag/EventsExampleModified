#include "framework.h"
#include "EventsModified.h"
#include <cstring>
#define MAX_LOADSTRING 100
extern int currentProfile;
int currentProfile = 999;
//extern int lastHeldTime;
//int lastHeldTime = 999;
//HWND hWnd = FindWindowA("AutoHotkey", "backupPCREHeading");
std::string sN = "backupPCREHeading";
LPCSTR scriptName = sN.c_str();
int* pointerToCurrentProfile = &currentProfile;
HWND hWnd = FindWindowA("AutoHotkey", scriptName);
//extern bool buckyMode; //bool buckyMode = false;
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
	return currentProfile;
}
void otherCallBack() {
	auto ledId = CLK_Q;
	CorsairLedColor ledColor = { ledId, 0, 0, 0 };
	CorsairGetLedsColors(1, &ledColor);
	currentProfile = profileGetter(ledColor);
}
void presserFunc(CorsairKeyId keyId,bool isUp)
{
	int ud = 0;
	isUp ? (ud = 0) : (ud = 2); // int should be fine here as hex and dec are same	//KEYEVENTF_KEYUP = 0x0002

	int arbitrarySCoffset = 0;
	if (keyId <= 26)
	{
		arbitrarySCoffset = 192 + keyId;
	}
	else if (keyId >= 27 && keyId <= 30)
	{		//this is only so wierd bc some of it was used for other things according to MS Docs
		arbitrarySCoffset = 206 + keyId;
	}
	else {
		std::cout << "error line 143 - keyID was out of bounds";
		return;
	}
	keybd_event(VK_KANA, arbitrarySCoffset, ud, 0);
	return;
}
void sendingAnotherMessage(int msg1, int lastHeld)
{
	//HWND hWnd = FindWindowA("AutoHotkey", "backupPCREHeading"); //where is the input name???
	HWND hWnd = FindWindowA("AutoHotkey", scriptName);
	PostMessageA(hWnd, 0x5556, (WPARAM)pointerToCurrentProfile, 0);
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
		auto ledId = CLK_Q;
		CorsairLedColor ledColor = { ledId, 0, 0, 0 };
		CorsairGetLedsColors(1, &ledColor);
		profileGetter(ledColor);
		presserFunc(e->keyId, e->isPressed);
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
    UNREFERENCED_PARAMETER(lpCmdLine);
	LPCTSTR scriptName = (LPCTSTR)(&lpCmdLine[0]);
	using namespace std::chrono_literals;
	currentProfile = 999;
	CorsairPerformProtocolHandshake();
	while (const auto error = CorsairGetLastError()) {
		CorsairPerformProtocolHandshake();
		std::cout << "Handshake failed: " << toString(error) << "\nWe will be retrying every 10 seconds, until the process is killed or is otherwise successful." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(10));
	}
	HWND hWnd = FindWindowA("AutoHotkey", (LPCSTR)scriptName);
	int* pointerToCurrentProfile = &currentProfile;
//	int* pointerToLHT = &lastHeldTime;
	const auto callback = [](void* context, const CorsairEvent* e) {
		EventPrinter* eventPrinter = static_cast<EventPrinter*>(context);
		eventPrinter->print(e);
	};
	EventPrinter context;
	CorsairSubscribeForEvents(callback, &context);
	// Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EVENTSMODIFIED, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EVENTSMODIFIED));
    MSG msg;
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//const UINT t = 0x5557;
	//const UINT t2 = 0x5559;
	
	/*if (message == t)
	{
		HWND hWnd2 = FindWindowA(NULL, scriptName);
		PostMessageA(hWnd2, 0x5556, (WPARAM)pointerToCurrentProfile, (WPARAM)pointerToLHT);
	}*/
	switch (message)
	{
	////case t:
	
	//	HWND hWnd2 = FindWindowA("AutoHotkey", (LPCSTR)scriptName);
	//	//PostMessageA(hWnd2, 0x5556, (WPARAM)pointerToCurrentProfile, (LPARAM)pointerToLHTG1);
	//	//HWND hWnd = FindWindowA(NULL, scriptName);
	//	//PostMessageA(hWnd, 0x5556, (WPARAM)pointerToCurrentProfile, (LPARAM)lastHeldCountG1);

	//	for (int i = 0x5556; i <= 0x5586; i++)
	//	{
	//		PostMessageA(hWnd, i, (WPARAM)pointerToCurrentProfile, (LPARAM)lhC[i]);
		//	}
	//	//return;
	//}
	//break;
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