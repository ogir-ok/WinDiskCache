/*
 * DiskBuffHashTable.h
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */
#pragma once

using namespace System;

#define HASH_SIZE 16

#ifndef DISKBUFFHASHTABLE_H_
#define DISKBUFFHASHTABLE_H_
#include "DiskBuffFullList.h"
#include <vector>
class DiskBuffHashTable
{
private:
	vector<DiskBuffFullList*>  _hash;
	RWLock _lock;
public:
	DiskBuffHashTable();
	~DiskBuffHashTable();
	void Add(DiskBuff* buff);
	void Del(DiskBuff* buff);
	DiskBuff* Get(int fsId,int blockNum);
};


#endif /* DISKBUFFHASHTABLE_H_ */
