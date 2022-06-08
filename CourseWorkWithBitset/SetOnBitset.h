#include <bitset>


class Set {
	bitset& set;
	
public:
	Set();
	Set(Set&& set);
	Set(int amount) {
		N = amount;
		bitset<amount> set;
	}
	~Set();
	bool isEmpty() {
	}
	bool isExist(int value);
	void add(int value);
	int getLength();
	std::string toString(char separate);

	bool isSubSet(Set& set);
	bool equils(Set& set);
	Set combining(Set& set);
	Set intersection(Set& set);
	Set difference(Set& set);
	Set symmetricDifference(Set& set);
	void clear();
private:
	Set copy();
};