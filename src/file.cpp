#include "file.hpp"

#include <cstdio>

#include <stdio.h>  /* defines FILENAME_MAX */
#include <unistd.h>
#include <iostream>
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

bool File::Read( int posToRead, int charToRead, char * buf )
{
	if(!_fp)
	{
		return false;
	}
	size_t pos = ftell( _fp );
	fseek( _fp, posToRead, SEEK_SET );
	fgets( buf, charToRead + 1, _fp ); 
	fseek( _fp, pos, SEEK_SET );
	return true;
}
