//============================================================================
// Name        : TestDiskCache.cpp
// Author      : Garagatyy Igor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define DISK_CONF_FILE "c:/WinDiskCache/disks/disks.txt"
#define READERS_COUNT 10
#define WRITERS_COUNT 5
#define FS_COUNT 6
#define MAX_BLOCK 10
#include <stdio.h>
#include <stdlib.h>
#include <DiskCache.h>
#include <ctime>
#include <Windows.h>
#include <process.h>
//using namespace System::Threading;
#ifndef _MT 
#define _MT
#endif

DiskCache* cache;
HANDLE* readers;
HANDLE* writers;
HANDLE rand_mutex;
HANDLE console_mutex;

unsigned CALLBACK f_readers(PVOID pvParam)
{
	WaitForSingleObject(rand_mutex,INFINITE);
	srand(time(NULL));
	int dr = rand() % MAX_BLOCK;
	int fr = rand() % FS_COUNT;
	char* ret;
	try
	{
		printf("Try read< fs : %4d block : %5d >\n",fr,dr);
		ret = cache->Read(fr , dr * BLOCK_SIZE, BLOCK_SIZE);
		//printf("read:%p\n", ret);
		cout<<"read"<<*ret<<endl;
	}
	catch(char* exception)
	{
		printf("%s\n", exception);
	}
	ReleaseMutex(rand_mutex);
	return 0;
}

unsigned CALLBACK f_writers(PVOID pvParam)
{
	WaitForSingleObject(rand_mutex,INFINITE);
	srand(time(NULL));
	int dr = rand() % MAX_BLOCK;
	int fr = rand() % FS_COUNT;
	
	//char *a=(char*)malloc(BLOCK_SIZE*sizeof(char));
	char* a = new char[BLOCK_SIZE];
	try
	{
		//cache->Write(fr, dr * BLOCK_SIZE, BLOCK_SIZE,(char*)a);
		//WaitForSingleObject(console_mutex,INFINITE);
		printf("wrote\n");
		//ReleaseMutex(console_mutex);
	}
	catch(char* exception)
	{
		printf("%s/n", exception);
	}
	delete [] a;
	ReleaseMutex(rand_mutex);
	return 0;
}

int main()
{
	cache = new DiskCache((char*)DISK_CONF_FILE);
	readers = new HANDLE[READERS_COUNT];
	writers = new HANDLE[WRITERS_COUNT];
	rand_mutex = CreateMutex(0,false,0);

	WaitForSingleObject(rand_mutex,INFINITE);
	for (int i=0; i<READERS_COUNT; i++)
 	{
		readers[i] = (HANDLE)_beginthreadex(NULL, 0, f_readers, NULL, 0, NULL);
 		//printf(" reader thread created\n");
 	}
	ReleaseMutex(rand_mutex);
/*
	for (int i=0;i<WRITERS_COUNT;i++)
 	{
		//writers[i]=(HANDLE)_beginthreadex(NULL, 0, f_writers, NULL, 0, NULL);
 		//printf("writer thread created\n");
 	}
	*/

 	/*for (int i=0;i<READERS_COUNT;i++)
	{
		void* tr_ret=NULL;
		pthread_join(readers[i],&tr_ret);
	}

	for (int i=0;i<WRITERS_COUNT;i++)
	{
		void* tr_ret=NULL;
		pthread_join(writers[i],&tr_ret);
	}*/


	

	//if(WaitForSingleObject(rand_mutex, (DWORD)0) != WAIT_TIMEOUT )
	//{
	WaitForMultipleObjects(READERS_COUNT, readers, TRUE, INFINITE);
	WaitForMultipleObjects(WRITERS_COUNT, writers, TRUE, INFINITE);

	CloseHandle(rand_mutex);
	//}
	//if(WaitForSingleObject(console_mutex, (DWORD)0) != WAIT_TIMEOUT )
	//{
	//CloseHandle(console_mutex);
	//}
	printf("exit\n");

	delete [] readers;
	delete [] writers;
	std::cin.get();
	return 0;
}
