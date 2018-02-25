#include <gtest/gtest.h>

#include "log_tests.cpp"
#include "file_tests.cpp"
#include "lexer_tests.cpp"

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
