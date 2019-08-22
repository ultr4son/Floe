#pragma once
#include<stdlib.h>
#include<vector>


union OpArg {
	char* ref;
	int constInt;
};
typedef enum ArgType {
	ARG_NODE_REF,
	ARG_CONST_INT
} ArgType;
typedef int (*Operation)(int*, int);
typedef struct OperationTree {
	std::vector<OperationArg*> arguments;
	Operation op;
	OperationTree* then;
} OperationTree;
typedef struct OperationArg {
	OpArg argValue;
	ArgType argType;
} OperationArg;

typedef struct DependencyGraph {
	char* name;
	std::vector<DependencyGraph*> dependsOn;
	OperationTree* operation;
} DependencyGraph;

OperationTree* newOperationTree();
DependencyGraph* newNode(char* name);

void destroyGraph(DependencyGraph* dg);
