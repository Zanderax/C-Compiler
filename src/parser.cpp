#include "parser.hpp"
#include "logger.hpp"

Logger logger;

void SetFunctionArgs( Node & node, Tokens tokens, index_t i )
{
	if( tokens[i].type == TokenType::RPAREN)
	{
		return;
	}
	while( i < tokens.size() )
	{
		if(tokens[i].type == TokenType::TYPE &&
			tokens[i+1].type == TokenType::TEXT  )
		{
			Node arg{NodeType::ARGUMENT, tokens[i].cType, tokens[i+1].spelling };
			node.children.push_back(arg);
			if(tokens[i+2].type == TokenType::COMMA)
			{
				i += 3;
				continue;
			}
		}

		return;
	}
}


Node CreateFunctionBlock( Tokens tokens, index_t & i )
{
	Node block{ NodeType::BLOCK };
	for(size_t t = i; t < tokens.size(); ++t)
	{
		if(tokens[t].type == TokenType::SEMICOLON)
		{
			Node statement{ NodeType::STATEMENT };
			block.children.push_back( statement );
			if(tokens[t].type == TokenType::RPAREN )
			{
				return block;
			}
		}
	}
	return block;
}

Node CreateFunctionSymbol( Tokens tokens, index_t & i )
{
	Node func{NodeType::FUNCTION_DECL, tokens[0].cType, tokens[1].spelling, Nodes{} };
	SetFunctionArgs(func, tokens, 3);
	func.children.push_back( CreateFunctionBlock( tokens, i ) );
	return func;
}

bool Parser::Parse( Tokens tokens, AST & tree )
{
	if(tokens[0].type == TokenType::TYPE &&
		tokens[1].type == TokenType::TEXT &&
		tokens[2].type == TokenType::LPAREN )
	{
		index_t i = 0;
		tree.root.children.push_back( CreateFunctionSymbol( tokens, i ) );
	}
}
