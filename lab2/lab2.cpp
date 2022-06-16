#include "Lab2.h"

namespace lab2 {
	Node* createEmptySet(void)
	{
		Node* start = new Node;
		start->next = nullptr;
		start->value = INT_MAX;
		return start;
	}

	bool isEmpty(Node* start)
	{
		return start == nullptr;
	}

	bool isExist(Node* start, int value)
	{
		if (!isEmpty(start)) {
			for (Node* ptr = start; ptr; ptr = ptr->next) {
				if (value == ptr->value) {
					return true;
				}
			}
		}
		return false;
	}

	Node* add(Node* start, int value)
	{
		if (!isExist(start, value)) {
			Node* newStart = new Node;
			newStart->value = value;
			newStart->next = start;
			return newStart;
		}
		else {
			return start;
		}
	}

	Node* createSet(int amount, int min, int max, int div)
	{
		Node* start = createEmptySet();
		int elem;
		Node* oldStart = start;
		for (int i = 0; i < amount;) {
			elem = min + rand() % (max - min);
			if (elem % div == 0) {
				start = add(start, elem);
				if (oldStart != start) {
					i++;
				}
				oldStart = start;
			}
		}
		return start;
	}
	Node* createSet(int amount, int min, int max)
	{
		Node* start = createEmptySet();
		int elem;
		Node* oldStart = start;
		for (int i = 0; i < amount;) {
			elem = min + rand() % (max - min);
			start = add(start, elem);
			if (oldStart != start) {
				i++;
			}
			oldStart = start;
		}
		return start;
	}

	int getLength(Node* start)
	{
		if (isEmpty(start)) {
			return 0;
		}
		int size = 0;
		for (Node* ptr = start; ptr; ptr = ptr->next) {
			size++;
		}
		return size;

	}

	std::string toString(Node* start, char separate)
	{
		std::string s = "";
		for (Node* ptr = start; ((ptr) && (ptr)->value != INT_MAX); ptr = ptr->next) {
			s += std::to_string(ptr->value);
			if (ptr->next) {
				s += separate;

			}
		}
		return s;
	}

	Node* clear(Node* start)
	{
		if (isEmpty(start)) {
			return start;
		}
		Node* temp;
		for (Node* ptr = start->next; ptr;) {
			if (start->next) {
				temp = ptr;
				ptr = ptr->next;
				temp->next = nullptr;
				temp->value = INT_MAX;
				delete temp;
			}
		}
		start->next = nullptr;
		start->value = INT_MAX;
		return start;
	}

	bool isSubSet(Node* subset, Node* set)
	{
		if (isEmpty(subset)) {
			return true;
		}
		if (getLength(subset) > getLength(set)) {
			return false;
		}
		for (Node* ptrSubset = subset; ptrSubset; ptrSubset = ptrSubset->next) {
			if (!isExist(set, subset->value)) {
				return false;
			}
		}
		return true;

	}

	bool equils(Node* set1, Node* set2)
	{
		return isSubSet(set1, set2) && isSubSet(set2, set1);
	}

	Node* combining(Node* set1, Node* set2)
	{
		Node* newSet = createEmptySet();

		if (isEmpty(set1) && isEmpty(set2)) {
			return newSet;
		}
		if (isEmpty(set1)) {
			return copy(set2);
		}
		else if (isEmpty(set2)) {
			return copy(set1);
		}
		for (Node* ptr = set1; ptr; ptr = ptr->next) {
			newSet = add(newSet, ptr->value);
		}
		for (Node* ptr = set2; ptr; ptr = ptr->next) {
			newSet = add(newSet, ptr->value);
		}
		return newSet;

	}
	Node* copy(Node* set) {
		Node* newSet = createEmptySet();
		for (Node* ptr = set; ptr; ptr = ptr->next) {
			newSet = add(newSet, ptr->value);
		}
		return newSet;
	}
	Node* intersection(Node* set1, Node* set2)
	{
		Node* newSet = createEmptySet();

		if (isEmpty(set1) || isEmpty(set2)) {
			return newSet;
		}
		else {
			for (Node* ptr = set2; ptr; ptr = ptr->next) {
				if (isExist(set1, ptr->value)) {
					newSet = add(newSet, ptr->value);
				}
			}
			return newSet;
		}
	}

	Node* difference(Node* set1, Node* set2)
	{
		Node* newSet = createEmptySet();
		if (isEmpty(set1)) {
			return newSet;
		}
		else if (isEmpty(set2)) {
			return newSet;
		}
		else {
			Node* newSet = createEmptySet();
			for (Node* ptr = set1; ptr; ptr = ptr->next) {
				if (!isExist(set2, ptr->value)) {
					newSet = add(newSet, ptr->value);
				}
			}
			return newSet;
		};
	}

	Node* symmetricDifference(Node* set1, Node* set2)
	{
		Node* combiningSet = combining(set1, set2);
		Node* intersectionSet = intersection(set1, set2);
		Node* newNode = difference(combiningSet, intersectionSet);
		return newNode;
	}
}

