//Headers
#include<Windows.h>

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//register above class
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindow(szAppName,
		TEXT("My Application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	TCHAR str[255] = TEXT("I am in WM_CREATE ");

	//code
	switch (iMsg)
	{
	case WM_CREATE:
		MessageBox(hwnd, str, TEXT("Message"), MB_SYSTEMMODAL | MB_OK | MB_TOPMOST | MB_ICONINFORMATION);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("I am in WM_LBUTTONDOWN"), TEXT("Message"), MB_APPLMODAL | MB_OKCANCEL | MB_TOPMOST | MB_ICONEXCLAMATION);
		break;
	case WM_MOVE:
		MessageBox(hwnd, TEXT("I am in WM_MOVE"), TEXT("Message"), MB_TASKMODAL | MB_RETRYCANCEL | MB_ICONHAND );
		break;
	case WM_SIZE:
		MessageBox(hwnd, TEXT("I am in WM_SIZE"), TEXT("Message"), MB_CANCELTRYCONTINUE | MB_ICONASTERISK );
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
			case VK_SPACE:
				MessageBox(hwnd, TEXT("WM_KEYDOWN you pressed SPACEBAR"), TEXT("Message"), MB_CANCELTRYCONTINUE | MB_ICONERROR);
			break;

		}
	break;
	
	case WM_DESTROY:
		PostQuitMessage(0);
	break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
