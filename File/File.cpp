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
	_fileStreamId = _open(fileName,O_RDWR);//func
}

File::~File()
{
	_close(_fileStreamId);
}

int File::Lseek(int offset)
{
	return _lseek(_fileStreamId,offset,SEEK_SET);
}

int File::Read(BlockData* container, int size)
{
	return _read(_fileStreamId,*(container),size);
}

int File::Write(BlockData value,int size)
{
	return _write(_fileStreamId,value,size);
}
