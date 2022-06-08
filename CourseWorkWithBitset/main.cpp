#include "courseWork.h"

using namespace std;

int main() {
	setlocale(0, "");
	system("color F0");
	Benchmarck benchmarck(2000);
	benchmarck.RunSetOnPointers();
	benchmarck.RunSetOnClass();
	benchmarck.RunSetOnList();
	benchmarck.RunSetOnSet();
	benchmarck.RunSetOnBitset();

	cout << benchmarck.GetTable();

	return 0;
}
