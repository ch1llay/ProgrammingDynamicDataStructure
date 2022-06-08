#include "SetOnBitset.h"
#include <string>

namespace courseWorkSetOnBitset {
	Set::Set() {


	}
	Set::Set(Set&& set) {
		containerSet = set.containerSet;
	}
	Set::Set(int amount) {
		int elem;
		int min = 0;
		int max = 1;
		while (containerSet.size() < amount) {
			elem = min + rand() % (max - min);
			add(elem);
		}

	}

	Set::~Set() {
		containerSet.reset();
	}

	bool Set::isEmpty() {
		return containerSet.none();
	}
	bool Set::isExist(int value) {
		if (!isEmpty()) {
			return containerSet[value] == 1;
		}
		return false;
	}
	void Set::add(int value) {
		if (!isExist(value)) {
			containerSet[value] = 1;
		}
	}
	int Set::getLength() {
		return containerSet.size();
	}
	std::string Set::toString(char separate) {
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

	bool Set::isSubSet(Set& set) {
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
	Set Set::copy() {
		Set newSet;
		newSet.containerSet = containerSet;
		return newSet;
	}
	bool Set::equils(Set& set) {
		return isSubSet(set) && set.isSubSet(*this);
	}
	Set Set::combining(Set& set) {
		Set newSet;

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

	Set Set::intersection(Set& set) {
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
	Set Set::difference(Set& set) {
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
	Set Set::symmetricDifference(Set& set) {
		Set combiningSet = combining(set);
		Set intersectionSet = intersection(set);
		Set newNode = combiningSet.difference(intersectionSet);
		return newNode;
	}
	void Set::clear() {
		containerSet.reset();
	}
}