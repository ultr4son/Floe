#include "dependencyGraph.h"
#include <vector>
DependencyGraph* newNode(char* name) {
	DependencyGraph* dg = (DependencyGraph*)malloc(sizeof(DependencyGraph));
	memset(dg, NULL, sizeof(DependencyGraph));
	if (dg != NULL) {
		dg->name = name;
	}

	return dg;

}

OperationTree* newOperationTree() {
	OperationTree* op = (OperationTree*)malloc(sizeof(OperationTree));
	op->then = NULL;
	op->op = NULL;
	return op;
}

void destroyGraph(DependencyGraph* dg) {
	for (std::vector<DependencyGraph*>::iterator it = dg->dependsOn.begin(); it != dg->dependsOn.end(); ++it) {
		destroyGraph(*it);
	}
	

}