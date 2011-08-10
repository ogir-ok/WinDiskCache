#pragma once

using namespace System;


//#include <pthread.h>

class Mutex
{
private:
	//pthread_mutex_t _mutex;
public:
	Mutex();
	~Mutex();
	void Lock();
	void Unlock();
};