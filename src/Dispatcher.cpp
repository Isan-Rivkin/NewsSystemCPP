/*
 * Dispatcher.cpp
 *
 *  Created on: Jan 14, 2018
 *      Author: wilder
 */

#include "Dispatcher.h"

Dispatcher::Dispatcher(vector<BQS> allQs, BQS sportsCo, BQS weatherCo, BQS newsCo):
	mAllQs(allQs),mfinishedcount(0),
	mSportsCo(sportsCo),mWeatherco(weatherCo),mNewsCo(newsCo)
	{

	}

Dispatcher::~Dispatcher() {}

void Dispatcher::run()
{
	bool stop = false;
	while(!stop)
	{
		// read messages from ques
		vector<BQS>::iterator it = mAllQs.begin();
		while(it != mAllQs.end())
		{
			if((*it)->isEmpty())
			{
				continue;
			}
			else
			{
				// blocks
				NewsItem * item = (*it)->remove();
				if(item->getNews() == "DONE")
				{
					if( (stop = finallize()) )
					{
						terminate();
					}
				}
				else
				{
					attachToQueue(item);
				}
			}
			it++;
		}
	}
}

bool Dispatcher::finallize()
{
	bool notempty = false;
	mfinishedcount++;
	vector<BQS>::iterator it = mAllQs.begin();
	while(it != mAllQs.end()){
		if(!(*it)->isEmpty()){
			notempty = true;
		}
		it++;
	}
	if(notempty)
		return false;
	if(mfinishedcount >= mAllQs.size())
		return true;
	return false;
}

bool Dispatcher::terminate()
{
	// might block
	mWeatherco->insert(new NewsItem(0,"DONE",0));
	mSportsCo->insert(new NewsItem(0,"DONE",0));
	mNewsCo->insert(new NewsItem(0,"DONE",0));
	return true;
}

void Dispatcher::attachToQueue(NewsItem * item)
{
	string t = item->getNews();
	// might block
	fromMap(t)->insert(item);
}

BoundedQueue<NewsItem*>* Dispatcher::fromMap(string newsType)
{
	string sports = "Sports";
	string news = "News";
	string weather = "Weather";
	if(newsType == sports){
		return mSportsCo;
	}else if(newsType == weather){
		return mWeatherco;
	}else{
		return mNewsCo;
	}
}
