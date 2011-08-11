/*
 * File.cpp
 *
 *  Created on: Aug 9, 2011
 *      Author: user
 */

#include "File.h"
//#ifdef LINUX

File::File(const char *fileName)
{
	_fileStreamId = open(fileName,O_RDWR|O_SYNC);//func
}

File::~File()
{
	close(_fileStreamId);
}

int File::Lseek(int offset)
{
	return lseek(_fileStreamId,offset,SEEK_SET);
}

int File::Read(BlockData* container, int size)
{
	return read(_fileStreamId,*(container),size);
}

int File::Write(BlockData value,int size)
{
	return write(_fileStreamId,value,size);
}
