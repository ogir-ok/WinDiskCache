/*
 * Mutex.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#ifndef MUTEX_H_
#define MUTEX_H_

/*#ifdef LINUX

#include <pthread.h>

class Mutex
{
private:
	pthread_mutex_t _mutex;
public:
	Mutex();
	~Mutex();
	void Lock();
	void Unlock();
};

#elif WINDOWS*/
#include <Windows.h>

class Mutex
{
private:
	HANDLE _mutex;
public:
	Mutex();
	~Mutex();
	void Lock();
	void Unlock();
};
//#endif
#endif /* MUTEX_H_ */
