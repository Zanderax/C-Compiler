#include "../src/parser.hpp"
#include "../src/lexer.hpp"

Tokens TestTokens
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
};

TEST( ParserTest, Parse )
{
	Parser parser;
	AST tree;
	ASSERT_TRUE( parser.Parse( TestTokens, tree ) );

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
	
	Block block = func.block;

	ASSERT_EQ( block.statements.size(), 1 );
}
