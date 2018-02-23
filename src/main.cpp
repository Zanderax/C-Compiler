#include "logger.hpp"

#include <string>


int main( int argc, char ** argv )
{
	Logger logger;

	if(argc != 2)
	{
		logger.log( "Wrong number of args.", Severity::Error );
		return 1;		
	}

	std::string logMsg = "Log!";
	logger.log( logMsg );
	return 0; 
}
