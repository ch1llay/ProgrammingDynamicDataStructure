#pragma once
#include <string>
#include <random>
#include <iostream>
#include <set>

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
	
	void RunSetOnPointers() {
		BENCHMARK(SetOnPointers->create_time, Node* A = createSet(randomInt(6, 9), 0, 100, 6));
		Node* B = createSet(randomInt(6, 9), 0, 100, 6);
		BENCHMARK(SetOnPointers->powerful_time, getLength(A));
		BENCHMARK(SetOnPointers->subsetAA_time,isSubSet(A, A ));
		BENCHMARK(SetOnPointers->subsetBA_time,isSubSet(B, A ));
		BENCHMARK(SetOnPointers->combinaning_time, combining(A, B));
		BENCHMARK(SetOnPointers->intersection_time, intersection(A, B));
		BENCHMARK(SetOnPointers->difference_time, difference(A,B));
		BENCHMARK(SetOnPointers->symmetric_difference_time, symmetricDifference(A, B));
	}
	Benchmarck() {
		
	}
	StatsContainer* SetOnPointers;
	StatsContainer* SetOnClass;
	StatsContainer* SetOnList;
	StatsContainer* SetOnSet;
};








