////============================================================================
//// Name        : NewsDistribution.cpp
//// Author      : Isan Rivkin
//// Version     :
//// Copyright   : BTC ETH
//// Description : Hello World in C++, Ansi-style
////============================================================================
//// good mutex tutorial
////https://www.thegeekstuff.com/2012/05/c-mutex-examples/?refcom
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include "MThread.h"
//
//// offirs semaphore example
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <pthread.h>
//#include <unistd.h>
//#include <semaphore.h>
//
//using namespace std;
//
//int glob = 0;
//pthread_mutex_t lock;
//sem_t mutex;
//
//void* thread(void* arg)
//{
//    //wait
//    sem_wait(&mutex);
//    printf("\nEntered..\n");
//
//    //critical section
//    sleep(4);
//
//    //signal
//    printf("\nJust Exiting...\n");
//    sem_post(&mutex);
//}
//
//class Thread : public MThread
//{
//private:
//	int flag;
//public:
//	Thread(int f):flag(f){}
//	virtual void run()
//	{
//		pthread_mutex_lock(&lock);
//		while(1)
//		{
//			if(flag){
//			   // pthread_mutex_lock(&lock);
//			    for(int i=0;i<10;++i){
//			    	increase();
//			    }
//			    //pthread_mutex_unlock(&lock);
//			}
//
//			else{
//				//pthread_mutex_lock(&lock);
//				for(int i=0;i<10;++i){
//				decrease();
//				}
//				//pthread_mutex_unlock(&lock);
//			}
//			cout << glob << endl;
//			sleep(1);
//		}
//		pthread_mutex_unlock(&lock);
//
//	}
//	void increase()
//	{
//		cout << "up"<<endl;
//		glob++;
//	}
//	void decrease()
//	{
//		cout << "down" <<endl;
//		glob--;
//	}
//};
//
//void run(){
//    sem_init(&mutex, 0, 1);
//    pthread_t t1,t2,t3;
//    pthread_create(&t1,NULL,thread,NULL);
//    sleep(1.5);
//    pthread_create(&t2,NULL,thread,NULL);
//    sleep(1);
//    pthread_create(&t3,NULL,thread,NULL);
//    pthread_join(t1,NULL);
//    pthread_join(t2,NULL);
//    pthread_join(t3,NULL);
//    sem_destroy(&mutex);
//}
//int main2(void)
//{
//	//cout << "starting..." <<endl;
//	run();
////    if (pthread_mutex_init(&lock, NULL) != 0)
////    {
////        printf("\n mutex init failed\n");
////        return 1;
////    }
////	MThread * t = new Thread(1);
////	MThread * t2 = new Thread(0);
////	t->start();
////	t2->start();
////	t->waitForThread();
////    pthread_mutex_destroy(&lock);
//
//    return 0;
//}
