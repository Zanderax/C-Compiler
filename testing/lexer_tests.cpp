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
	ASSERT_EQ( tokens.at(2).type, TokenType::LPAREN );
	ASSERT_EQ( tokens.at(3).type, TokenType::TYPE ); 
	ASSERT_EQ( tokens.at(4).type, TokenType::TEXT ); 
	ASSERT_EQ( tokens.at(5).type, TokenType::COMMA );
	ASSERT_EQ( tokens.at(6).type, TokenType::TYPE ); 
	ASSERT_EQ( tokens.at(7).type, TokenType::TEXT ); 
	ASSERT_EQ( tokens.at(8).type, TokenType::RPAREN );
	ASSERT_EQ( tokens.at(9).type, TokenType::LBRACE );
	ASSERT_EQ( tokens.at(10).type, TokenType::KEYWORD );
	ASSERT_EQ( tokens.at(11).type, TokenType::TEXT ); 
	ASSERT_EQ( tokens.at(12).type, TokenType::PLUS ); 
	ASSERT_EQ( tokens.at(13).type, TokenType::TEXT ); 
	ASSERT_EQ( tokens.at(14).type, TokenType::SEMICOLON ); 
	ASSERT_EQ( tokens.at(15).type, TokenType::RBRACE ); 
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

TEST( LexerTests, TokenSpelling )
{
	Logger logger;
	File file( "testing/res/test_file.c" );
	file.Open();
	std::string c = file.Read();

	Lexer lexer;

	Tokens tokens;
	lexer.ReadTokens( c, tokens );
	
	ASSERT_EQ( tokens.at(1).type, TokenType::TEXT); 
	ASSERT_EQ( tokens.at(1).spelling, "add" ); 
}
