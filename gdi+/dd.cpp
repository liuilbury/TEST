#include<Windows.h>

HINSTANCE hIns;
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstace,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {
	//定义窗口类
	WNDCLASSEXA wcx;
	HWND hWnd;
	MSG msg;
	BOOL isGetMsg;
	hIns = hInstace;
	wcx.cbSize = sizeof(wcx);
	wcx.style = CS_HREDRAW | CS_VREDRAW;//窗口大小改变，重画窗口
	wcx.lpfnWndProc = MainWndProc;
	wcx.lpszClassName = "MainWndClass";
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.lpszMenuName = NULL;
	wcx.hInstance = hInstace;
	wcx.hIcon = LoadIconA(NULL, IDI_APPLICATION);
	wcx.hCursor = LoadCursorA((HINSTANCE)NULL, IDC_ARROW);
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//自带的画刷
	wcx.hIconSm = (HICON)LoadImageA(hInstace, MAKEINTRESOURCEA(5), IMAGE_ICON, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
	if (!RegisterClassExA(&wcx)) {
		return 1;
	}
	//创建窗口
	hWnd = CreateWindowA("MainWndClass", "HerGhost", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL,hInstace,NULL);
	if (!hWnd)
		return 1;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while ((isGetMsg = GetMessageA(&msg, NULL, 0, 0)) != 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
//窗口过程函数
LRESULT CALLBACK MainWndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam) {
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}
}