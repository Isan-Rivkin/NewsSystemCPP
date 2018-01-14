/*
 * MThread.h
 *
 *  Created on: Jan 13, 2018
 *      Author: wilder
 */

#ifndef MTHREAD_H_
#define MTHREAD_H_

#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
//#define PTW32_STATIC_LIB
class MThread
{
public:
	pthread_t threadId;

public:
	virtual void run() = 0;
	void start();
	void waitForThread();
	virtual ~MThread();
};

#endif /* MTHREAD_H_ */
