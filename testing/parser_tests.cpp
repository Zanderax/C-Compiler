#include "../src/parser.hpp"
#include "../src/lexer.hpp"

Tokens TestTokens
{
	{TokenType::TYPE, CType::INT, 3, ""},
	{TokenType::TEXT, CType::CTYPENONE, 3, "add"}
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
}
