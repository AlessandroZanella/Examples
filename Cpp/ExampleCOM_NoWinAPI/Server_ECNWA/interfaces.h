#pragma once

#include <Unknwn.h>

struct __declspec(uuid("1cc2ce8e-b2f0-4cbb-bf28-218212916314"))
ISubtractor : IUnknown
{
    virtual void __stdcall Subtract(int a, int b, int* c) = 0;
};

struct __declspec(uuid("8edb856c-e3c5-4cad-ad77-9b5ed7b763c1"))
IAdder : IUnknown
{
    virtual void __stdcall Add(int a, int b, int* c) = 0;
};

struct __declspec(uuid("06686adb-69f9-49af-88cd-30170a17afd1"))
ISuperAdder : IAdder
{
    virtual void __stdcall SuperAdd(int a, int b, int c, int* d) = 0;
};

HRESULT __stdcall createCalculator(ISuperAdder** calc);
