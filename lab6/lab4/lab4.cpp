#include "Lab4.h"


namespace lab4 {
	Set::Set() {

		lst;
	}
	Set::Set(Set&& set) {
		lst = set.lst;
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

	Set::~Set() {
		lst.clear();
	}

	bool Set::isEmpty() {
		return lst.empty();
	}
	bool Set::isExist(int value) {
		if (!isEmpty()) {
			for (int n : lst) {
				if (n == value) {
					return true;
				}
			}
		}
		return false;
	}
	void Set::add(int value) {
		if (!isExist(value)) {
			lst.push_front(value);
		}
	}
	int Set::getLength() {
		if (isEmpty()) {
			return 0;
		}
		return lst.size();
	}
	std::string Set::toString(char separate) {
		std::string s;
		if (!isEmpty()) {
			int last = lst.back();
			for (int n : lst) {
				s += (n != last) ? std::to_string(n) + separate : std::to_string(n);
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
		for (int n : lst) {
			if (!set.isExist(n)) {
				return false;
			}
		}
		return true;
	}
	Set Set::copy() {
		Set newSet;
		newSet.lst = lst;
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
		for (int n : lst) {
			newSet.add(n);
		}
		for (int n : set.lst) {
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
			for (int n : set.lst) {
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
			for (int n : lst) {
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
		lst.clear();
	}
}