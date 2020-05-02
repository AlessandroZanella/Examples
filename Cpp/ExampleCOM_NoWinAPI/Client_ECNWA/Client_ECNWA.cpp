// Client_ECNWA.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include "../Server_ECNWA/interfaces.h"

int main()
{
    ISuperAdder* adder;
    HRESULT res = createCalculator(&adder);

    if (res != S_OK)
    {
        return 0;
    }

    int result;
    adder->Add(90, 20, &result);

    return 0;
}
