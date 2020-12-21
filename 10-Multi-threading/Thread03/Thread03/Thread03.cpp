// Thread03.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <list>
#include <algorithm>
#include <mutex>

using namespace std;

list<int> myList;

std::mutex g_mutex_mutex;

void ajoutPair(int max)
{
	//unique_lock<mutex> verrou(g_mutex_mutex);
	//std::lock_gard<mutex> guard(g_mutex_mutex);
	const std::lock_guard<std::mutex> lock(g_mutex_mutex);
	//g_mutex_mutex.lock();
	for (int i = 0; i < max; i++) {
		if ((i % 2) == 0) myList.push_back(i);
	}
	//g_mutex_mutex.unlock();
}

void ajoutImpair(int max)
{
	//g_mutex_mutex.lock();
	const std::lock_guard<std::mutex> lock(g_mutex_mutex);
	for (int i = 0; i < max; i++) {
		if ((i % 2) == 1) myList.push_back(i);
	}
	//g_mutex_mutex.unlock();
}

void printList()
{
	for (auto itr = myList.begin(), end_itr = myList.end(); itr != end_itr; ++itr) {
		cout << *itr << ",";
	}
}

int main()
{
	int max = 500;

	thread t1(ajoutPair, max);
	thread t2(ajoutImpair, max);
	thread t3(printList);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}


