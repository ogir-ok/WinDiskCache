/*
 * FSArea.cpp
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */
//#include <cstdio>

#include "FSArea.h"
//#include <sys/types.h>
//#include <unistd.h>



FSArea::FSArea(const char* fileName)
{
	_file = new File(fileName);
}

FSArea::~FSArea()
{
	delete _file;
}

int FSArea::GetBlock(int blockNum, BlockData* container)
{	int error = 0;
	error = _file->Lseek(blockNum* BLOCK_SIZE);
	if (-1 != error)
		error = _file->Read(container, BLOCK_SIZE);
	return error;
}

int FSArea::SetBlock(int blockNum, BlockData value)
{
	int error = 0;
	error = _file->Lseek(blockNum* BLOCK_SIZE);
	if (-1 != error)
		error = _file->Write(value, BLOCK_SIZE);
	return error;
}

FSArea::FSArea()
{
	_file = new File(NULL);
}
