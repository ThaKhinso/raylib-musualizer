#include "double_plug.h"

#include <Windows.h>
#include <stdio.h>
#include "plug.h"


plug_hello_t plug_hello = NULL;

int call(void) {
	const wchar_t* libplug = L"libplug.dll";
	HMODULE handle = LoadLibrary(libplug);
	if (handle == NULL)
	{
		printf("No library\n");
		return 1;
	}

	plug_hello = (plug_hello_t)GetProcAddress(handle, "plug_hello");
	if (plug_hello == NULL)
	{
		printf("didn't find the function\n");
		return 1;
	}
	plug_hello();
	return 0;
}