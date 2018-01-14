/*
 * BoundedQueue.h
 *
 *  Created on: Jan 14, 2018
 *      Author: wilder
 */
#include <queue>
#include <iostream>
#include <semaphore.h>
#include <string.h>
#include <strings.h>
#include <string>

using namespace std;
#ifndef BOUNDEDQUEUE_H_
#define BOUNDEDQUEUE_H_

template <class T>
class BoundedQueue
{
private:
	std::queue<T> que;
	sem_t mFull;
	sem_t mEmpty;
	sem_t mMutex;
public:
	BoundedQueue(size_t max_capacity);
	virtual ~BoundedQueue();
public:
	T remove();
	void insert(T value);
	bool isEmpty()const;
};

template<class T>
inline BoundedQueue<T>::BoundedQueue(size_t max_capacity)
{
	sem_init(&mMutex,0,1);
	sem_init(&mEmpty,0,max_capacity);
	sem_init(&mFull,0,0);
}

template<class T>
inline BoundedQueue<T>::~BoundedQueue() {
}

template<class T>
inline T BoundedQueue<T>::remove()
{
	sem_wait(&mFull);
	sem_wait(&mMutex);
	T value = this->que.front();
	this->que.pop();
	sem_post(&mMutex);
	sem_post(&mEmpty);
	return value;
}

template<class T>
inline void BoundedQueue<T>::insert(T value)
{
	sem_wait(&mEmpty);
	sem_wait(&mMutex);
	this->que.push(value);
	sem_post(&mMutex);
	sem_post(&mFull);
}

template<class T>
inline bool BoundedQueue<T>::isEmpty()const
{
	return que.empty();
}

#endif /* BOUNDEDQUEUE_H_ */
