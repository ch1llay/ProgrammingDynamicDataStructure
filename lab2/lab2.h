#pragma once
#include <string>
#include <random>
#include <iostream>

typedef struct Node {
	int value = INT_MAX;
	Node* next = nullptr;
};

Node* createEmptySet(void);
bool isEmpty(Node* start);
bool isExist(Node* start, int value);
Node* add(Node* start, int value);
Node* createSet(int amount, int min, int max, int div);
int getLength(Node* start);
std::string toString(Node* start, char separate);
Node* clear(Node* start);

bool isSubSet(Node* subset, Node* set);
bool equils(Node* set1, Node* set2);
Node* combining(Node* set1, Node* set2);
Node* intersection(Node* set1, Node* set2);
Node* difference(Node* set1, Node* set2);
Node* symmetricDifference(Node* set1, Node* set2);






