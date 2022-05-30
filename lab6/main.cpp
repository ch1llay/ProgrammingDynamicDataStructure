#include "lab2/lab2.h";
#include "lab3/lab3.h";
#include "lab4/lab4.h";
#include "lab5/lab5.h";
#include "lab6.h"

int main() {
	Benchmarck benchmarck(10);
	benchmarck.RunSetOnPointers();
	std::cout << benchmarck.SetOnPointers->combining_time;

	return 0;
}
