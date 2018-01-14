/*
 * Dispatcher.h
 *
 *  Created on: Jan 14, 2018
 *      Author: wilder
 */

#ifndef DISPATCHER_H_
#define DISPATCHER_H_

#include <iostream>
#include <string>
#include <string.h>
#include <strings.h>
#include "MThread.h"
#include "BoundedQueue.h"
#include "NewsItem.h"
#include <vector>
#include <hash_map>

using namespace std;


class Dispatcher : public MThread
{
private:
	typedef BoundedQueue<NewsItem*>* BQS;
	vector<BQS> mAllQs;
	BQS mSportsCo,mNewsCo,mWeatherco;
	size_t mfinishedcount;
public:
	Dispatcher(vector<BQS> allQ, BQS sportsCo, BQS weatherCo, BQS newsCo);
	virtual ~Dispatcher();
public:
	virtual void run();
private:
	// finallize connection with producers
	bool finallize();
	// finallize connection with co-producers
	bool terminate();
	// might block
	void attachToQueue(NewsItem * item);
	// find co-producer que mapping(news type=> que)
	BoundedQueue<NewsItem*>* fromMap(string newsType);
};

#endif /* DISPATCHER_H_ */
