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
	ASSERT_EQ( file.Length(), 43 ); 
}

TEST( FileTest, ReadCharacter )
{
	File file( "testing/res/test_file.c" );
	ASSERT_TRUE( file.Open() );

	char c[4];
	ASSERT_TRUE( file.Read(0, 3, c) );
	ASSERT_EQ( 'i', c[0] ); 
	ASSERT_EQ( 'n', c[1] ); 
	ASSERT_EQ( 't', c[2] ); 
}
