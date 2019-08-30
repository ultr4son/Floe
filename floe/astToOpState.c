#include "astToOpState.h"
#include <stdlib.h>
struct FoldState* newState(int allocate) {
	struct FoldState* s = (struct FoldState*) malloc(sizeof(struct FoldState));
	if (s != NULL) {
		s->nodes = (struct Dependency**) calloc(allocate, sizeof(struct Dependency*));
		s->allocated = allocate;
		s->nodec = 0;
	}
	return s;
}

void freeState(struct FoldState* s) {
	for (int i = 0; i < s->nodec; i++) {
		free(s->nodes[i]);
	}
	free(s);
}

void resizeArray(struct Dependency** deps, int oldSize) {

}

void addNode(struct FoldState* s, char* name) {
	struct Dependency* dep = (struct Dependency*)malloc(sizeof(struct Dependency));
	if (dep != NULL) {
		dep->name = name;
	}
	

}
