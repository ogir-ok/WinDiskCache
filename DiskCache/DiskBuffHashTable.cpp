/*
 * DiskBuffHashTable.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */


#include "DiskBuffHashTable.h"

DiskBuffHashTable::DiskBuffHashTable()
{
	DiskBuffFullList *temp;
	for (int i = 0; i< HASH_SIZE;i++)
	{
		temp= new DiskBuffFullList();
		_hash.push_back(temp);
	}
}
DiskBuffHashTable::~DiskBuffHashTable()
{
}
void DiskBuffHashTable:: Add(DiskBuff* buff)
{
	_hash[buff->fsBlockNum%HASH_SIZE]->AddToTail(buff);
}
void DiskBuffHashTable:: Del(DiskBuff* buff)
{
	_hash[buff->fsBlockNum%HASH_SIZE]->Delete(buff);
}

DiskBuff* DiskBuffHashTable::Get(int fsId,int blockNum)
{
	DiskBuff* temp;
	temp = _hash[blockNum%HASH_SIZE]->Get(fsId,blockNum);
	return temp;
}
