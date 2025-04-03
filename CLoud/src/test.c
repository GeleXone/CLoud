#include <gx/matrix.h>

mat4 matrix = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int test() {
  matrixCreateTransform(10, 20, 30, matrix);
  matrixPrint(matrix);

  return 0;
}

int main() {
	test();

	return 0;
}