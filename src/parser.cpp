#include "parser.hpp"
#include "logger.hpp"

Logger logger;

Tokens _tokens;
index_t tok_i = 0;

Token * GetNextToken()
{
	if(tok_i >= _tokens.size())
	{
		logger.log("Reached EoF Unexpectedly");
		return nullptr;
	}
	return &_tokens[tok_i++];
}

bool NextTokenValid()
{
	return tok_i + 1 < _tokens.size(); 
}


void Function::SetArgs()
{
	Token * token = GetNextToken();
	
	if(token->type == TokenType::RPAREN)
	{
		return;
	}

	while( token )
	{
		Argument arg;

		token = GetNextToken();
		arg.cType = token->cType;

		token = GetNextToken();
		arg.spelling = token->spelling;
	
		arguments.push_back(arg);
		
		token = GetNextToken();

		if(token->type != TokenType::COMMA)
		{
			if(token->type != TokenType::RPAREN)
			{
				logger.log("Expected Comma in arg list");
			}
			return;
		}
	}
}


void Function::SetBlock()
{
	Block block;
	Token * token = GetNextToken();
	if(token->type == TokenType::LBRACE )
	{
		logger.log("Left brace expected");
		return;
	}

	token = GetNextToken();
	while( token )
	{
		if(token->type == TokenType::SEMICOLON)
		{
			Statement statement;
			block.statements.push_back( statement );
		}
		if(token->type == TokenType::RBRACE )
		{
			_block = block;
			return;
		}
		token = GetNextToken();
	}
}

void AST::ParseFunction() 
{
	Function func;
	func.cType = GetNextToken()->cType;
	func.spelling = GetNextToken()->spelling;
	func.SetArgs();
	func.SetBlock();
	functions.push_back( func );
}

bool Parser::Parse( Tokens tokens, AST & tree )
{
	_tokens = tokens;
	tok_i = 0;
	while( NextTokenValid() )
	{
		tree.ParseFunction();
	}
	return true;
}
