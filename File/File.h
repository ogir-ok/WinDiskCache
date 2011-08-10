// File.h

#pragma once

using namespace System;



#include <sys/types.h>
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

