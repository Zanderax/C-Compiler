#include "lexer.hpp"

#include "logger.hpp"

bool IsLetter( char c )
{
	return ( c >= 65 && c <= 90 ) || ( c >= 97 && c <= 122 );
}

bool IsPunct( char c )
{
	return (c == '{' || 
			c == '}' || 
			c == '(' || 
			c == ')' || 
			c == ';' || 
			c == '+' || 
			c == ',' ); 
}

const std::map<std::string, CType> Types 
{
	{"int", CType::INT}
};

const std::vector<std::string> Keywords
{
	"return"
};

const std::map<char, TokenType> Punctuations
{
	{ '(', TokenType::LPAREN },
	{ ')', TokenType::RPAREN },
	{ '{', TokenType::LBRACE },
	{ '}', TokenType::RBRACE },
	{ ',', TokenType::COMMA },
	{ ';', TokenType::SEMICOLON },
	{ '+', TokenType::PLUS }
}; 

bool IsType( std::string text )
{
	if(Types.find( text ) == Types.end())
	{
		return false;
	}
	return true;
}

bool IsKeyword( std::string text )
{
	for( auto keyword : Keywords )
	{
		if(text.compare( keyword ) == 0)
		{
			return true;
		}
	}
	return false;
}

void Lexer::ReadTokens( std::string source, Tokens & tokens ) 
{
	Logger logger;
	int len = source.size();
	int tokenLen = 0;

	for(int pos = 0; pos < len; ++pos)
	{
		char c = source.at(pos);

		if(IsLetter(c))
		{
			tokenLen++;
			continue;
		}
		
		if(tokenLen != 0)
		{
			std::string tokenStr = source.substr( pos - tokenLen, tokenLen);
			Token token{TokenType::TEXT, CType::CTYPENONE, tokenLen, tokenStr};
			if(IsType(tokenStr))
			{
				token.type = TokenType::TYPE;
				token.cType = Types.find(tokenStr)->second;
			}
			if(IsKeyword(tokenStr))
			{
				token.type = TokenType::KEYWORD;
			}
			tokens.push_back(token);
			tokenLen = 0;
		}

		if(IsPunct(c))
		{
			Token token{Punctuations.find(c)->second, CType::CTYPENONE, 1, std::string{c}};
			tokens.push_back(token);
			tokenLen = 0;
		}
	}
}
