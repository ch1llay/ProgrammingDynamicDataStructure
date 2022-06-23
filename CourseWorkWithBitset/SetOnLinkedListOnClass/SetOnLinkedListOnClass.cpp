#include "SetOnLinkedListOnClass.h"

namespace SetOnLinkedListOnClass {
	Set::Set()
	{
		start = new Node();
		start->next = nullptr;
	}

	Set::Set(Set&& set)
	{
		start = set.start;
		set.start = nullptr;
	}


	bool Set::isEmpty()
	{
		return start == nullptr;
	}

	bool Set::isExist(int value)
	{
		if (!isEmpty()) {
			for (Node* ptr = start->next; ptr; ptr = ptr->next) {
				if (value == ptr->value) {
					return true;
				}
			}
		}
		return false;
	}
	void Set::add(int value)
	{
		if (!isExist(value)) {
			start->value = value;
			Node* newStart = new Node;
			newStart->next = start;
			start = newStart;
		}
	}


	Set::Set(int amount, int min, int max, int div)
	{
		start = new Node();
		start->next = nullptr;
		int elem;
		Node* oldStart = start;
		for (int i = 0; i < amount;) {
			elem = min + rand() % (max - min);
			if (elem % div == 0) {
				add(elem);
				if (oldStart != start) {
					i++;
				}
				oldStart = start;
			}

		}
	}
	Set::Set(int amount, int min, int max)
	{
		start = new Node();
		start->next = nullptr;
		int elem;
		Node* oldStart = start;
		for (int i = 0; i < amount;) {
			elem = min + rand() % (max - min);
			add(elem);
			if (oldStart != start) {
				i++;
			}
			oldStart = start;

		}
	}

	int Set::getLength()
	{
		if (isEmpty()) {
			return 0;
		}
		int size = 0;
		for (Node* ptr = start->next; ptr; ptr = ptr->next) {
			size++;
		}
		return size;

	}

	std::string Set::toString(char separate)
	{
		std::string s = "";
		for (Node* ptr = start->next; ptr;) {
			s += std::to_string(ptr->value);
			if (ptr->next) {
				s += separate;

			}
			ptr = ptr->next;
		}
		return s;
	}

	Set::~Set()
	{
		if (isEmpty()) {
			return;
		}
		Node* temp;
		for (Node* ptr = start->next; ptr;) {
			if (ptr->next) {
				temp = ptr;
				ptr = ptr->next;
				temp->next = nullptr;
				delete temp;
			}
			else {
				break;
			}
		}
		start->next = nullptr;
		start->value = INT_MAX;
		return;
	}

	bool Set::isSubSet(Set& set)
	{
		if (isEmpty()) {
			return true;
		}
		if (getLength() > set.getLength()) {
			return false;
		}
		for (Node* ptr = start->next; ptr; ptr = ptr->next) {
			if (!set.isExist(ptr->value)) {
				return false;
			}
		}
		return true;

	}

	bool Set::equils(Set& set)
	{
		return isSubSet(set) && set.isSubSet(*this);
	}

	Set Set::combining(Set& set)
	{
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
		for (Node* ptr = start->next; ptr; ptr = ptr->next) {
			newSet.add(ptr->value);
		}
		for (Node* ptr = set.start->next; ptr; ptr = ptr->next) {
			newSet.add(ptr->value);
		}
		return newSet;

	}

	Set Set::copy() {
		Set newSet;
		for (Node* ptr = start->next; ptr; ptr = ptr->next) {
			newSet.add(ptr->value);
		}
		return newSet;
	}

	Set Set::intersection(Set& set)
	{
		Set newSet;

		if (isEmpty() || set.isEmpty()) {
			return newSet;
		}
		else {
			for (Node* ptr = set.start->next; ptr; ptr = ptr->next) {
				if (isExist(ptr->value)) {
					newSet.add(ptr->value);
				}
			}
			return newSet;
		}
	}

	Set Set::difference(Set& set)
	{
		Set newSet;
		if (isEmpty()) {
			return newSet;
		}
		else if (set.isEmpty()) {
			return newSet;
		}
		else {
			for (Node* ptr = start->next; ptr; ptr = ptr->next) {
				if (!set.isExist(ptr->value)) {
					newSet.add(ptr->value);
				}
			}
			return newSet;
		};
	}

	Set Set::symmetricDifference(Set& set)
	{
		Set combiningSet = combining(set);
		Set intersectionSet = intersection(set);
		Set newNode = combiningSet.difference(intersectionSet);
		return newNode;
	}

	void Set::clear()
	{
		if (isEmpty()) {
			return;
		}
		Node* temp;
		for (Node* ptr = start->next; ((ptr) && (ptr)->value != INT_MAX);) {
			if (ptr->next) {
				temp = ptr;
				ptr = ptr->next;
				temp->next = nullptr;
				temp->value = INT_MAX;
				delete temp;
			}
			else {
				break;
			}
		}
		start->next = nullptr;
		start->value = INT_MAX;
	}
}
