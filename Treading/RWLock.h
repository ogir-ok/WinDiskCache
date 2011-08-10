#pragma once

using namespace System;

//#include <pthread.h>

class RWLock
{
private:
	//pthread_rwlock_t _rwlock;
public:
	RWLock();
	~RWLock();
	void WrLock();
	void RdLock();
	void Unlock();
};
