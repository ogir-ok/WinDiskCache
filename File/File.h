/*
 * File.h
 *
 *  Created on: Aug 9, 2011
 *      Author: user
 */

#ifndef FILE_H_
#define FILE_H_

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef char*  BlockData;

class File
{
private:
	int _fileStreamId;
public:
	File(const char *fileName);
	~File();
	int Lseek(int pos);
	int Read (BlockData* container, int size);
	int Write(BlockData value, int size);
};

#endif /* FILE_H_ */
