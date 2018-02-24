#ifndef FILE_HPP
#define FILE_HPP

#include <string>

class File
{
public:
	File( std::string filePath );

	bool Open();
	size_t Length();
	bool Read( int posToRead, int charToRead, char * buf );

private:
	std::string _filePath;
	FILE * _fp = nullptr;
};

#endif //FILE_HPP
