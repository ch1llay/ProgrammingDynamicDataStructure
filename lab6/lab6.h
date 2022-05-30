#pragma once
#include <string>
#include <random>
#include <iostream>
#include <set>
#include "lab2/lab2.h"	
#include "lab3/lab3.h"	
#include "lab4/lab4.h"	
#include "lab5/lab5.h"	



////
#include <chrono>

#define GET_TIME \
	static_cast<int64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count())

#define BENCHMARK(t, func)	\
	(t) = GET_TIME;			\
	func;					\
	(t) = GET_TIME - (t)

////


struct StatsContainer {
	int create_time;
	int power_time;
	int subsetAA_time;
	int subsetBA_time;
	int combining_time;
	int intersection_time;
	int difference_time;
	int symmetric_difference_time;

};

class Benchmarck {
	
public:
	int N;
	void RunSetOnPointers() {
		BENCHMARK(SetOnPointers->create_time, lab2::Node* A = lab2::createSet(N, 0, 100, 6));
		lab2::Node* B = lab2::createSet(N, 0, 100, 6);
		BENCHMARK(SetOnPointers->power_time, lab2::getLength(A));
		BENCHMARK(SetOnPointers->subsetAA_time, lab2::isSubSet(A, A ));
		BENCHMARK(SetOnPointers->subsetBA_time, lab2::isSubSet(B, A ));
		BENCHMARK(SetOnPointers->combining_time, lab2::combining(A, B));
		BENCHMARK(SetOnPointers->intersection_time, lab2::intersection(A, B));
		BENCHMARK(SetOnPointers->difference_time, lab2::difference(A,B));
		BENCHMARK(SetOnPointers->symmetric_difference_time, lab2::symmetricDifference(A, B));
	}
	Benchmarck(int n) {
		N = n;
	}
	StatsContainer* SetOnPointers;
	/*StatsContainer* SetOnClass;
	StatsContainer* SetOnList;
	StatsContainer* SetOnSet;*/
};








