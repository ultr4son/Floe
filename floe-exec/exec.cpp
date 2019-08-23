#include "exec.h"
#include <stdlib.h>

void exec(Operation* node) {
	fufill(node);
}

int fufill(Operation* node) {
	//Node fufilled with constants
	if (node->deps.size() == 0 || constantDependencies(node->depTypes)) {

		//We know that deps is all int constants, so convert it to an int array
		return node->op((int*)node->deps., node->depc);

	}
	
	for (int i = 0; i < node->depc; ++i) {
		if (node->depTypes[i] == ARG_NODE_REF) {
			node->deps[i].constant = fufill(node->deps[i].ref);
		}
	}
	return node->op((int*)node->deps, node->depc);
}

bool constantDependencies(std::vector<ArgType> depTypes) {
	bool cons = true;
	for (int i = 0; i < depTypes.size(); ++i) {
		cons &= depTypes[i] == ARG_CONST_INT;
		if (cons == false) {
			return false;
		}
	}
	return true;
}
