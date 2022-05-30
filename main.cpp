#include "lab6.h"

int main() {
	system("color F0");
	Benchmarck benchmarck(2000);
	benchmarck.RunSetOnPointers();
	benchmarck.RunSetOnClass();
	benchmarck.RunSetOnList();
	benchmarck.RunSetOnSet();
	std::cout << benchmarck.SetOnPointers.combining_time << std::endl;
	std::cout << benchmarck.SetOnClass.combining_time << std::endl;
	std::cout << benchmarck.SetOnList.combining_time << std::endl;
	std::cout << benchmarck.SetOnSet.combining_time << std::endl;

	return 0;
}
