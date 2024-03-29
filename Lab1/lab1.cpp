#include "Lab1.h"

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

