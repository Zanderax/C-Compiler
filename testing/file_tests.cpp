#include "../src/file.hpp"

TEST( FileTest, OpenFile )
{
	File file( "testing/res/test_file.c" );
	ASSERT_TRUE( file.Open() );
}

TEST( FileTest, FileLength )
{
	File file( "testing/res/test_file.c" );
	ASSERT_TRUE( file.Open() );
	ASSERT_EQ( file.Length(), 46 ); 
}

TEST( FileTest, ReadCharacter )
{
	File file( "testing/res/test_file.c" );
	ASSERT_TRUE( file.Open() );

	auto c = file.Read();
	ASSERT_EQ( c.size(), 46 );
	ASSERT_EQ( 'i', c.at(0) ); 
	ASSERT_EQ( 'n', c.at(1) ); 
	ASSERT_EQ( 't', c.at(2) ); 
}


