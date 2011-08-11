/*
 * RWLock.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#ifndef RWLOCK_H_
#define RWLOCK_H_

#include <pthread.h>

//#ifdef LINUX

class RWLock
{
private:
	pthread_rwlock_t _rwlock;
public:
	RWLock();
	~RWLock();
	void WrLock();
	void RdLock();
	void Unlock();
};

//#endif

#endif /* RWLOCK_H_ */
