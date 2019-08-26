#include "..//Common/operation.h"
#include "exec.h"

int main() {
	Operation* assign = newOperation(1, "assign");
	assign->op = opAssign;
	addConstant(assign, 5);
	
	Operation* add = newOperation(2, "add");
	add->op = opAdd;
	addDependency(add, assign);
	addConstant(add, 2);

	Operation* print = newOperation(1, "print");
	print->op = opPrint;
	addDependency(print, add);

	exec(print);
	
}
