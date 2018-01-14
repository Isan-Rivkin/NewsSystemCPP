/*
 * tests.cpp
 *
 *  Created on: Jan 14, 2018
 *      Author: wilder
 */
//bounded queue example

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MThread.h"
#include <vector>
// offirs semaphore example
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <vector>
#include <math.h>
#include <time.h>
#include "BoundedQueue.h"
#include "Producer.h"
#include "NewsItem.h"
#include "Dispatcher.h"
using namespace std;

int glob = 0;

sem_t mutex;
sem_t empty;
sem_t full;
vector<int> bounded_que;

void* producer_thread(void* arg)
{
	while(1)
	{
	//	cout << "[producer] waiting " <<endl;;
		sem_wait(&empty);
		sem_wait(&mutex);
		 srand (time(NULL));
		 int iSecret = rand() % 10 + 1;
		 bounded_que.push_back(iSecret);
		 srand (time(NULL)+19);
		 int iSecret2 = rand() % 10 + 1;
		 bounded_que.push_back(iSecret2);
		 cout <<"[producer]: posted values = " << iSecret << "," << iSecret2<<endl;
			sleep(1);
		sem_post(&mutex);
		sem_post(&full);
	//	cout << "[producer] finished " <<endl;;
	}
}

void* consumer_thread(void* arg)
{
	while(1)
	{
		//cout << "[consumer ] waiting " <<endl;
		sem_wait(&full);
		sem_wait(&mutex);
		sleep(1);
		int value = bounded_que.at(0);
		bounded_que.clear();
		cout << "[consumer] got value = " << value <<endl;
		sem_post(&mutex);
		sem_post(&empty);
		//cout <<"[consumer:] finished"<<endl;
	}
}

void consumerProducer(){
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, 1);
	sem_init(&mutex, 0, 1);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,consumer_thread,NULL);
	sleep(3);
	pthread_create(&t2,NULL,producer_thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}

BoundedQueue<NewsItem*> * bQue = new BoundedQueue<NewsItem*>(1);
void* testListener_thread(void* arg){
	while(true){
		NewsItem * item = bQue->remove();
		item->print();
	}
}
void runProducersTestOnly(){
	Producer * p1 = new Producer(0,bQue,5);
	pthread_t t2;
	pthread_create(&t2,NULL,testListener_thread,NULL);
	p1->start();
	p1->waitForThread();
    pthread_join(t2,NULL);
}
void runProducersInitialWithDispatcherTest(){
	BoundedQueue<NewsItem*> *  q1 = new BoundedQueue<NewsItem*>(1);
	BoundedQueue<NewsItem*> *  q2 = new BoundedQueue<NewsItem*>(1);
	BoundedQueue<NewsItem*> *  q3 = new BoundedQueue<NewsItem*>(1);
	vector<BoundedQueue<NewsItem*>*> qs;
	qs.push_back(q1);
	qs.push_back(q2);
	qs.push_back(q3);
	size_t totalMsgs = 5;
	Producer * p1 = new Producer(0,q1,totalMsgs);
	Producer * p2 = new Producer(1,q2,totalMsgs);
	Producer * p3 = new Producer(2,q3,totalMsgs);
	Dispatcher * dispatcher = new Dispatcher(qs,q1,q2,q3);
	dispatcher->start();
	sleep(1);
	p1->start();
	sleep(0.5);
	p2->start();
	sleep(0.5);
	p3->start();
	p1->waitForThread();
	p2->waitForThread();
	p3->waitForThread();
	dispatcher->waitForThread();
}
int main(void)
{

    return 0;
}


