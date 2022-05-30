#pragma once
#include <string>
#include <random>
#include <iostream>

namespace lab3 {
	struct Node {
		int value = INT_MAX;
		Node* next = nullptr;
	};

	class Set {
		Node* start = nullptr;
	public:
		Set();
		Set(Set&& set);
		Set(int amount, int min, int max, int div);
		Set(int amount, int min, int max);
		~Set();
		bool isEmpty();
		bool isExist(int value);
		void add(int value);
		int getLength();
		std::string toString(char separate);

		bool isSubSet(Set& set);
		bool equils(Set& set);
		Set combining(Set& set);
		Set intersection(Set& set);
		Set difference(Set& set);
		Set symmetricDifference(Set& set);
		void clear();
	private:
		Set copy();
	};
}








