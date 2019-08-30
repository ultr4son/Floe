#include "astToOp.h"
#include "mpc-master/mpc.h"
#include "..//Common/operation.h"

/*
* find node containing the tag value between start and end, inclusive
*
*/
mpc_ast_t* findNode(mpc_ast_t* start, mpc_ast_t* end, char* tagContains) {
	for (mpc_ast_t* node = start; node != end; node++) {
		if (strstr(node->tag, tagContains)) {
			return node;
		}
	}
	return NULL;
}

Operation* stoToOperation(mpc_ast_t* ast) {
	char* end = strchr(ast->tag, '|');
	*end = '\0';

	char* opTag = ast->tag;

	Operation* operation = NULL;

	if (strcmp(opTag, OP_OUT) == 0) {
		operation = newOperation(1, ast->contents);
		operation->op = opPrint;

	}
	else if (strcmp(opTag, OP_ASSIGN) == 0) {
		operation = newOperation(1, ast->contents, opAssign);
		operation->op = opAssign;
	}

	return operation;
}

int dependencies(mpc_ast_t* ast) {
	int d = 0;
	for (mpc_ast_t* node = ast->children[0]; node != ast->children[ast->children_num]; node++) {
		if (strncmp(node->tag, "product", strchr(node->tag, '|') - node->tag)) {
			d++;
		}
	}
	return d;

}

ArgType nodeArg(mpc_ast_t* node) {
	if (strstr(node->tag, "intLiteral") == 0) {
		return ARG_CONST_INT;
	}
	if (strstr(node->tag, "node") == 0) {
		return ARG_NODE_REF;
	}
	return -1;
}

Operation* foldOperation(mpc_ast_t* lh, char* op) {
	Operation* fold = newOperation(dependencies(lh), NULL);
	if (lh->children_num == 0) {
		ArgType argType = nodeArg(lh);
		switch (argType) {
		case ARG_CONST_INT:
			addConstant(fold, atoi(lh->contents));
			break;
		case ARG_NODE_REF:
			break;
		}
	}

	return fold;

}

Operation* astToDependencies(mpc_ast_t* ast) {
	Operation* current = newOperation(dependencies(ast), NULL);
	for (
		mpc_ast_t* node = findNode(ast->children[0], ast->children[ast->children_num - 1], "product");
		node != NULL;
		node = findNode(node++, ast->children[ast->children_num - 1], "product")
		) {
		mpc_ast_t* lh = node;

	}
	return current;

}



Operation* astToOperation(mpc_ast_t* ast) {
	//>
	ast = ast->children[0];

	for (
		mpc_ast_t* stoNode = findNode(ast->children[0], ast->children[ast->children_num - 1], "store");
		stoNode != NULL;
		stoNode = findNode(stoNode++, ast->children[ast->children_num - 1], "store")
		) {
		Operation* stoOp = stoToOperation(stoNode->children[0]);
		mpc_ast_t* expression = findNode(stoNode->children[1], stoNode->children[stoNode->children_num], "expression");
		astToDependencies(stoOp, expression);
	}
	return NULL;
}