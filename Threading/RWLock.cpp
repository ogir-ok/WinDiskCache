/*
 * RWLock.cpp
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */
#include "RWLock.h"
#include "Stdafx.h"
//#ifdef LINUX

RWLock::RWLock()
{
	//pthread_rwlock_init(&(_rwlock),NULL);
}


RWLock::~RWLock()
{
	//pthread_rwlock_destroy(&(_rwlock));
}

void RWLock::WrLock()
{
	//pthread_rwlock_wrlock(&(_rwlock));
}

void RWLock::RdLock()
{
	//pthread_rwlock_rdlock(&(_rwlock));
}

void RWLock::Unlock()
{
//	pthread_rwlock_unlock(&(_rwlock));
}

//#endif
