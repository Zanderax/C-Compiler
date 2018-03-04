#include "../src/parser.hpp"
#include "../src/lexer.hpp"

Tokens TestTokensSingle
{
	{TokenType::TYPE, CType::INT, 3, "int"},
	{TokenType::TEXT, CType::CTYPENONE, 3, "add"},
	{TokenType::LPAREN, CType::CTYPENONE, 1, "("},
	{TokenType::TYPE, CType::INT, 3, "int"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "a"},
	{TokenType::COMMA, CType::CTYPENONE, 1, ","},
	{TokenType::TYPE, CType::INT, 3, "int"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "b"},
	{TokenType::RPAREN, CType::CTYPENONE, 1, ")"},
	{TokenType::KEYWORD, CType::CTYPENONE, 1, "return"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "a"},
	{TokenType::PLUS, CType::CTYPENONE, 1, "+"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "b"},
	{TokenType::SEMICOLON, CType::CTYPENONE, 1, ";"},
	{TokenType::LPAREN, CType::CTYPENONE, 1, ")"},
	{TokenType::LBRACE, CType::CTYPENONE, 1, ")"},
	{TokenType::RBRACE, CType::CTYPENONE, 1, ")"},
	
};

Tokens TestTokensDouble
{
	{TokenType::TYPE, CType::INT, 3, "int"},
	{TokenType::TEXT, CType::CTYPENONE, 3, "add"},
	{TokenType::LPAREN, CType::CTYPENONE, 1, "("},
	{TokenType::TYPE, CType::INT, 3, "int"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "a"},
	{TokenType::COMMA, CType::CTYPENONE, 1, ","},
	{TokenType::TYPE, CType::INT, 3, "int"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "b"},
	{TokenType::RPAREN, CType::CTYPENONE, 1, ")"},
	{TokenType::KEYWORD, CType::CTYPENONE, 1, "return"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "a"},
	{TokenType::PLUS, CType::CTYPENONE, 1, "+"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "b"},
	{TokenType::SEMICOLON, CType::CTYPENONE, 1, ";"},
	{TokenType::LPAREN, CType::CTYPENONE, 1, ")"},
	{TokenType::LBRACE, CType::CTYPENONE, 1, "{"},
	{TokenType::RBRACE, CType::CTYPENONE, 1, "}"},
	
	{TokenType::TYPE, CType::INT, 3, "int"},
	{TokenType::TEXT, CType::CTYPENONE, 3, "sub"},
	{TokenType::LPAREN, CType::CTYPENONE, 1, "("},
	{TokenType::TYPE, CType::INT, 3, "int"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "a"},
	{TokenType::COMMA, CType::CTYPENONE, 1, ","},
	{TokenType::TYPE, CType::INT, 3, "int"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "b"},
	{TokenType::RPAREN, CType::CTYPENONE, 1, ")"},
	{TokenType::KEYWORD, CType::CTYPENONE, 1, "return"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "a"},
	{TokenType::MINUS, CType::CTYPENONE, 1, "-"},
	{TokenType::TEXT, CType::CTYPENONE, 1, "b"},
	{TokenType::SEMICOLON, CType::CTYPENONE, 1, ";"},
	{TokenType::LPAREN, CType::CTYPENONE, 1, ")"},
	{TokenType::LBRACE, CType::CTYPENONE, 1, "{"},
	{TokenType::RBRACE, CType::CTYPENONE, 1, "}"},
};

TEST( ParserTest, OneFunction )
{
	Parser parser;
	AST tree;
	ASSERT_TRUE( parser.Parse( TestTokensSingle, tree ) );

	ASSERT_EQ( tree.functions.size(), 1);
	
	Function func = tree.functions[0];
	 
	ASSERT_EQ( func.cType, CType::INT ); 
	ASSERT_EQ( func.spelling, "add" );
	ASSERT_EQ( func.arguments.size(), 2 );

	Argument a = func.arguments[0];

	ASSERT_EQ( a.cType, CType::INT ); 
	ASSERT_EQ( a.spelling, "a" );

	Argument b = func.arguments[1];

	ASSERT_EQ( b.cType, CType::INT ); 
	ASSERT_EQ( b.spelling, "b" );
	
	Block block = func._block;

	ASSERT_EQ( block.statements.size(), 1 );
}

TEST( ParserTest, TwoFunctions )
{
	Parser parser;
	AST tree;
	ASSERT_TRUE( parser.Parse( TestTokensDouble, tree ) );

	ASSERT_EQ( tree.functions.size(), 2 );
}
