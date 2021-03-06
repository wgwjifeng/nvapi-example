// NvDigitalVibranceControls.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include <memory>
#include "NvDigitalVibranceControls.h"

#include "../NvController/NvController.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	LPWSTR *szArgList;
	int argCount;

	szArgList = CommandLineToArgvW(GetCommandLine(), &argCount);
	if (szArgList == NULL)
	{
		return 0;
	}

	if (argCount < 3)
	{
		return 0;
	}

	int displayNumber = _ttoi(szArgList[1]);
	int setValue = _ttoi(szArgList[2]);

	std::shared_ptr<NvController> controller;
	controller.reset(new NvController);
	if (controller->Initialize())
	{
		controller->SetDVCLevelEx(displayNumber, setValue > 100 ? 100 : (setValue < 0 ? 0 : setValue));
	}
	controller->UnInitialize();
	LocalFree(szArgList);

	return 0;
}
