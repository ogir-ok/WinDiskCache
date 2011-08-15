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
	//	_sopen_s(&_fileStreamId, fileName, NULL, NULL, NULL);
	//printf("TRY OPEN FILE < fileName: %s > \n", (LPCWSTR)fileName);
	//	_fileStream =  CreateFile((LPCWSTR)fileName, GENERIC_ALL, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
	//	printf("CreateFile < fileName: %s handle: %d >\n", fileName, _fileStream);
	//printf("TRY OPEN FILE < fileName: %s > \n", fileName);
	_fileStreamId = _open(fileName,O_RDWR);
//	printf("CreateFile < fileName: %s handle: %d >\n", fileName, _fileStreamId);
}

File::~File()
{
	//	printf("Destructor File");
	//CloseHandle(_fileStream);
	_close(_fileStreamId);
}

int File::Lseek(int offset)
{
	//printf("Lseek < offset: %4d >\n", offset);
	//	return (int) SetFilePointer(_fileStream, offset, NULL, FILE_BEGIN);
	return _lseek(_fileStreamId,offset,SEEK_SET);
}

int File::Read(BlockData* container, int size)
{
	//printf("Read < container: %4d size: %4d>\n", container, size);
	return _read(_fileStreamId,*(container),size);
	//DWORD ret;
	//	ReadFile(_fileStream, container, size, &ret, NULL);
	//	return (int) ret;
}

int File::Write(BlockData value,int size)
{
	//printf("Write < value: %4d size: %4d >\n", value, size);
	//DWORD ret;
	//WriteFile(_fileStream,value,size,&ret,NULL);
	return _write(_fileStreamId, value, size);
	//return ret;
}
