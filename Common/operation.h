#pragma once

int opAssign(int* argv, int argc);
int opAdd(int* argv, int argc);
int opSubtract(int* argv, int argc);
int opMultiply(int* argv, int argc);
int opDivide(int* argv, int argc);
int opPrint(int* argv, int argc);

struct Operation* newOperation(int maxDeps, char* name);
void addDependency(struct Operation* op, struct Operation* dep);
void addConstant(struct Operation* op, int constant);
void deleteOperation(struct Operation* operation);
typedef int (*Op)(int*, int);



typedef enum ArgType {
	ARG_NODE_REF,
	ARG_CONST_INT
} ArgType;
typedef struct Operation {
	Op op;

	/*
		What needs fufilling
	*/
	union DependencyArg* dependencies;
	enum ArgType* depTypes;
	int depc;

	char* name;
} Operation;

typedef union DependencyArg {
	struct Operation* ref;
	int constant;
} DependencyArg;

