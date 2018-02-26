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

const std::vector<std::string> Types 
{
	"int"
};

const std::vector<std::string> Keywords
{
	"return"
};

bool IsType( std::string text )
{
	for( auto type : Types )
	{
		if(text.compare( type ) == 0)
		{
			return true;
		}
	}
	return false;
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
			Token token{TokenType::TEXT, tokenLen};
			if(IsType(source.substr( pos - tokenLen, tokenLen)))
			{
				token.type = TokenType::TYPE;
			}
			if(IsKeyword(source.substr( pos - tokenLen, tokenLen)))
			{
				token.type = TokenType::KEYWORD;
			}
			tokens.push_back(token);
			tokenLen = 0;
		}

		if(IsPunct(c))
		{
			Token token{TokenType::PUNCT, 1};
			tokens.push_back(token);
			tokenLen = 0;
		}
	}
}
