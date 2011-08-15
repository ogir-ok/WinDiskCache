/*
 * File.h
 *
 *  Created on: Aug 9, 2011
 *      Author: user
 */

#ifndef FILE_H_
#define FILE_H_

#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <share.h>
#include <Windows.h>
#define DllExport   __declspec( dllexport )

typedef char*  BlockData;

class DllExport File
{
private:
	int _fileStreamId;
	//HANDLE _fileStream;
public:
	File(const char *fileName);
	~File();
	int Lseek(int pos);
	int Read (BlockData* container, int size);
	int Write(BlockData value, int size);
};

#endif /* FILE_H_ */
