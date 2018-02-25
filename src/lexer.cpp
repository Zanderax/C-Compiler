#include "lexer.hpp"

#include "logger.hpp"

bool isLetter( char c )
{
	return ( c >= 65 && c <= 90 ) || ( c >= 97 && c <= 122 );
}

bool isSymbolChar( char c )
{
	return (c == '{' || 
			c == '}' || 
			c == '(' || 
			c == ')' || 
			c == ';' || 
			c == '+' || 
			c == ',' ); 
}

bool isSpace( char c )
{
	return (c == ' '  || 
			c == '\n' ||  
			c == '\t' ); 
}


int readSymbol( std::string str, int len, int & pos )
{
	int symLen = 0;
	Logger logger;
	while(pos < len)
	{
		char c = str.at(pos);
		if(isLetter(c))
		{
			pos++;
			symLen++;
			continue;
		}

		if(isSymbolChar(c))
		{
			if(symLen == 0)
			{
				pos++;
				return 1;
			}
			return symLen;
		}

		if(isSpace(c))
		{
			pos++;
			if(symLen == 0)
			{
				continue;
			}
			return symLen;
		}
		return 0;
	}
	return symLen;
}

void Lexer::Parse( std::string c, Symbols & symbols ) 
{
	int len = c.size();
	int pos = 0;
	Logger logger;
	while( pos < len )
	{
		int symbolLength = readSymbol( c, len, pos );
		if(symbolLength == 0)
		{
			return;
		}
		Symbol symbol;
		symbol.length = symbolLength;
		symbols.push_back(symbol);
	}
}
