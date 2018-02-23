#ifndef LOG_H
#define LOG_H

#include <string>
#include <map>

enum Severity
{
	Error,
	Info,
	Warning,
	Hack,
	Debug
};

enum Output
{
	STDOUT,
	STDERR,
	LOGFILE
};

class Logger
{
public:

	Logger();
	Logger( Output output );
	Logger( Output output, std::string fileName );

	Output getOutput() { return output; };
	std::string getOutputFile() { return outputFile; };

	void log( const char * msg );
	void log( std::string msg );

	void log( const char * msg, Severity severity );
	void log( std::string msg, Severity severity );

private:
	Output output;
	std::string outputFile;
	const std::map<Severity, std::string> severityToString
	{
		{Error, "Error"},
		{Info, "Info"},
		{Warning, "Warning"},
		{Hack, "Hack"},
		{Debug, "Debug"}
	};
};

#endif
