#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <string>

enum CType
{
	CTYPENONE,
	INT
};

enum TokenType
{
	NONE,
	TEXT,
	PUNCT,
	TYPE,
	KEYWORD,
	LPAREN,
	RPAREN,
	LBRACE,
	RBRACE,
	COMMA,
	SEMICOLON,
	PLUS
};

struct Token
{
	TokenType type;
	CType cType;
	int length;
	std::string spelling;
};

typedef unsigned char uchar;

typedef std::vector<Token> Tokens;

class Lexer
{
public:
	void ReadTokens(std::string c, Tokens & tokens );
};



#endif //LEXER_HPP
