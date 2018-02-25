#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <string>

enum SymType
{
	NONE,
	TEXT,
	PUNCT,
	TYPE
};

struct Symbol
{
	SymType type;
	int length;
};

typedef unsigned char uchar;

typedef std::vector<Symbol> Symbols;

class Lexer
{
public:
	void Parse(std::string c, Symbols & symbols );
};



#endif //LEXER_HPP
