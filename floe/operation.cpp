#include "operation.h"

int opAssign(int* argv, int argc) {
	return argv[0];
}
int opAdd(int* argv, int argc) {
	return argv[0] + argv[1];
}
int opSubtract(int* argv, int argc) {
	return argv[0] - argv[1];
}
int opMultiply(int* argv, int argc) {
	return argv[0] * argv[1];
}
int opDivide(int* argv, int argc) {
	return argv[0] / argv[1];
}