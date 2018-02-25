#include "../src/lexer.hpp"
#include "../src/file.hpp"

#include <string>

TEST( LexerTest, ParseIntoSymbols )
{
	Logger logger;
	File file( "testing/res/test_file.c" );
	file.Open();
	std::string c = file.Read();

	Lexer lexer;

	Symbols symbols;
	lexer.Parse( c, symbols );

	ASSERT_EQ( symbols.size(), 16 ); 
}

TEST( LexerTest, ParseIntoSymbolsWithType )
{
	Logger logger;
	File file( "testing/res/test_file.c" );
	file.Open();
	std::string c = file.Read();

	Lexer lexer;

	Symbols symbols;
	lexer.Parse( c, symbols );

	ASSERT_EQ( symbols.at(0).type, SymType::TYPE ); 
	ASSERT_EQ( symbols.at(1).type, SymType::TEXT ); 
	ASSERT_EQ( symbols.at(2).type, SymType::PUNCT );
	ASSERT_EQ( symbols.at(3).type, SymType::TYPE ); 
	ASSERT_EQ( symbols.at(4).type, SymType::TEXT ); 
	ASSERT_EQ( symbols.at(5).type, SymType::PUNCT );
}
