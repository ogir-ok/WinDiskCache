// This is the main DLL file.

#include "stdafx.h"

#include "File.h"

File::File(const char *fileName)
{
	//_fileStreamId = open(fileName,O_RDWR|O_SYNC);//func
}

File::~File()
{
	//close(_fileStreamId);
}

int File::Lseek(int offset)
{
//	return lseek(_fileStreamId,offset,SEEK_SET);
	return 0 ;
}

int File::Read(BlockData* container, int size)
{
	//return read(_fileStreamId,*(container),size);
	return 0 ;
}

int File::Write(BlockData value,int size)
{
//	return write(_fileStreamId,value,size);
	return 0 ;
}
