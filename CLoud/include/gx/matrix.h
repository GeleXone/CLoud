#pragma once

typedef double vec4[4];
typedef double mat4[16];

void matrixCreateTransform(double x, double y, double z, mat4 matrix);

void matrixPrint(mat4 matrix);