#include "parser.hpp"
#include "logger.hpp"

Logger logger;

void SetFunctionArgs( Function & func, Tokens tokens, index_t i )
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
			Argument arg;
			arg.cType = tokens[i].cType;
			arg.spelling = tokens[i+1].spelling;
			func.arguments.push_back(arg);
			if(tokens[i+2].type == TokenType::COMMA)
			{
				i += 3;
				continue;
			}
		}

		return;
	}
}


Block CreateFunctionBlock( Tokens tokens, index_t & i )
{
	Block block;
	for(size_t t = i; t < tokens.size(); ++t)
	{
		if(tokens[t].type == TokenType::SEMICOLON)
		{
			Statement statement;
			block.statements.push_back( statement );
			if(tokens[t].type == TokenType::RPAREN )
			{
				return block;
			}
		}
	}
	return block;
}

Function CreateFunctionSymbol( Tokens tokens, index_t & i )
{
	Function func;
	func.cType = tokens[0].cType;
	func.spelling = tokens[1].spelling;
	SetFunctionArgs(func, tokens, 3);
	func.block = CreateFunctionBlock( tokens, i );
	return func;
}

bool Parser::Parse( Tokens tokens, AST & tree )
{
	if(tokens[0].type == TokenType::TYPE &&
		tokens[1].type == TokenType::TEXT &&
		tokens[2].type == TokenType::LPAREN )
	{
		index_t i = 0;
		tree.functions.push_back( CreateFunctionSymbol( tokens, i ) );
	}
}
