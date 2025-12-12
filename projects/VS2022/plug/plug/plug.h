#pragma once
#define N 256
#include <complex>
#include "raylib.h"

typedef struct Plug {
	float in[N] = { 0 };
	std::complex<float> out[N] = { 0 };
	float max_amp = 0;

};

typedef void (*add_t)(int, int);
typedef void (*plug_hello_t)(void);
typedef void (*plug_init_t)(Plug* plug);
typedef void (*plug_frame_t)(Plug* plug);