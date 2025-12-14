#include "plugger.h"
#include <Windows.h>

void* loadlibrary(const char* string) {
	return LoadLibraryA(string);
};

void* findsymbol(void* handle, const char* address_name) {
	return GetProcAddress((HMODULE)handle, address_name);
};