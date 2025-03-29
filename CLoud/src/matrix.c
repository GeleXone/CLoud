#include <gx/matrix.h>
#include <stdio.h>

void matrixCreateTransform(double x, double y, double z, mat4 matrix) {
	matrix = (mat4){1, 0, 0, x,
					0, 1, 0, y,
					0, 0, 1, z,
					0, 0, 0, 1};
}

void matrixPrint(mat4 matrix) {
	for (int i = 0; i < 16; i++) {
		if (i % 4 == 0) printf("\n");
		printf("");
	}
}