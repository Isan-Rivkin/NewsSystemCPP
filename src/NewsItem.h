/*
 * NewsItem.h
 *
 *  Created on: Jan 14, 2018
 *      Author: wilder
 */
#include <iostream>
#include <string>
#include <string.h>
#include <strings.h>

using namespace std;

#ifndef NEWSITEM_H_
#define NEWSITEM_H_

class NewsItem
{
private:
	size_t mProducerID, mTypeCounter;
	string mNews;

public:
	NewsItem(size_t producerID,string news, size_t typeCounter):
		mNews(news),mProducerID(producerID),mTypeCounter(typeCounter){}
	virtual ~NewsItem(){}
public:
	size_t getProducerID()const
	{
		return mProducerID;
	}
	size_t getNewsCounter()const
	{
		return mTypeCounter;
	}
	string getNews()const
	{
		return mNews;
	}
	void print()const{
		cout <<"ProducerID: " << mProducerID << " " << mNews << " " << mTypeCounter <<endl;
	}
};


#endif /* NEWSITEM_H_ */
