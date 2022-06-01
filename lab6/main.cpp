#include "lab6.h"

using namespace std;

int main() {
	system("color F0");
	Benchmarck benchmarck(2000);
	benchmarck.RunSetOnPointers();
	benchmarck.RunSetOnClass();
	benchmarck.RunSetOnList();
	benchmarck.RunSetOnSet();

	cout << "+----------+------------+-------------+-----------+----------+" << endl;
	cout << "|   name   | list(func) | list(class) | list(std) | set(std) |" << endl;
	cout << "+----------+------------+-------------+-----------+----------+" << endl;
	cout << "|  create  |  " << benchmarck.SetOnPointers.create_time << "  | " << benchmarck.SetOnClass.create_time << "  |  " << benchmarck.SetOnList.create_time << " |  " << benchmarck.SetOnSet.create_time << "  |";


	return 0;
}
