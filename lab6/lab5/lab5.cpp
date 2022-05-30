#include "lab5.h"

namespace lab5 {
	Set::Set() {

		container;
	}
	Set::Set(Set&& set) {
		container = set.container;
	}
	Set::Set(int amount, int min, int max) {
		int elem;
		while (container.size() < amount) {
			elem = min + rand() % (max - min);
			add(elem);
		}

	}

	Set::~Set() {
		container.clear();
	}

	bool Set::isEmpty() {
		return container.empty();
	}
	bool Set::isExist(int value) {
		return container.count(value) != 0;
	}
	void Set::add(int value) {
		container.insert(value);
	}
	int Set::getLength() {
		return container.size();
	}
	std::string Set::toString(char separate) {
		std::string s;
		// int last = *container.rbegin();
		for (int n : container) {
			s += /*(n != last) ?*/ std::to_string(n) + separate /*: n*/;
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
		for (int n : container) {
			if (!set.isExist(n)) {
				return false;
			}
		}
		return true;
	}
	Set Set::copy() {
		Set newSet;
		newSet.container = container;
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
		for (int n : container) {
			newSet.add(n);
		}
		for (int n : set.container) {
			newSet.add(n);
		}
		return newSet;

	}

	Set Set::intersection(Set& set) {
		Set newSet;

		if (isEmpty() || set.isEmpty()) {
			return newSet;
		}
		for (int n : set.container) {
			if (isExist(n)) {
				newSet.add(n);
			}
		}
		return newSet;
	}
	Set Set::difference(Set& set) {
		Set newSet;
		for (int n : container) {
			if (!set.isExist(n)) {
				newSet.add(n);
			}
		}
		return newSet;
	}
	Set Set::symmetricDifference(Set& set) {
		Set combiningSet = combining(set);
		Set intersectionSet = intersection(set);
		Set newNode = combiningSet.difference(intersectionSet);
		return newNode;
	}
	void Set::clear() {
		container.clear();
	}
}