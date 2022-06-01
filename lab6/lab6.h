#pragma once
#include <string>
#include <random>
#include <iostream>

#include "../lab2/lab2.h"
#include "../lab3/lab3.h"	
#include "../lab4/lab4.h"	
#include "../lab5/lab5.h"	



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
	int equilAA;
	int equilBA;
	int combining_time;
	int intersection_time;
	int difference_time;
	int symmetric_difference_time;


};
enum Stats {
	create_time,
	power_time,
	subsetAA_time,
	subsetBA_time,
	equilAA_time,
	equilBA_time,
	combining_time,
	intersection_time,
	difference_time,
	symmetric_difference_time
};

class Benchmarck {

public:
	int N;
	int weightTable;
	int GetDigitAmount(int n) {
		return floor(log10(n) + 1);
	}
	int* SetOnPointers;
	int* SetOnClass;
	int* SetOnList;
	int* SetOnSet;
	int* SetStats[4] = {SetOnPointers, SetOnClass, SetOnList, SetOnSet};
	std::string GetTime(Stats statsTime) {
		std::string s = "";
		for (int i = 0; i < 4; i++) {
			int time = SetStats[i][statsTime];
			int amountDigit = GetDigitAmount(time);
			for (int j = 0; j < (weightTable - amountDigit) / 2; j++) {
				s += " ";
			}
			s += std::to_string(time);
			for (int j = 0; j < weightTable - amountDigit - ((weightTable - amountDigit) / 2); j++) {
				s += " ";
			}
			s += "|";
		}
		return s;
	}

	std::string GetLine() {
		std::string str = "\n";
		for (int _ = 0; _ < 4; _++) {
			str += "+";
			for (int i = 0; i < weightTable; i++) {
				str += "-";
			}
		}
		str += "+\n";
		return str;
	}
	std::string GetColumnByName(std::string name) {
		std::string s;
		int amountSymbols = name.length();
		for (int j = 0; j < (weightTable - amountSymbols) / 2; j++) {
			s += " ";
		}
		s += name;
		for (int j = 0; j < weightTable - amountSymbols - ((weightTable - amountSymbols) / 2); j++) {
			s += " ";
		}
		s += "|";
		return s;
	}
	std::string GetTable() {
		std::string str;
		str += GetLine();
		str += "|";
		str += GetColumnByName("list(func)");
		str += GetColumnByName("list(class");
		str += GetColumnByName("list(std)");
		str += GetColumnByName("set(std)");
		str += GetLine();
		str += "|";
		str += GetCreateTime();
		str += GetLine();
		return str;
	}
	void RunSetOnPointers() {
		BENCHMARK(SetOnPointers[Stats::create_time], lab2::Node * A = lab2::createSet(N, 0, N));
		lab2::Node* B = lab2::createSet(N, 0, N);
		BENCHMARK(SetOnPointers[Stats::power_time],					 lab2::getLength(A));
		BENCHMARK(SetOnPointers[Stats::subsetAA_time],				 lab2::isSubSet(A, A));
		BENCHMARK(SetOnPointers[Stats::subsetBA_time],				 lab2::isSubSet(B, A));
		BENCHMARK(SetOnPointers[Stats::equilAA_time],				 lab2::equils(A, A));
		BENCHMARK(SetOnPointers[Stats::equilBA_time],				 lab2::equils(B, A));
		BENCHMARK(SetOnPointers[Stats::combining_time],				 lab2::combining(A, B));
		BENCHMARK(SetOnPointers[Stats::intersection_time]			,lab2::intersection(A, B));
		BENCHMARK(SetOnPointers[Stats::difference_time],			 lab2::difference(A, B));
		BENCHMARK(SetOnPointers[Stats::symmetric_difference_time], lab2::symmetricDifference(A, B));
	}
	void RunSetOnClass() {
		BENCHMARK(SetOnClass[Stats::create_time], lab3::Set A(N, 0, N));
		lab3::Set B(N, 0, N);
		BENCHMARK(SetOnClass[Stats::power_time], A.getLength());
		BENCHMARK(SetOnClass[Stats::subsetAA_time], A.isSubSet(A));
		BENCHMARK(SetOnClass[Stats::subsetBA_time], B.isSubSet(A));
		BENCHMARK(SetOnClass[Stats::equilAA_time], A.equils(A));
		BENCHMARK(SetOnClass[Stats::equilBA_time], B.equils(A));
		BENCHMARK(SetOnClass[Stats::combining_time], A.combining(B));
		BENCHMARK(SetOnClass[Stats::intersection_time],			A.intersection(B));
		BENCHMARK(SetOnClass[Stats::difference_time], A.difference(B));
		BENCHMARK(SetOnClass[Stats::symmetric_difference_time], A.symmetricDifference(B));
	}
	void RunSetOnList() {
		BENCHMARK(SetOnClass[Stats::create_time], lab4::Set A(N, 0, N));
		lab4::Set B(N, 0, N);
		BENCHMARK(SetOnClass[Stats::power_time], A.getLength());
		BENCHMARK(SetOnClass[Stats::subsetAA_time], A.isSubSet(A));
		BENCHMARK(SetOnClass[Stats::subsetBA_time], B.isSubSet(A));
		BENCHMARK(SetOnClass[Stats::equilAA_time], A.equils(A));
		BENCHMARK(SetOnClass[Stats::equilBA_time], B.equils(A));
		BENCHMARK(SetOnClass[Stats::combining_time], A.combining(B));
		BENCHMARK(SetOnClass[Stats::intersection_time], A.intersection(B));
		BENCHMARK(SetOnClass[Stats::difference_time], A.difference(B));
		BENCHMARK(SetOnClass[Stats::symmetric_difference_time], A.symmetricDifference(B));
	}
	void RunSetOnSet() {
		BENCHMARK(SetOnClass[Stats::create_time], lab5::Set A(N, 0, N));
		lab5::Set B(N, 0, N);
		BENCHMARK(SetOnClass[Stats::power_time], A.getLength());
		BENCHMARK(SetOnClass[Stats::subsetAA_time], A.isSubSet(A));
		BENCHMARK(SetOnClass[Stats::subsetBA_time], B.isSubSet(A));
		BENCHMARK(SetOnClass[Stats::equilAA_time], A.equils(A));
		BENCHMARK(SetOnClass[Stats::equilBA_time], B.equils(A));
		BENCHMARK(SetOnClass[Stats::combining_time], A.combining(B));
		BENCHMARK(SetOnClass[Stats::intersection_time], A.intersection(B));
		BENCHMARK(SetOnClass[Stats::difference_time], A.difference(B));
		BENCHMARK(SetOnClass[Stats::symmetric_difference_time], A.symmetricDifference(B));
	}
	Benchmarck(int n, int weight_table) {
		N = n;
		weightTable = weight_table;
	}

};








