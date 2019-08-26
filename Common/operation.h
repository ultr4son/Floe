#pragma once

int opAssign(int* argv, int argc);
int opAdd(int* argv, int argc);
int opSubtract(int* argv, int argc);
int opMultiply(int* argv, int argc);
int opDivide(int* argv, int argc);

typedef int (*Op)(int*, int);

typedef enum ArgType {
	ARG_NODE_REF,
	ARG_CONST_INT
} ArgType;

typedef union DependencyArg {
	struct Operation** ref;
	int constant;
} DependencyArg;

typedef struct Operation {
	Op op;

	/*
		What needs fufilling
	*/
	union DependencyArg* deps;
	ArgType* depTypes;
	int depc;
} Operation;
