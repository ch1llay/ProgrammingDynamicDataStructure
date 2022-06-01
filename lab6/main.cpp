#include "lab6.h"

using namespace std;

int main() {
	system("color F0");
	Benchmarck benchmarck(2000);
	benchmarck.RunSetOnPointers();
	benchmarck.RunSetOnClass();
	benchmarck.RunSetOnList();
	benchmarck.RunSetOnSet();

	cout << benchmarck.GetTable();

	return 0;
}
