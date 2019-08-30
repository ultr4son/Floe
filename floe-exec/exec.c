#include "exec.h"
#include <stdlib.h>
#include <stdbool.h>

bool constantDependencies(ArgType* depTypes, int depc) {
	bool cons = true;
	for (int i = 0; i < depc; ++i) {
		cons &= depTypes[i] == ARG_CONST_INT;
		if (cons == false) {
			return false;
		}
	}
	return true;
}


int fufill(Operation* node) {
	//Node fufilled with constants
	if (node->depc == 0 || constantDependencies(node->depTypes, node->depc)) {

		//We know that deps is all int constants, so convert it to an int array
		return node->op((int*)node->dependencies, node->depc);

	}
	
	for (int i = 0; i < node->depc; ++i) {
		if (node->depTypes[i] == ARG_NODE_REF) {
			node->dependencies[i].constant = fufill(node->dependencies[i].ref);
		}
	}
	return node->op((int*)node->dependencies, node->depc);
}

void exec(Operation* node) {
	fufill(node);
}

