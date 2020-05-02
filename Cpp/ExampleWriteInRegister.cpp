
// Simple example of how to create a key with the register key
// It is created a key in HKEY_CURRENT_USER\7_prova
// Inserted property ss with value prova prova
// 
// Warning there is better and newer method to write the register using the 
// transaction


#include "pch.h"
#include <iostream>
#include <windows.h>

int main()
{
    printf("Try to create key in the register\n");
    HKEY key;
    DWORD disp;
    LSTATUS status = RegCreateKeyExA(
        HKEY_CURRENT_USER, 
        "Software\\7_prova", 
        0, 
        NULL, 
        REG_OPTION_NON_VOLATILE, 
        KEY_ALL_ACCESS, 
        NULL, 
        &key, 
        &disp);

    if (status != ERROR_SUCCESS)
    {
        printf("Error RegCreateKeyExA %s\n", status);
    }

    const wchar_t* value = L"Prova prova";

    status = RegSetKeyValueW(
        HKEY_CURRENT_USER,
        L"Software\\7_prova",
        L"ss",
        REG_SZ,
        value,
        wcslen(value) + 1);
    
    if (status != ERROR_SUCCESS)
    {
        printf("Error RegSetKeyValueW %s\n", status);
    }

    RegCloseKey(key);
    return 0;
}
