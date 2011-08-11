/*
 * DiskBuff.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */

#include <stdlib.h>
#include "DiskBuff.h"

DiskBuff::DiskBuff()
{
	pFreeNext = NULL;
	pFreePrev = NULL;
	pFullNext = NULL;
	pFullPrev = NULL;
	state=DISK_BLOCK_NOT_CHANGED;
}
DiskBuff::~DiskBuff()
{
	delete pData;
}



