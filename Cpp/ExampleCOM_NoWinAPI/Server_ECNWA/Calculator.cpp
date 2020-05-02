#pragma once

#include "interfaces.h"


struct Calculator : ISuperAdder, ISubtractor
{
    ULONG m_count;

    Calculator()
    {
        m_count = 0;
    }

    ULONG __stdcall AddRef(void)
    {
        _InterlockedIncrement(&m_count);

        return m_count;
    }

    ULONG __stdcall Release(void)
    {
        ULONG result = _InterlockedDecrement(&m_count);

        if (result == 0)
        {
            delete this;
        }

        return result;
    }

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID id,
        void** result)
    {
        if (id == __uuidof(IAdder) ||
            id == __uuidof(ISuperAdder))
        {
            *result = static_cast<ISuperAdder*>(this);
        }
        else if (id == __uuidof(ISubtractor))
        {
            *result = static_cast<ISubtractor*>(this);
        }
        else
        {
            *result = 0;
            return E_NOINTERFACE;
        }
        static_cast<IUnknown*>(*result)->AddRef();
        return S_OK;
    }

    void __stdcall Add(int a, int b, int* c)
    {
        *c = a + b;
    }

    void __stdcall Subtract(int a, int b, int* c)
    {
        *c = a - b;
    }

    void __stdcall GetName(const char** name)
    {
        *name = "Calculator";
    }

    void __stdcall SuperAdd(int a, int b, int c, int* d)
    {
        *d = a + b + c;
    }
};

HRESULT __stdcall createCalculator(ISuperAdder** calc)
{
    * calc = new Calculator;

    if (*calc == 0)
    {
        return E_OUTOFMEMORY;
    }
    (*calc)->AddRef();
    return S_OK;
}
