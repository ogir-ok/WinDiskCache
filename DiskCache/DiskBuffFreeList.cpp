/*
 * DiskBuffFreeList.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */

#include "stdafx.h"
#include"DiskBuffFreeList.h"

DiskBuffFreeList::DiskBuffFreeList()
{
	_pHead = NULL;
	_pTail = NULL;
	_countElem = 0;
}

DiskBuffFreeList::~DiskBuffFreeList()
{
	delete _pHead;
	delete _pTail;
}

void DiskBuffFreeList::AddToTail(DiskBuff* addBuff)
{
	DiskBuff* newElement = addBuff;
	newElement->pFreeNext = NULL;
	newElement->pFreePrev = _pTail;
	if (NULL != _pTail)
	{
		_pTail->pFreePrev = newElement;
	}
	_pTail = newElement;
	if (NULL == _pHead)
	{
		_pHead = newElement;
	}
	_countElem++;
}

void DiskBuffFreeList::Delete(DiskBuff * currentElement)
{
	if (NULL != currentElement)
	{
		if (_pHead == currentElement)
		{
			_pHead = currentElement->pFreeNext;
			delete currentElement;
		}
		else
		if (_pTail == currentElement)
		{
			_pTail = currentElement->pFreePrev;
			delete currentElement;
		}
		else
		{
			currentElement->pFreeNext->pFreePrev = currentElement->pFreePrev;
			currentElement->pFreePrev->pFreeNext = currentElement->pFreeNext;
			_countElem--;
			delete currentElement;
		}
	}
}

DiskBuff* DiskBuffFreeList::GetHead()
{
	DiskBuff * temp = NULL;
	temp = _pHead;
    return temp;
}



