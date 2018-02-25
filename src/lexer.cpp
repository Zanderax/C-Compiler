#include "lexer.hpp"

#include "logger.hpp"


int readSymbol( std::string c, int len, int & pos )
{
	int symLen = 0;
	Logger logger;
	while(pos < len)
	{
		if( c.at(pos) == '\n' )
		{
			pos++;
			continue;
		}
		if( c.at(pos) == ' ' )
		{
			if(symLen == 0)
			{
				pos++;
				continue;
			}
			return symLen;
		}
		if( 
			c.at(pos) == '{' || 
			c.at(pos) == '}' || 
			c.at(pos) == '(' || 
			c.at(pos) == ')' || 
			c.at(pos) == ';' || 
			c.at(pos) == '+' || 
			c.at(pos) == ',' ) 
		{
			if(symLen == 0)
			{
				pos++;
				return 1;
			}
			return symLen;
		}
		++pos;
		++symLen;
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
