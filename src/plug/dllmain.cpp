// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdio.h>
#include "double_plug.h"
#define MY_DLL extern "C" __declspec(dllexport)

// mylib.cpp

//extern "C" __declspec(dllexport)
MY_DLL int add(int a, int b) {
    return a + b;
}

MY_DLL//extern "C" __declspec(dllexport)
void plug_hello(void) {
    printf("Hello from dll\n");
}

MY_DLL void plug_init(void* state, const char* file_path) {
    m_plug_init(state, file_path);
}

MY_DLL void plug_update(void* state) {
    m_plug_update(state);
}

MY_DLL void plug_pre_reload(void* state) {
    m_pre_reload(state);
}

MY_DLL void plug_post_reload(void* state) {
    m_post_reload(state);
}