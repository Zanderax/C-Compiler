#include "lexer.hpp"

#include "logger.hpp"

bool isLetter( char c )
{
	return ( c >= 65 && c <= 90 ) || ( c >= 97 && c <= 122 );
}

bool isPunct( char c )
{
	return (c == '{' || 
			c == '}' || 
			c == '(' || 
			c == ')' || 
			c == ';' || 
			c == '+' || 
			c == ',' ); 
}

bool isWhiteSpace( char c )
{
	return (c == ' '  || 
			c == '\n' ||  
			c == '\t' ); 
}

void Lexer::Parse( std::string source, Symbols & symbols ) 
{
	Logger logger;
	int len = source.size();
	int symLen = 0;

	for(int pos = 0; pos < len; ++pos)
	{
		char c = source.at(pos);

		if(isLetter(c))
		{
			symLen++;
			continue;
		}
		
		if(symLen != 0)
		{
			Symbol symbol{SymType::TEXT, symLen};
			symbols.push_back(symbol);
			symLen = 0;
		}

		if(isPunct(c))
		{
			Symbol symbol{SymType::PUNCT, 1};
			symbols.push_back(symbol);
			symLen = 0;
		}
	}
}
