#include "file.hpp"

#include <cstdio>

#include <stdio.h>  /* defines FILENAME_MAX */
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include "logger.hpp"
 
std::string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  getcwd( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}

File::File( std::string filePath )
{
	_filePath = filePath;
}

bool File::Open()
{
	if(_fp)
	{
		return false;
	}

	_fp = fopen( _filePath.c_str(), "r+");

	return _fp;
}

size_t File::Length()
{
	size_t pos = ftell( _fp );
	fseek( _fp, 0, SEEK_END );
	size_t size = ftell( _fp );
	fseek( _fp, pos, SEEK_SET );
	return size; 
}

std::string File::Read()
{

	std::ifstream ifs(_filePath.c_str());
  	auto content = std::string( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	return content;
}
