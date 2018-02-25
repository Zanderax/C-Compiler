#ifndef FILE_HPP
#define FILE_HPP

#include <string>

typedef unsigned char uchar;

class File
{
public:
	File( std::string filePath );

	bool Open();
	size_t Length();
	std::string Read();

private:
	std::string _filePath;
	FILE * _fp = nullptr;
};

#endif //FILE_HPP
