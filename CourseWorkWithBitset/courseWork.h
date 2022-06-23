#pragma once
#include <string>
#include <random>
#include <iostream>

#include "SetOnLinkedListOnPointers/SetOnLinkedListOnPointers.h"
#include "SetOnLinkedListOnClass/SetOnLinkedListOnClass.h"
#include "SetOnListStd/SetOnListStd.h"
#include "SetOnSetStd/SetOnSetStd.h"
#include "SetOnBitset.h"	



////
#include <chrono>

#define GET_TIME \
	static_cast<int64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count())

#define BENCHMARK(t, func)	\
	(t) = GET_TIME;			\
	func;					\
	(t) = GET_TIME - (t)

////



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

template <size_t N>
class Benchmarck {

public:
	int weightTable;
	int GetDigitAmount(int n) {
		return floor(log10(n) + 1);
	}
	int* SetOnPointers;
	int* SetOnClass;
	int* SetOnList;
	int* SetOnSet;
	int* SetOnBitset;
	int* SetStats[5];
	std::vector<std::string> names = {
		"создание",
		"мощность",
		"подномножество AA",
		"подмножество BA",
		"равенство AA",
		"равенство BA",
		"объединение AB",
		"пересечение AB",
		"разность AB",
		"симметричная разность AB",
	};
	std::string GetTime(Stats statsTime) {
		std::string s = "";
		for (int i = 0; i < 5; i++) {
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
		for (int _ = 0; _ < 6; _++) {
			str += "+";
			for (int i = 0; i < weightTable; i++) {
				str += "-";
			}
		}
		str += "+\n";
		return str;
	}
	std::string GetColumnByName(std::string name, bool end = true) {
		std::string s = "|";
		int amountSymbols = name.length();
		for (int j = 0; j < (weightTable - amountSymbols) / 2; j++) {
			s += " ";
		}
		s += name;
		for (int j = 0; j < weightTable - amountSymbols - ((weightTable - amountSymbols) / 2); j++) {
			s += " ";
		}
		if (end) {
			s += "|";
		}
		return s;
	}
	std::string GetTable() {
		std::string str;
		str += GetLine();
		str += GetColumnByName("name", false);
		str += GetColumnByName("list(func)", false);
		str += GetColumnByName("list(class", false);
		str += GetColumnByName("list(std)", false);
		str += GetColumnByName("set(std)", false);
		str += GetColumnByName("bitset(std)", true);
		str += GetLine();
		for (int i = 0; i < 10; i++) {
			str += GetColumnByName(names[i]);
			str += GetTime((Stats)i);
			str += GetLine();
		}
		return str;
	}
	void RunSetOnPointers() {
		BENCHMARK(SetOnPointers[Stats::create_time], SetOnLinkedListOnPointers::Node * A = SetOnLinkedListOnPointers::createSet(N, 0, N));
		SetOnLinkedListOnPointers::Node* B = SetOnLinkedListOnPointers::createSet(N, 0, N);
		BENCHMARK(SetOnPointers[Stats::power_time], SetOnLinkedListOnPointers::getLength(A));
		BENCHMARK(SetOnPointers[Stats::subsetAA_time], SetOnLinkedListOnPointers::isSubSet(A, A));
		BENCHMARK(SetOnPointers[Stats::subsetBA_time], SetOnLinkedListOnPointers::isSubSet(B, A));
		BENCHMARK(SetOnPointers[Stats::equilAA_time], SetOnLinkedListOnPointers::equils(A, A));
		BENCHMARK(SetOnPointers[Stats::equilBA_time], SetOnLinkedListOnPointers::equils(B, A));
		BENCHMARK(SetOnPointers[Stats::combining_time], SetOnLinkedListOnPointers::combining(A, B));
		BENCHMARK(SetOnPointers[Stats::intersection_time], SetOnLinkedListOnPointers::intersection(A, B));
		BENCHMARK(SetOnPointers[Stats::difference_time], SetOnLinkedListOnPointers::difference(A, B));
		BENCHMARK(SetOnPointers[Stats::symmetric_difference_time], SetOnLinkedListOnPointers::symmetricDifference(A, B));
	}
	void RunSetOnClass() {
		BENCHMARK(SetOnClass[Stats::create_time], SetOnLinkedListOnClass::Set A(N, 0, N));
		SetOnLinkedListOnClass::Set B(N, 0, N);
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
	void RunSetOnList() {
		BENCHMARK(SetOnList[Stats::create_time], SetOnListStd::Set A(N, 0, N));
		SetOnListStd::Set B(N, 0, N);
		BENCHMARK(SetOnList[Stats::power_time], A.getLength());
		BENCHMARK(SetOnList[Stats::subsetAA_time], A.isSubSet(A));
		BENCHMARK(SetOnList[Stats::subsetBA_time], B.isSubSet(A));
		BENCHMARK(SetOnList[Stats::equilAA_time], A.equils(A));
		BENCHMARK(SetOnList[Stats::equilBA_time], B.equils(A));
		BENCHMARK(SetOnList[Stats::combining_time], A.combining(B));
		BENCHMARK(SetOnList[Stats::intersection_time], A.intersection(B));
		BENCHMARK(SetOnList[Stats::difference_time], A.difference(B));
		BENCHMARK(SetOnList[Stats::symmetric_difference_time], A.symmetricDifference(B));
	}
	void RunSetOnSet() {
		BENCHMARK(SetOnSet[Stats::create_time], SetOnSetStd::Set A(N, 0, N));
		SetOnSetStd::Set B(N, 0, N);
		BENCHMARK(SetOnSet[Stats::power_time], A.getLength());
		BENCHMARK(SetOnSet[Stats::subsetAA_time], A.isSubSet(A));
		BENCHMARK(SetOnSet[Stats::subsetBA_time], B.isSubSet(A));
		BENCHMARK(SetOnSet[Stats::equilAA_time], A.equils(A));
		BENCHMARK(SetOnSet[Stats::equilBA_time], B.equils(A));
		BENCHMARK(SetOnSet[Stats::combining_time], A.combining(B));
		BENCHMARK(SetOnSet[Stats::intersection_time], A.intersection(B));
		BENCHMARK(SetOnSet[Stats::difference_time], A.difference(B));
		BENCHMARK(SetOnSet[Stats::symmetric_difference_time], A.symmetricDifference(B));
	}
	void RunSetOnBitset() {
		BENCHMARK(SetOnBitset[Stats::create_time], SetOnBitsetStd::Set<N> A);
		SetOnBitsetStd::Set<N> B;
		BENCHMARK(SetOnBitset[Stats::power_time], A.getLength());
		BENCHMARK(SetOnBitset[Stats::subsetAA_time], A.isSubSet(A));
		BENCHMARK(SetOnBitset[Stats::subsetBA_time], B.isSubSet(A));
		BENCHMARK(SetOnBitset[Stats::equilAA_time], A.equils(A));
		BENCHMARK(SetOnBitset[Stats::equilBA_time], B.equils(A));
		BENCHMARK(SetOnBitset[Stats::combining_time], A.combining(B));
		BENCHMARK(SetOnBitset[Stats::intersection_time], A.intersection(B));
		BENCHMARK(SetOnBitset[Stats::difference_time], A.difference(B));
		BENCHMARK(SetOnBitset[Stats::symmetric_difference_time], A.symmetricDifference(B));
	}
	int GetMaxLengthWord() {
		int max = names[0].length();
		for (int i = 0; i < names.size(); i++) {
			if (names[i].length() > max) {
				max = names[i].length();
			}
		}
		return max;
	}
	Benchmarck() {
		SetOnPointers = new int[10];
		SetOnClass = new int[10];
		SetOnList = new int[10];
		SetOnSet = new int[10];
		SetOnBitset = new int[10];
		SetStats[0] = SetOnPointers;
		SetStats[1] = SetOnClass;
		SetStats[2] = SetOnList;
		SetStats[3] = SetOnSet;
		SetStats[4] = SetOnBitset;
		weightTable = GetMaxLengthWord();
	}

};








