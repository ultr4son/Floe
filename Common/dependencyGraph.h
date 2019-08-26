#pragma once
#include<stdlib.h>



typedef struct DependencyGraph {
	char* node;
	struct DependencyGraph* dependsOn;
	int dependsOnc;
	struct DependencyGraph* dependents;
	int dependentsc;
} DependencyGraph;

struct DependencyGraph* newNode(char* name);
void destroyGraph(struct DependencyGraph* dg);
