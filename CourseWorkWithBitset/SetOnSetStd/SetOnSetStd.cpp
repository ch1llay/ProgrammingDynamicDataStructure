#include "SetOnSetStd.h"

namespace SetOnSetStd {
	Set::Set() {


	}
	Set::Set(Set&& set) {
		containerSet = set.containerSet;
	}
	Set::Set(int amount, int min, int max, int div) {
		int elem;
		for (int i = 0; i < amount;) {
			elem = min + rand() % (max - min);
			if (elem % div == 0) {
				add(elem);
				i++;
			}
		}

	}
	Set::Set(int amount, int min, int max) {
		int elem;
		while (containerSet.size() < amount) {
			elem = min + rand() % (max - min);
			add(elem);
		}

	}

	Set::~Set() {
		containerSet.clear();
	}

	bool Set::isEmpty() {
		return containerSet.empty();
	}
	bool Set::isExist(int value) {
		return containerSet.count(value) > 0;
	}
	void Set::add(int value) {
		if (!isExist(value)) {
			containerSet.insert(value);
		}
	}
	int Set::getLength() {
		return containerSet.size();
	}
	std::string Set::toString(char separate) {
		std::string s = "";
		if (!isEmpty()) {
			for (auto n : containerSet) {
				s += std::to_string(n) + separate;
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
		for (int n : containerSet) {
			if (!set.isExist(n)) {
				return false;
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
		for (int n : containerSet) {
			newSet.add(n);
		}
		for (int n : set.containerSet) {
			newSet.add(n);
		}
		return newSet;

	}

	Set Set::intersection(Set& set) {
		Set newSet;

		if (isEmpty() || set.isEmpty()) {
			return newSet;
		}
		else {
			for (int n : set.containerSet) {
				if (isExist(n)) {
					newSet.add(n);
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
			for (int n : containerSet) {
				if (!set.isExist(n)) {
					newSet.add(n);
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
		containerSet.clear();
	}
}