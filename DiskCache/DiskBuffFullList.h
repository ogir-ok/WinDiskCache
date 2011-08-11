/*
 * DiskBuffFullList.h
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */
#pragma once

using namespace System;

#ifndef DISKBUFFFULLLIST_H_
#define DISKBUFFFULLLIST_H_

#include <stdlib.h>

#include <FSDriver.h>
#include <Mutex.h>
#include <RWLock.h>

#include "DiskBuff.h"


class DiskBuffFullList
{
private:
	DiskBuff* _pHead;
	DiskBuff* _pTail;
	int _countElem;
public:
	DiskBuffFullList();
	~DiskBuffFullList();
	void AddToTail(DiskBuff* addBuff);
	void Delete(DiskBuff * el);
	DiskBuff* Get(int fsId,int blockNum) ;

};

#endif /* DISKBUFFFULLLIST_H_ */
