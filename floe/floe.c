// floe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "mpc-master/mpc.h"


//OperationArg* astToArg(mpc_ast_t* ast) {
//	OperationArg* newArg = (OperationArg*)malloc(sizeof(OperationArg));
//	if (newArg != NULL) {
//		if (strstr(ast->tag, "intLiteral") == 0) {
//			newArg->argType = ARG_CONST_INT;
//			newArg->argValue.constInt = atoi(ast->contents);
//		}
//		else if (strstr(ast->tag, "node") == 0) {
//			newArg->argType = ARG_NODE_REF;
//			newArg->argValue.ref = ast->contents;
//		}
//	}
//	return newArg;
//
//}
//
//void operation(mpc_ast_t* ast, DependencyGraph* node) {
//	OperationTree* op;
//	if (ast->children_num == 0) {
//		op = newOperationTree();		
//		op->op = opAssign;
//		op->arguments.push_back(astToArg(ast));		
//	}
//	else if (ast->children_num > 0) {
//
//		for (int i = 0; i < ast->children_num; i += 2) {
//			
//		}
//	}
//	
//}
//
//void _operation(mpc_ast_t* ast, OperationTree* node) {
//
//}
//
//DependencyGraph* astToGraph(mpc_ast_t* ast) {
//	DependencyGraph* currentGraphNode;
//
//	if (strcmp(ast->tag, ">") != 0) {
//		return NULL;
//	}
//
//	for (int topI = 0; topI < ast->children_num; ++topI) {
//		mpc_ast_t* storeNode = ast->children[topI];
//		if (strstr(storeNode->tag, "store")) {
//			char* nodeName = storeNode->children[0]->contents;
//			currentGraphNode = newNode(nodeName);
//			
//			operation(storeNode->children[2], currentGraphNode);
//		}
//	}
//	return NULL;
//
//}



int main()
{
	mpc_ast_t* ast = parse("c <- 5;out <- in + 4 - b; a <- (2 * 3)+4*(5-6);");
	mpc_ast_print(ast);
	
	//DependencyGraph* graph = astToGraph(ast);
	
	


}

