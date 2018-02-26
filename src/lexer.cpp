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

void Lexer::ReadTokens( std::string source, Tokens & tokens ) 
{
	Logger logger;
	int len = source.size();
	int tokLen = 0;

	for(int pos = 0; pos < len; ++pos)
	{
		char c = source.at(pos);

		if(IsLetter(c))
		{
			tokLen++;
			continue;
		}
		
		if(tokLen != 0)
		{
			Token token{TokenType::TEXT, tokLen};
			if(IsType(source.substr( pos - tokLen, tokLen)))
			{
				token.type = TokenType::TYPE;
			}
			tokens.push_back(token);
			tokLen = 0;
		}

		if(IsPunct(c))
		{
			Token token{TokenType::PUNCT, 1};
			tokens.push_back(token);
			tokLen = 0;
		}
	}
}
