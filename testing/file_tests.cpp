#include "../src/file.hpp"

TEST( FileTest, OpenFile )
{
	File file( "testing/res/test_file.txt" );
	ASSERT_TRUE( file.Open() );
}
