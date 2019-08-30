#include <string.h>
#include "parser.h"
#include "..//Common/operation.h"

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
		" value      : <reserved_in> | <intLiteral> | <node> | '(' <expression> ')' ;    "
		" store      : (<reserved_out> | <node>)\"<-\" ( <expression> )';';"
		" floe       : /^/ <store>+ /$/;",

		Node, ReservedOut, ReservedIn, IntLiteral, Expr, Prod, Value, Store, Floe, NULL);

	mpc_result_t r;

	if (mpc_parse("input", input, Floe, &r)) {

		mpc_cleanup(7, Node, ReservedIn, ReservedOut, IntLiteral, Expr, Prod, Value, Store, Floe);
		return (mpc_ast_t*)r.output;
	}

	mpc_cleanup(7, Node, ReservedIn, ReservedOut, IntLiteral, Expr, Prod, Value, Store, Floe);
	mpc_err_print(r.error);
	mpc_err_delete(r.error);
	return NULL;
}


