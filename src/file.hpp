#ifndef FILE_HPP
#define FILE_HPP

#include <string>

class File
{
public:
	File( std::string filePath );

	bool Open();
};

#endif //FILE_HPP
