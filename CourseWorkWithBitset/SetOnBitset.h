#pragma once
#include <bitset>
#include <string>


namespace courseWorkSetOnBitset {
	template<size_t N>
	class Set {

	public:
		std::bitset<N> containerSet;
		Set() {
			int elem;
			int min = 0;
			int max = 1;
			while (containerSet.size() < N) {
				elem = min + rand() % (max - min);
				add(elem);
			}
		}
		Set(Set&& set) {
			containerSet = set.containerSet;
		}
		~Set() {
			containerSet.reset();
		}
		bool isEmpty() {
			return containerSet.none();
		}
		bool isExist(int value) {
			if (!isEmpty()) {
				return containerSet[value] == 1;
			}
			return false;
		}
		void add(int value) {
			if (!isExist(value)) {
				containerSet[value] = 1;
			}
		}
		int getLength() {
			return containerSet.size();
		}
		std::string toString(char separate) {
			std::string s = "";
			if (!isEmpty()) {
				for (int i = 0; i < N; i++) {
					if (containerSet[i] == 1) {
						s += i < N - 1 ? std::to_string(i) + separate : std::to_string(i);
					}
				}
			}
			return s;
		}

		bool isSubSet(Set& set) {
			if (isEmpty()) {
				return true;
			}
			if (getLength() > set.getLength()) {
				return false;
			}
			for (int i = 0; i < N; i++) {
				if (containerSet[i] == 1) {
					if (!set.isExist(i)) {
						return false;
					}
				}
			}
			return true;
		}
		bool equils(Set& set) {
			return isSubSet(set) && set.isSubSet(*this);
		}
		Set combining(Set& set) {
			Set<N> newSet;

			if (isEmpty() && set.isEmpty()) {
				return newSet;
			}
			if (isEmpty()) {
				return set.copy();
			}
			else if (set.isEmpty()) {
				return copy();
			}
			for (int i = 0; i < N; i++) {
				if (containerSet[i] == 1) {
					newSet.add(i);
				}
			}
			for (int i = 0; i < N; i++) {
				if (set.containerSet[i] == 1) {
					newSet.add(i);
				}
			}
			return newSet;
		}
		Set intersection(Set& set) {
			Set newSet;

			if (isEmpty() || set.isEmpty()) {
				return newSet;
			}
			else {
				for (int i = 0; i < N; i++) {
					if (set.containerSet[i] == 1) {
						if (isExist(i)) {
							newSet.add(i);
						}
					}
				}
				return newSet;
			}
		}
		Set difference(Set& set) {
			Set newSet;
			if (isEmpty()) {
				return newSet;
			}
			else if (set.isEmpty()) {
				return newSet;
			}
			else {
				for (int i = 0; i < N; i++) {
					if (containerSet[i] == 1) {
						if (!set.isExist(i)) {
							newSet.add(i);
						}
					}
				}
				return newSet;
			};
		}
		Set symmetricDifference(Set& set) {
			Set combiningSet = combining(set);
			Set intersectionSet = intersection(set);
			Set newNode = combiningSet.difference(intersectionSet);
			return newNode;
		}
		void clear() {
			containerSet.reset();
		}
	private:
		Set copy() {
			Set newSet;
			newSet.containerSet = containerSet;
			return newSet;
		}
	};
}