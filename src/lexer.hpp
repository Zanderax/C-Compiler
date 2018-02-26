#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <string>

enum TokenType
{
	NONE,
	TEXT,
	PUNCT,
	TYPE,
	KEYWORD
};

struct Token
{
	TokenType type;
	int length;
};

typedef unsigned char uchar;

typedef std::vector<Token> Tokens;

class Lexer
{
public:
	void ReadTokens(std::string c, Tokens & tokens );
};



#endif //LEXER_HPP
