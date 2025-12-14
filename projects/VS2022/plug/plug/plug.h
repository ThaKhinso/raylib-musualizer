#pragma once
#define N 256
#define NOMINMAX
#define RAYLIB_WITH_EXTERNAL_CALLS
#include "raylib.h"
#include <complex>

//Function names
#define plug_initn "plug_init"
#define plug_updaten "plug_update"

typedef struct Plug {
	float pi;
	float in[N] = { 0 };
	std::complex<float> out[N] = { 0 };
	float max_amp = 0;
	Music music;
};

typedef void (*add_t)(int, int);
typedef void (*plug_hello_t)(void);
typedef void (*plug_init_t)(const char* file_path);
typedef void (*plug_update_t)();