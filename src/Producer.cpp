/*
 * Producer.cpp
 *
 *  Created on: Jan 14, 2018
 *      Author: wilder
 */

#include "Producer.h"


Producer::Producer(int producerId,BoundedQueue<NewsItem*> * que,size_t itemsNumber):
	mQue(que),mItemsCounter(0),mItemsNumber(itemsNumber),
	mNewsCounter(0),mSportsCounter(0),mWeathercount(0),mProducerID(producerId){}

Producer::~Producer(){}

void Producer::run() {
	while(mItemsCounter < mItemsNumber)
	{
		// produce new items
		Data news = getItem();
		// put into queue
		mQue->insert(new NewsItem(mProducerID,news.news,news.counter));
		// when finished "end"
		mItemsCounter++;
	}
	finallize();
}
void Producer::finallize()
{
	mQue->insert(new NewsItem(mProducerID,"DONE",0));
}
Data Producer::getItem()
{
	size_t seed = rand() % 3;
	string type = "";
	size_t relevant_counter = 0;
	switch(seed)
	{
	case 0:
	{
		type = "News";
		relevant_counter = mNewsCounter;
		mNewsCounter++;
		break;
	}
	case 1:
	{
		type = "Sports";
		relevant_counter = mSportsCounter;
		mSportsCounter++;
		break;
	}
	case 2:
	{
		type = "Weather";
		relevant_counter = mWeathercount;
		mWeathercount++;
		break;
	}
	}
	return Data(type,relevant_counter);
}


