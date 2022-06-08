#include <bitset>

using namespace std;

int main() {
	const int N = 10;
	system("color F0");
	bitset<N> set;
	set.flip(1);
	/*Benchmarck benchmarck(2000);
	benchmarck.RunSetOnPointers();
	benchmarck.RunSetOnClass();
	benchmarck.RunSetOnList();
	benchmarck.RunSetOnSet();

	cout << benchmarck.GetTable();*/

	return 0;
}
