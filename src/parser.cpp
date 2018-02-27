#include "parser.hpp"

bool Parser::Parse( Tokens tokens, AST & tree )
{
	//if(tokens[0].type == TokenType::TYPE && tokens[1].type == TokenType::TEXT)
	{
		Node func{NodeType::FUNCTION_DECL, tokens[0].cType, "add", Nodes{} };
		tree.root.children.push_back(func);	
	}
}
