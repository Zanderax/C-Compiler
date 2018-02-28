#include "../src/lexer.hpp"
#include "../src/parser.hpp"
#include "../src/file.hpp"

#include <string>

TEST( LexerTests, ReadSourceIntoTokens )
{
	Logger logger;
	File file( "testing/res/test_file.c" );
	file.Open();
	std::string c = file.Read();

	Lexer lexer;

	Tokens tokens;
	lexer.ReadTokens( c, tokens );

	ASSERT_EQ( tokens.size(), 16 ); 
}

TEST( LexerTests, TokensWithType )
{
	Logger logger;
	File file( "testing/res/test_file.c" );
	file.Open();
	std::string c = file.Read();

	Lexer lexer;

	Tokens tokens;
	lexer.ReadTokens( c, tokens );

	ASSERT_EQ( tokens.at(0).type, TokenType::TYPE ); 
	ASSERT_EQ( tokens.at(1).type, TokenType::TEXT ); 
	ASSERT_EQ( tokens.at(2).type, TokenType::PUNCT );
	ASSERT_EQ( tokens.at(3).type, TokenType::TYPE ); 
	ASSERT_EQ( tokens.at(4).type, TokenType::TEXT ); 
	ASSERT_EQ( tokens.at(5).type, TokenType::PUNCT );
	
	ASSERT_EQ( tokens.at(10).type, TokenType::KEYWORD );
}

TEST( LexerTests, TokenCType )
{
	Logger logger;
	File file( "testing/res/test_file.c" );
	file.Open();
	std::string c = file.Read();

	Lexer lexer;

	Tokens tokens;
	lexer.ReadTokens( c, tokens );

	ASSERT_EQ( tokens.at(0).type, TokenType::TYPE ); 
	ASSERT_EQ( tokens.at(0).cType, CType::INT ); 
}
