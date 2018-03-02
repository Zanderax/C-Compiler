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

	ASSERT_EQ( tree.root.type, NodeType::ROOT);
	
	ASSERT_EQ( tree.root.children.size(), 1);
	
	Node node = tree.root.children[0];
	 
	ASSERT_EQ( node.type, NodeType::FUNCTION_DECL); 
	ASSERT_EQ( node.cType, CType::INT ); 
	ASSERT_EQ( node.spelling, "add" );
	ASSERT_EQ( node.children.size(), 3 );

	Node a = node.children[0];

	ASSERT_EQ( a.type, NodeType::ARGUMENT); 
	ASSERT_EQ( a.cType, CType::INT ); 
	ASSERT_EQ( a.spelling, "a" );
	ASSERT_EQ( a.children.size(), 0 );

	Node b = node.children[1];

	ASSERT_EQ( b.type, NodeType::ARGUMENT); 
	ASSERT_EQ( b.cType, CType::INT ); 
	ASSERT_EQ( b.spelling, "b" );
	ASSERT_EQ( b.children.size(), 0 );
	
	Node block = node.children[2];

	ASSERT_EQ( block.type, NodeType::BLOCK); 
	ASSERT_EQ( block.cType, CType::CTYPENONE ); 
	ASSERT_EQ( block.spelling, "" );
	ASSERT_EQ( block.children.size(), 1 );

}
