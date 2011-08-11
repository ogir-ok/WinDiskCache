/*
 * DiskCache.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: user
 */
#include "stdafx.h"
#include "DiskCache.h"
DiskCache::DiskCache(char* DiskConfigFile)
{
	_diskBuffHashTable = new DiskBuffHashTable();
	_diskBuffFreeList = new DiskBuffFreeList();
	FSDriver::Create(DiskConfigFile);
	_mutex = new Mutex();
	_buffCount = 0;
}
/*
class MyException : public std::exception
{
public:
	MyException(const std::string& message):
		_message(message)
	{

	}

	const char* what() const throw() {
		return _message.c_str();
	}

private:
	std::string _message;
};
*/

DiskCache::~DiskCache()
{
	Commit();
	delete _diskBuffHashTable;
	delete _diskBuffFreeList;
	delete _mutex;
	FSDriver::Destroy();
}
void DiskCache::Commit()
{
	_mutex->Lock();
	DiskBuff* pCurrentElement = _diskBuffFreeList->_pHead;
	while(pCurrentElement != _diskBuffFreeList->_pTail)
	{
		if(DISK_BLOCK_CHANGED == pCurrentElement->state)
		{
			FSDriver::Instance()->SetBlock(pCurrentElement->fsId, pCurrentElement->fsBlockNum, pCurrentElement->pData);
		}
		pCurrentElement = pCurrentElement->pFreeNext;
	}
	_mutex->Unlock();
}

BlockData DiskCache::Read(int fsId, int pos, int len)
{
	_mutex->Lock();
	int block = (pos / BLOCK_SIZE);
	DiskBuff* ans =	 _diskBuffHashTable->Get(fsId,block);

	if(NULL == ans)
	{
		if (_buffCount < MAX_BUFF_COUNT)
		{
			ans = new DiskBuff();
		}
		else
		{
			do
			{
				ans = _diskBuffFreeList->GetHead();
			}
			while(NULL == ans);

			_diskBuffHashTable->Del(ans);
			_diskBuffFreeList->Delete(ans);

			if(DISK_BLOCK_CHANGED == ans->state)
			{
				 if (-1 == FSDriver::Instance()->SetBlock(fsId,block, ans->pData))
				 {
					 throw("Can`t set block in function read");
				 }
			}
		}
		ans->fsId = fsId;
		ans->fsBlockNum = block;
		ans->pData = new char[BLOCK_SIZE];
		 if (-1 == FSDriver::Instance()->GetBlock(fsId, block,&(ans->pData)))
		{
			 throw("Can`t get block in function read");
		}

		_diskBuffHashTable->Add(ans);
	}
	else
	{
		_diskBuffFreeList->Delete(ans);
	}
	char *temp = ans->pData;
	_diskBuffFreeList->AddToTail(ans);
	_mutex->Unlock();
	return temp;
}

void DiskCache::Write(int fsId, int pos, int len, char* value)
{

	_mutex->Lock();
	int block = (pos % BLOCK_SIZE);
	DiskBuff* ans =	 _diskBuffHashTable->Get(fsId,block);
	if(NULL == ans)
	{
		if (_buffCount < MAX_BUFF_COUNT)
		{
			ans=new DiskBuff();
		}
		else
		{
			do
			{
				ans = _diskBuffFreeList->GetHead();
			}while(NULL==ans);

			_diskBuffHashTable->Del(ans);
			_diskBuffFreeList->Delete(ans);

			if(DISK_BLOCK_CHANGED == ans->state)
			{
				 if (-1 == FSDriver::Instance()->SetBlock(fsId,block, ans->pData))
				 {
					 throw "Can`t set block in function Write";
				 }
			}
		}
		_diskBuffHashTable->Add(ans);

	}
	else
	{
		_diskBuffFreeList->Delete(ans);
	}
	ans->pData = value;
	ans->state = DISK_BLOCK_CHANGED;
	_diskBuffFreeList->AddToTail(ans);
	_mutex->Unlock();
}


