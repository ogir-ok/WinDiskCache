/*
 * DiskBuffFreeList.h
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */
#pragma once

using namespace System;

#ifndef DISKBUFFREEFLIST_H_
#define DISKBUFFREEFLIST_H_

#include "DiskBuff.h"
#include <Mutex.h>
#include <RWLock.h>
#include <FSDriver.h>
#include <stdlib.h>

class DiskBuffFreeList
{
public:
	DiskBuff* _pHead;
	DiskBuff* _pTail;
	int _countElem;
	DiskBuffFreeList();
	~DiskBuffFreeList();
	void AddToTail(DiskBuff* addBuff);
	void Delete(DiskBuff * el);
	DiskBuff* GetHead() ;

};



#endif /* DISKBUFFREEFLIST_H_ */
