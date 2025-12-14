#include "double_plug.h"
#include <stdio.h>
#include "plugger.h"
#include "plug.h"

#define DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name

DECLARE_HANDLE(HINSTANCE);
typedef HINSTANCE HMODULE;

plug_hello_t plug_hello = NULL;
plug_init_t plug_init = NULL;
plug_update_t plug_update = NULL;

const char* libplug = "libplug.dll";
HMODULE handle = (HMODULE)loadlibrary(libplug);

int call(void) {
	if (handle == NULL)
	{
		printf("No library\n");
		return 1;
	}

	plug_hello = (plug_hello_t)findsymbol(handle, "plug_hello");
	if (plug_hello == NULL)
	{
		printf("didn't find the function\n");
		return 1;
	}

	

	plug_update = (plug_update_t)findsymbol(handle, plug_updaten);
	if (plug_update == NULL)
	{
		printf("didn't find the function\n");
		return 1;
	}
	plug_hello();
	return 0;
}

void init(const char* song_name) {
	plug_init = (plug_init_t)findsymbol(handle, plug_initn);
	if (plug_init == NULL)
	{
		printf("didn't find the function\n");
		
	}
	plug_init(song_name);
}