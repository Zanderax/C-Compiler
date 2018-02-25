#include "logger.hpp"

#include <iostream>
#include <ctime>
#include <fstream>

Logger::Logger( void )
{
	output = Output::STDOUT;
}

Logger::Logger( Output outputIn )
{
	output = outputIn;
	if(outputIn == Output::LOGFILE)
	{
		output = Output::STDOUT;
		log( "Logger cannot be set to file output without a file path. "
			"Defaulting to stdout",
			Severity::Error );
	}
}

Logger::Logger( Output outputIn, std::string outputFileIn )
{
	if( outputIn != Output::LOGFILE )
	{
		log( "Initalizing Logger with a file name but output type is"
			" not set to LOGFILE",
			Severity::Warning );
	}
	output = outputIn;
	outputFile = outputFileIn;

	std::ofstream file;
	file.open( outputFile, std::ofstream::out | std::ofstream::trunc );
	file.close();
}

void Logger::log( const char * msg )
{
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	switch( output )
	{
		case Output::STDOUT:
			std::cout << time << " - " << msg << std::endl;
			break;
		case Output::STDERR:
			std::cerr << time << " - " << msg << std::endl;
			break;
		case Output::LOGFILE:
			std::ofstream file;
			file.open(outputFile, std::ofstream::out | std::ofstream::app);
			file << time << " - " << msg << std::endl;
			file.close();
			break;	
	}
}

void Logger::log( std::string msg )
{
	log( msg.c_str() );
}

void Logger::log( const char * msg, Severity severity )
{
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();
	auto severityString = severityToString.at( severity );
	
	switch( output )
	{
		case Output::STDOUT:
			std::cout << time << " - [" << severityString << "] - " << msg << std::endl;
			break;
		case Output::STDERR:
			std::cerr << time << " - [" << severityString << "] - " << msg << std::endl;
			break;
		case Output::LOGFILE:
			std::ofstream file;
			file.open(outputFile, std::ofstream::out | std::ofstream::app );
			file << time << " - [" << severityString << "] - " << msg << std::endl;
			file.close();
			break;	
	}
}

void Logger::log( std::string msg, Severity severity )
{
	log( msg.c_str(), severity );
}
