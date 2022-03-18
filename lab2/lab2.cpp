#include "Lab2.h"

Node* createEmptySet(void)
{
	Node* start = new Node;
	start->next = nullptr;
	start->value = INT_MAX;
	return start;
}

bool isEmpty(Node* start)
{
	return ((start == nullptr) || (start->value == INT_MAX));
}

bool isExist(Node* start, int value)
{
	if (!isEmpty(start)) {
		for (Node* ptr = start; ((ptr) && (ptr)->value != INT_MAX); ptr = ptr->next) {
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
	for (int i = 0; i <= amount;) {
		elem = min + rand() % (max - min);
		if (elem % div == 0) {
			start = add(start, elem);
			i++;
		}
	}
	return start;
}

int getLength(Node* start)
{
	if (isEmpty(start)) {
		return 0;
	}
	int size = 0;
	for (Node* ptr = start; ((ptr) && (ptr)->value != INT_MAX); ptr = ptr->next) {
		size++;
	}
	return size;

}

std::string toString(Node* start, char separate)
{
	std::string s = "";
	for (Node* ptr = start; ((ptr) && (ptr)->value != INT_MAX);ptr = ptr->next) {
		s += std::to_string(ptr->value);
		if (ptr->next->value != INT_MAX) {
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
	for (Node* ptr = start->next; ((ptr) && (ptr)->value != INT_MAX);) {
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
	for (Node* ptrSubset = subset; ((ptrSubset) && (ptrSubset)->value != INT_MAX);ptr = ptr->next) {
		if (!isExist(set, subset->value)) {
			return false;
		}
	}
	return true;

}

bool equils(Node* set1, Node* set2)
{
	if (isSubSet(set1, set2) && isSubSet(set2, set1)) {
		return true''
	}
	else {
		return false;
	}
}

Node* combining(Node* set1, Node* set2)
{
	Node* gettedSet;
	Node* givenSet;
	if (isEmpty(set1) && isEmpty(set2)) {
		return set1;
	}
	if (isEmpty(set1)) {
		gettedSet = set1;
		givenSet = set2;
	}
	else if (isEmpty(set2)) {
		gettedSet = set2;
		givenSet = set1;
	}
	for (Node* ptr = givenSet; ((ptr) && (ptr)->value != INT_MAX);ptr = ptr->next) {
		add(gettedSet, ptr->value);
	}
	return gettedSet;

}

Node* intersection(Node* set1, Node* set2)
{
	if (isEmpty(set1) || isEmpty(set2)) {
		return set1;
	}
	else {
		Node* newSet = createEmptySet();
		for (Node* ptr1 = set1, ptr2 = set2; ((ptr1) && (ptr1)->value != INT_MAX && ((ptr2) && (ptr2)->value != INT_MAX);ptr = ptr->next) {
			if (isExist(ptr2, ptr1->value)) {
				newSet = add(newSet, ptr1->value);
			}
			if (isExist(ptr1, ptr2->value)) {
				newSet = add(newSet, ptr2->value);
			}
		}
		return newSet;
	}
}

Node* difference(Node* set1, Node* set2)
{
	if (isEmpty(set1)) {
		return set1;
	}
	else if (isEmpty(set2)) {
		return set1;
	}
	else {
		Node* newSet = createEmptySet();
		for (Node* ptr1 = set1, ptr2 = set2; ((ptr1) && (ptr1)->value != INT_MAX && ((ptr2) && (ptr2)->value != INT_MAX);ptr = ptr->next) {
			if (!isExist(ptr1, ptr2->value)) {
				newSet = add(newSet, ptr1->value);
			}
		}
		return newSet;
	};
}

Node* symmetricDifference(Node* set1, Node* set2)
{
	Node* combiningSet = combining(set1, set2);
	Node* intersectionSet = intersection(set1, set2);
	Node* newNode = difference(combining, intersectionSet);
	return newNode;
}

