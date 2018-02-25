#include "parser.hpp"

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

const std::vector<std::string> TypeString 
{
	"int"
};

bool IsType( std::string text )
{
	for( auto type : TypeString )
	{
		if(text.compare( type ) == 0)
		{
			return true;
		}
	}
	return false;
}

void Parser::Parse( std::string source, Symbols & symbols ) 
{
	Logger logger;
	int len = source.size();
	int symLen = 0;

	for(int pos = 0; pos < len; ++pos)
	{
		char c = source.at(pos);

		if(IsLetter(c))
		{
			symLen++;
			continue;
		}
		
		if(symLen != 0)
		{
			Symbol symbol{SymType::TEXT, symLen};
			if(IsType(source.substr( pos - symLen, symLen)))
			{
				symbol.type = SymType::TYPE;
			}
			symbols.push_back(symbol);
			symLen = 0;
		}

		if(IsPunct(c))
		{
			Symbol symbol{SymType::PUNCT, 1};
			symbols.push_back(symbol);
			symLen = 0;
		}
	}
}
