#include "..//floe/operation.h"
#include "..//floe/dependencyGraph.h"
#include "exec.h"

int main() {
	Operation a;
	DependencyArg aArg;
	aArg.constant = 2;
	a.op = opAssign;
	a.deps.push_back(aArg);
	a.depTypes.push_back(ARG_CONST_INT);

	Operation b;
	DependencyArg bArg0;
	DependencyArg bArg1;
	bArg0.constant = 2;
	bArg1.ref = &a;
	b.op = opAdd;
	b.deps.push_back(bArg0);
	b.depTypes.push_back(ARG_CONST_INT);
	b.deps.push_back(bArg1);
	b.depTypes.push_back(ARG_NODE_REF);

	exec(&b);

}
