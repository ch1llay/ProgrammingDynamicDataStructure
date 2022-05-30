#pragma once
#include <string>
#include <random>
#include <iostream>

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
		BENCHMARK(SetOnPointers.create_time, lab2::Node* A = lab2::createSet(N, 0, N));
		lab2::Node* B = lab2::createSet(N, 0, N);
		BENCHMARK(SetOnPointers.power_time, lab2::getLength(A));
		BENCHMARK(SetOnPointers.subsetAA_time, lab2::isSubSet(A, A ));
		BENCHMARK(SetOnPointers.subsetBA_time, lab2::isSubSet(B, A ));
		BENCHMARK(SetOnPointers.combining_time, lab2::combining(A, B));
		BENCHMARK(SetOnPointers.intersection_time, lab2::intersection(A, B));
		BENCHMARK(SetOnPointers.difference_time, lab2::difference(A,B));
		BENCHMARK(SetOnPointers.symmetric_difference_time, lab2::symmetricDifference(A, B));
	}
	void RunSetOnClass() {
		BENCHMARK(SetOnPointers.create_time, lab3::Set A(N, 0, N));
		lab3::Set B(N, 0, N);
		BENCHMARK(SetOnClass.power_time, A.getLength());
		BENCHMARK(SetOnClass.subsetAA_time, A.isSubSet(A));
		BENCHMARK(SetOnClass.subsetBA_time, B.isSubSet(A));
		BENCHMARK(SetOnClass.combining_time, A.combining(B));
		BENCHMARK(SetOnClass.intersection_time, A.intersection(B));
		BENCHMARK(SetOnClass.difference_time, A.difference(B));
		BENCHMARK(SetOnClass.symmetric_difference_time, A.symmetricDifference(B));
	}
	void RunSetOnList() {
		BENCHMARK(SetOnList.create_time, lab4::Set A(N, 0, N));
		lab4::Set B(N, 0, N);
		BENCHMARK(SetOnList.power_time, A.getLength());
		BENCHMARK(SetOnList.subsetAA_time, A.isSubSet(A));
		BENCHMARK(SetOnList.subsetBA_time, B.isSubSet(A));
		BENCHMARK(SetOnList.combining_time, A.combining(B));
		BENCHMARK(SetOnList.intersection_time, A.intersection(B));
		BENCHMARK(SetOnList.difference_time, A.difference(B));
		BENCHMARK(SetOnList.symmetric_difference_time, A.symmetricDifference(B));
	}
	void RunSetOnSet() {
		BENCHMARK(SetOnSet.create_time, lab5::Set A(N, 0, N));
		lab5::Set B(N, 0, N);
		BENCHMARK(SetOnSet.power_time, A.getLength());
		BENCHMARK(SetOnSet.subsetAA_time, A.isSubSet(A));
		BENCHMARK(SetOnSet.subsetBA_time, B.isSubSet(A));
		BENCHMARK(SetOnSet.combining_time, A.combining(B));
		BENCHMARK(SetOnSet.intersection_time, A.intersection(B));
		BENCHMARK(SetOnSet.difference_time, A.difference(B));
		BENCHMARK(SetOnSet.symmetric_difference_time, A.symmetricDifference(B));
	}
	Benchmarck(int n) {
		N = n;
	}
	StatsContainer SetOnPointers;
	StatsContainer SetOnClass;
	StatsContainer SetOnList;
	StatsContainer SetOnSet;
};








