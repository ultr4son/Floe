#pragma once
#include<stdlib.h>
#include<vector>


typedef enum ArgType {
	ARG_NODE_REF,
	ARG_CONST_INT
} ArgType;
typedef int (*Op)(int*, int);


typedef struct Dependency {
	ArgType fufill;
	DependencyArg arg;
} Dependency;

typedef struct Operation {
	Op op;

	/*
		What needs fufilling
	*/
	std::vector<DependencyArg> deps;
	std::vector<ArgType> depTypes;
} Operation;
union DependencyArg {
	Operation* ref;
	int constant;
};


typedef struct NodeOperation {
	Operation op;
	NodeOperation** dependencies;
	int depc;
} NodeOperation;
typedef struct DependencyGraph {
	char* node;
	std::vector<DependencyGraph*> dependsOn;
	std::vector<DependencyGraph*> dependents;
} DependencyGraph;

DependencyGraph* newNode(char* name);
void destroyGraph(DependencyGraph* dg);
