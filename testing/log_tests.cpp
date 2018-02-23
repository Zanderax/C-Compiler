#include "../src/logger.hpp"

#include <string>
#include <fstream>

void checkSimpleLogOutput( std::string msg )
{
	std::string actual = testing::internal::GetCapturedStdout();
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	std::string expected = time + " - " + msg + "\n";

	ASSERT_EQ( expected, actual );
}

TEST( LogTest, LogString )  
{
	//Setup
	testing::internal::CaptureStdout();
	Logger logger;
	std::string msg = "LogMsg";

	//Run Test
	logger.log( msg );

	//Assert
	checkSimpleLogOutput( msg );
}

TEST( LogTest, LogChar )  
{
	//Setup
	testing::internal::CaptureStdout();
	Logger logger;
	std::string msg = "LogMsg";

	//Run Test
	logger.log( msg.c_str() );

	//Assert
	checkSimpleLogOutput( msg );	
}

void runLogSeverityTest( Severity severity, std::string severityString )
{

	//Setup
	testing::internal::CaptureStdout();
	Logger logger;
	std::string msg = "LogMsg";

	//Run Test
	logger.log( msg.c_str(), severity );

	//Assert
	std::string actual = testing::internal::GetCapturedStdout();
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	std::string expected = time + " - [" + severityString + "] - " + msg + "\n";

	ASSERT_EQ( expected, actual );
}

TEST( LogTest, LogSeverityError )
{
	runLogSeverityTest( Severity::Error, "Error" );
}

TEST( LogTest, LogSeverityWarning )
{
	runLogSeverityTest( Severity::Warning, "Warning" );
}

TEST( LogTest, LogSeverityInfo )
{
	runLogSeverityTest( Severity::Info, "Info" );
}

TEST( LogTest, LogSeverityHack )
{
	runLogSeverityTest( Severity::Hack, "Hack" );
}

TEST( LogTest, LogSeverityDebug )
{
	runLogSeverityTest( Severity::Debug, "Debug" );
}

TEST( LogTest, LoggerDefaultToSTDOUT )
{
	//Setup
	Logger logger;

	//Assert
	ASSERT_EQ( logger.getOutput(), Output::STDOUT );
}

TEST( LogTest, LoggerInitalizedToSTDERR )
{
	//Setup
	Logger logger(Output::STDERR);

	//Assert
	ASSERT_EQ( logger.getOutput(), Output::STDERR );
}


TEST( LogTest, LogToSTDERR )
{
	//Setup
	testing::internal::CaptureStderr();

	Logger logger(Output::STDERR);

	//Assert

	auto msg = "Info log to STDERR"; 

	logger.log(msg, Severity::Info);
	
	std::string actual = testing::internal::GetCapturedStderr();
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	std::string expected = time + " - [Info] - " + msg + "\n";
	
	//Assert
	ASSERT_EQ( logger.getOutput(), Output::STDERR );
	
	ASSERT_EQ( expected, actual );
}


TEST( LogTest, LoggerInitalizedToFileWithoutFileName )
{
	//Setup
	testing::internal::CaptureStdout();
	Logger logger(Output::LOGFILE);

	std::string actual = testing::internal::GetCapturedStdout();
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	auto msg = "Logger cannot be set to file output without a file path. "
			"Defaulting to stdout";

	std::string expected = time + " - [Error] - " + msg + "\n";

	//Assert
	ASSERT_EQ( logger.getOutput(), Output::STDOUT );
	ASSERT_EQ( expected, actual );
}

TEST( LogTest, LoggerInitalizedToFile )
{
	//Setup
	auto fileName = "file.log";
	Logger logger(Output::LOGFILE, fileName );

	//Assert
	ASSERT_EQ( logger.getOutput(), Output::LOGFILE );
	ASSERT_EQ( logger.getOutputFile(), fileName );
}

TEST( LogTest, LogToFile )
{
	//Setup
	auto fileName = "file.log";
	Logger logger(Output::LOGFILE, fileName );

	//Assert

	auto msg = "Info log to file.log"; 

	logger.log(msg, Severity::Info);
	
	std::ifstream file;
	file.open(fileName);

	std::string actual;
	std::getline(file, actual);
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	std::string expected = time + " - [Info] - " + msg;
	
	//Assert
	ASSERT_EQ( logger.getOutput(), Output::LOGFILE );
	ASSERT_EQ( logger.getOutputFile(), fileName );
	ASSERT_EQ( expected, actual );
}
