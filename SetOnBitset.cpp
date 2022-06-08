#include "SetOnBitset.h"
#include <string>

namespace courseWorkSetOnBitset {

	template<size_t N>
	Set<N>::Set(Set&& set) {
		containerSet = set.containerSet;
	}
	template<size_t N>
	Set<N>::Set() {
		int elem;
		int min = 0;
		int max = 1;
		while (containerSet.size() < N) {
			elem = min + rand() % (max - min);
			add(elem);
		}

	}
	template<size_t N>
	Set<N>::~Set<N>() {
		containerSet.reset();
	}
	template<size_t N>
	bool Set<N>::isEmpty() {
		return containerSet.none();
	}
	template<size_t N>
	bool Set<N>::isExist(int value) {
		if (!isEmpty()) {
			return containerSet[value] == 1;
		}
		return false;
	}
	template<size_t N>
	void Set<N>::add(int value) {
		if (!isExist(value)) {
			containerSet[value] = 1;
		}
	}
	template<size_t N>
	int Set<N>::getLength() {
		return containerSet.size();
	}
	template<size_t N>
	std::string Set<N>::toString(char separate) {
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

	template<size_t N>
	bool Set<N>::isSubSet(Set& set) {
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
	template<size_t N>
	Set<N> Set<N>::copy() {
		Set newSet;
		newSet.containerSet = containerSet;
		return newSet;
	}
	template<size_t N>
	bool Set<N>::equils(Set& set) {
		return isSubSet(set) && set.isSubSet(*this);
	}
	template<size_t N>
	Set<N> Set<N>::combining(Set& set) {
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

	template<size_t N>
	Set<N> Set<N>::intersection(Set<N>& set) {
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
	template<size_t N>
	Set<N> Set<N>::difference(Set& set) {
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
	template<size_t N>
	Set<N> Set<N>::symmetricDifference(Set& set) {
		Set combiningSet = combining(set);
		Set intersectionSet = intersection(set);
		Set newNode = combiningSet.difference(intersectionSet);
		return newNode;
	}
	template<size_t N>
	void Set<N>::clear() {
		containerSet.reset();
	}
}