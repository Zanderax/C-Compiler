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
