/*
 * DiskBuffFullList.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: user
 */

#include "DiskBuffFullList.h"
DiskBuffFullList::DiskBuffFullList()
{
	_pHead = NULL;
	_pTail = NULL;
	_countElem = 0;

}

DiskBuffFullList::~DiskBuffFullList()
{
	delete _pHead;
	delete _pTail;
}

void DiskBuffFullList::AddToTail(DiskBuff* addBuff)
{
	DiskBuff* newElement = addBuff;
	newElement->pFullNext = NULL;
	newElement->pFullPrev = _pTail;
	if (NULL != _pTail)
	{
		_pTail->pFullPrev = newElement;
	}
	_pTail = newElement;
	if (NULL == _pHead)
	{
		_pHead = newElement;
	}
	_countElem++;
}

void DiskBuffFullList::Delete(DiskBuff * currentElement)
{
	if (NULL != currentElement)
	{
		if (_pHead == currentElement)
		{
			_pHead = currentElement->pFullNext;
			delete currentElement;
		}
		else
		if (_pTail == currentElement)
		{
			_pTail = currentElement->pFullPrev;
			delete currentElement;
		}
		else
		{
			currentElement->pFullNext->pFullPrev = currentElement->pFullPrev;
			currentElement->pFullPrev->pFullNext = currentElement->pFullNext;
				_countElem--;
			delete currentElement;
		}
	}
}

DiskBuff* DiskBuffFullList::Get(int fsId, int blockNum)
{
	DiskBuff *temp = _pHead;
	  	temp = _pHead;
	    while (temp != NULL)
	    {
	    	if ((temp->fsId == fsId)&&(temp->fsBlockNum == blockNum))
	    	{
	    		break;
	    	}
	    	temp = temp->pFullNext;
	    }
     return temp;
}




