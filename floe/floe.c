// floe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "mpc-master/mpc.h"

mpc_ast_t* parse(const char* input)
{
	mpc_parser_t* Node = mpc_new("node");
	mpc_parser_t* ReservedOut = mpc_new("reserved_out");
	mpc_parser_t* ReservedIn = mpc_new("reserved_in");
	mpc_parser_t* IntLiteral = mpc_new("intLiteral");
	mpc_parser_t* Expr = mpc_new("expression");
	mpc_parser_t* Prod = mpc_new("product");
	mpc_parser_t* Value = mpc_new("value");
	mpc_parser_t* Store = mpc_new("store");
	mpc_parser_t* Floe = mpc_new("floe");


	mpca_lang(MPCA_LANG_DEFAULT,

		" node       : /[A-Za-z]+[0-9]*/;"
		" reserved_out: \"out\";"
		" reserved_in: \"in\";"
		" intLiteral : /[0-9]+/;"
		" expression : <product> (('+' | '-') <product>)*; "
		" product    : <value>   (('*' | '/')   <value>)*; "
		" value      : <intLiteral> | <node> | '(' <expression> ')';    "
		" store      : (<reserved_out> | <node>)\"<-\" (<reserved_in> | <expression> )';';"
		" floe       : /^/ <store>+ /$/;",

		Node, ReservedOut, ReservedIn, IntLiteral, Expr, Prod, Value, Store, Floe, NULL);

	mpc_result_t r;

	if (mpc_parse("input", input, Floe, &r)) {

		mpc_cleanup(7, Node, ReservedIn, ReservedOut, IntLiteral, Expr, Prod, Value, Store, Floe);
		return (mpc_ast_t*) r.output;
	}

	mpc_cleanup(7, Node, ReservedIn, ReservedOut, IntLiteral, Expr, Prod, Value, Store, Floe);
	mpc_err_print(r.error);
	mpc_err_delete(r.error);
	return NULL;
}

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
	mpc_ast_t* ast = parse("out <- in;");
	mpc_ast_print(ast);
	
	//DependencyGraph* graph = astToGraph(ast);
	
	


}

