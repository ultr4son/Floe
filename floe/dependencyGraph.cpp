#include "dependencyGraph.h"
#include <vector>
DependencyGraph* newNode(char* name) {
	DependencyGraph* dg = (DependencyGraph*)malloc(sizeof(DependencyGraph));
	if (dg != NULL) {
		memset(dg, NULL, sizeof(DependencyGraph));
		dg->node = name;
	}

	return dg;

}


void destroyGraph(DependencyGraph* dg) {
	for (std::vector<DependencyGraph*>::iterator it = dg->dependsOn.begin(); it != dg->dependsOn.end(); ++it) {
		destroyGraph(*it);
	}
	

}