/*
 * Producer.h
 *
 *  Created on: Jan 14, 2018
 *      Author: wilder
 */

#include <iostream>
#include <string>
#include <string.h>
#include <strings.h>
#include "MThread.h"
#include "BoundedQueue.h"
#include "NewsItem.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>     /* srand, rand */
using namespace std;

#ifndef PRODUCER_H_
#define PRODUCER_H_


// inner logic holder
struct Data{
	string news;
	size_t counter;
	Data(string pNews,size_t pCounter):news(pNews),counter(pCounter){}
};

class Producer :public MThread
{
private:
	BoundedQueue<NewsItem*> * mQue;
	size_t mItemsCounter,mItemsNumber, mNewsCounter,mSportsCounter,mWeathercount;
	int mProducerID;
public:
	Producer(int producerId,BoundedQueue<NewsItem*> * que, size_t itemsNumber);
	virtual ~Producer();
public:
	virtual void run();
private:
	Data getItem();
	void finallize();
};

#endif /* PRODUCER_H_ */
