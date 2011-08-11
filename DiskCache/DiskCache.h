/*
 * DiskCache.h
 *
 *  Created on: Aug 2, 2011
 *      Author: user
 */


#ifndef DISKCACHE_H_
#define DISKCACHE_H_

#define MAX_BUFF_COUNT 256

#define DllExport   __declspec( dllexport )

#include <FSDriver.h>
#include <Mutex.h>
#include "DiskBuffHashTable.h"
#include "DiskBuffFreeList.h"


class DllExport DiskCache
{
private:
	DiskBuffHashTable* _diskBuffHashTable;
	DiskBuffFreeList* _diskBuffFreeList;
	Mutex* _mutex;
	int _buffCount;
public:
	DiskCache(char* DiskConfigFile);
	~DiskCache();
	void Commit();
	BlockData Read(int fsId, int pos, int len);
	void Write(int fsId, int pos, int len, BlockData value);
};


#endif /* DISKCACHE_H_ */
