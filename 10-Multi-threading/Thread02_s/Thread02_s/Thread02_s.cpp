// Thread02_s.cpp : définit le point d'entrée pour l'application console.
//
#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cassert>

using namespace std;

/*
const int max_sum_item = 1000000000;

void do_sum(long long *total)
{
	*total = 0;

	for (int i = 0; i < max_sum_item; i++)
	*total += i;
}

int main()
{
	long long result;

	std::cout << "Debut du calcul..." << std::endl;
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

	thread worker(do_sum, &result);

	worker.join();

	chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

	std::cout << "Resultat: " << result << " obtenu en " << (end - start).count() * ((double)chrono::high_resolution_clock::period::num
	/ chrono::high_resolution_clock::period::den) << "sec"
	<< std::endl;

	return 0;
}

*/

#define TRACE
#ifdef TRACE
mutex coutmutex;
#endif

std::vector<long long *> part_sums;
const int max_sum_item = 1000000000;
const int threads_to_use = 7;

void do_partial_sum(long long *final, int start_val, int sums_to_do) {
#ifdef TRACE
	coutmutex.lock();
	std::cout << "Depart: TID " << this_thread::get_id()
		<< " debut a " << start_val << ", calcul de " << sums_to_do << " elements" << std::endl;
coutmutex.unlock();

	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
#endif

	long long sub_result = 0;

	for (int i = start_val; i < start_val + sums_to_do; i++)
		sub_result += i;

	*final = sub_result;

#ifdef TRACE
	chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

	coutmutex.lock();
	std::cout << "Fin  : TID " << this_thread::get_id()
		<< " avec resultat " << sub_result << ", duree "
		<< (end - start).count() * ((double)chrono::high_resolution_clock::period::num
			/ chrono::high_resolution_clock::period::den)
		<< std::endl;
	coutmutex.unlock();
#endif
}

int main() {
	part_sums.clear();

	for (int i = 0; i < threads_to_use; i++) {
		part_sums.push_back(new long long(0));
	}

	std::vector<thread *> t;

	int sums_per_thread = max_sum_item / threads_to_use;

	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

	for (int start_val = 0, i = 0; start_val < max_sum_item; start_val += sums_per_thread, i++) {
		// si le nombre d'entiers n'est pas modulo le nombre de threads, c'est le dernier thread qui s'en occupe
		int sums_to_do = sums_per_thread;
		if (start_val + sums_per_thread < max_sum_item && start_val + sums_per_thread * 2 > max_sum_item) {
			sums_to_do = max_sum_item - start_val;
		}

		t.push_back(new thread(do_partial_sum, part_sums[i], start_val, sums_to_do));

		if (sums_to_do != sums_per_thread) {
			break;
		}
	}

	for (int i = 0; i < threads_to_use; i++) {
		t[i]->join();
	}

	long long result = 0;

	for (auto it = part_sums.begin(); it != part_sums.end(); ++it) {
		result += **it;
	}

	auto end = chrono::high_resolution_clock::now();

	for (int i = 0; i < threads_to_use; i++) {
		delete t[i];
		delete part_sums[i];
	}

	assert(result == long long(499999999500000000));

	std::cout << "Résultat correct" << " obtenu en "
		<< (end - start).count() * ((double)chrono::high_resolution_clock::period::num
			/ chrono::high_resolution_clock::period::den)
		<< "sec" << std::endl;

	return 0;
}
