#include "courseWork.h"

using namespace std;

int main() {
	setlocale(0, "");
	// system("color F0");
	const int N = 299;

	Benchmarck<N> benchmarck;
	benchmarck.RunSetOnPointers();
	benchmarck.RunSetOnClass();
	benchmarck.RunSetOnList();
	benchmarck.RunSetOnSet();
	benchmarck.RunSetOnBitset();

	cout << benchmarck.GetTable();

	return 0;
}
