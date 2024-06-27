#include <iostream>
#include <windows.h>

int main()
{
    HMODULE hDll = LoadLibraryA("windows.dll");
    if (hDll == NULL)
    {
        std::cerr << "Failed to load DLL.\n";
        return 1;
    }

    typedef void(*InjectedFunction)();
    InjectedFunction injectedFunc = (InjectedFunction)GetProcAddress(hDll, "injectedFunction");
    if (injectedFunc == NULL)
    {
        std::cerr << "Failed to get function address.\n";
        FreeLibrary(hDll);
        return 1;
    }

    injectedFunc();

    FreeLibrary(hDll);

    return 0;
}
