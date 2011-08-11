/*
 * DiskBuffHashTable.h
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */

#define HASH_SIZE 16

#ifndef DISKBUFFHASHTABLE_H_
#define DISKBUFFHASHTABLE_H_
#include "DiskBuffFullList.h"
#include <vector>
class DiskBuffHashTable
{
private:
	vector<DiskBuffFullList*>  _hash;
public:
	DiskBuffHashTable();
	~DiskBuffHashTable();
	void Add(DiskBuff* buff);
	void Del(DiskBuff* buff);
	DiskBuff* Get(int fsId,int blockNum);
};


#endif /* DISKBUFFHASHTABLE_H_ */
