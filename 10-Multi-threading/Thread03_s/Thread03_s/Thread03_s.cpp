// Thread03_s.cpp : définit le point d'entrée pour l'application console.
// http://www.bogotobogo.com/cplusplus/C11/7_C11_Thread_Sharing_Memory.php

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <list>
#include <algorithm>
#include <mutex>

using namespace std;

list<int> myList;

/*
void ajoutPair(int max)
{
	for (int i = 0; i < max; i++) {
		if ((i % 2) == 0) myList.push_back(i);
	}
}

void ajoutImpair(int max)
{
	for (int i = 0; i < max; i++) {
		if ((i % 2) == 1) myList.push_back(i);
	}
}

void printList()
{
	for (auto itr = myList.begin(), end_itr = myList.end(); itr != end_itr; ++itr) {
		cout << *itr << ",";
	}
}

// solution simple avec lock() et unlock()

void ajoutPair(int max)
{
	mtx.lock();
	for (int i = 0; i < max; i++) {
		if ((i % 2) == 0) myList.push_back(i);
	}
	mtx.unlock();
}

void ajoutImpair(int max)
{
	mtx.lock();
	for (int i = 0; i < max; i++) {
		if ((i % 2) == 1) myList.push_back(i);
	}
	mtx.unlock();
}

void printList()
{
	mtx.lock();
	for (auto itr = myList.begin(), end_itr = myList.end(); itr != end_itr; ++itr) {
		cout << *itr << ",";
	}
	mtx.unlock();
}

*/

// solution avec lock_guard:

mutex mtx;

void ajoutPair(int max)
{
	lock_guard<mutex> guard(mtx);
	for (int i = 0; i < max; i++) {
		if ((i % 2) == 0) myList.push_back(i);
	}
}

void ajoutImpair(int max)
{
	lock_guard<mutex> guard(mtx);
	for (int i = 0; i < max; i++) {
		if ((i % 2) == 1) myList.push_back(i);
	}
}

void printList()
{
	lock_guard<mutex> guard(mtx);
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
