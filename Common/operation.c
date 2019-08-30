#include "operation.h"
#include <stdlib.h>
#include <stdio.h>

#define COMPOSE(op1, op2) 

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
int opPrint(int* argv, int argc) {
	for (int i = 0; i < argc; i++) {
		printf("%d", argv[i]);
	}
	return 0;
}

Op opCompose(Op op1, Op op2) {

}

struct Operation* newOperation(int maxDeps, char* name) {
	struct Operation* operation = (struct Operation*)malloc(sizeof(struct Operation));
	if (operation != NULL) {
		operation->dependencies = calloc(maxDeps, sizeof(DependencyArg));
		operation->depTypes = calloc(maxDeps, sizeof(ArgType));
		operation->depc = 0;
		operation->name = name;
	}
	return operation;
}

void deleteOperation(struct Operation* operation) {
	free(operation->dependencies);
	free(operation->depTypes);
	free(operation);
}


void add(struct Operation* op, enum ArgType type, union DependencyArg arg) {
	op->dependencies[op->depc] = arg;
	op->depTypes[op->depc] = type;
	++op->depc;
}

void addDependency(struct Operation* op, struct Operation* dep) {
	union DependencyArg arg;
	arg.ref = dep;
	add(op, ARG_NODE_REF, arg);
}

void addConstant(struct Operation* op, int constant) {
	union DependencyArg arg;
	arg.constant = constant;
	add(op, ARG_CONST_INT, arg);
}