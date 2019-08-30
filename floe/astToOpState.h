#pragma once
#include "..//Common//operation.h"
#include "mpc-master/mpc.h"

const char* OP_OUT = "reserved_out";
const char* OP_ASSIGN = "node";

struct Dependency {
	char* name;
	Operation* op;
};
struct FoldState {
	struct Dependency** nodes;
	int nodec;
	int allocated;
};

struct FoldState* newState(int allocate);
void freeState(struct FoldState* state);

void addNode(struct FoldState* s, char* name);

Operation* getNode(char* name);

