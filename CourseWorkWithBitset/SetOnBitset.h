#pragma once
#include <bitset>


namespace courseWorkSetOnBitset {
	class Set {

	public:
		static const int N = 1000;
		std::bitset<N> containerSet;
		Set();
		Set(Set&& set);
		Set(int amount);
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