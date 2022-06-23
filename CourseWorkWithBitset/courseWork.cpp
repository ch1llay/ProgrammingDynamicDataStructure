#include "courseWork.h"

using namespace std;

bool isNotNegativeNumber(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
int main() {
	setlocale(0, "");
	system("color F0");

	
	cout << "������� �������� ��������� " << endl;
	
	string powerSetStr;
	for (;;) {
		cin >> powerSetStr;
		if (isNotNegativeNumber(powerSetStr)) {
			break;
		}
		else {
			cout << "������� �������� ������" << endl;
		}
	}
	
	int n = stol(powerSetStr);
	const int N = 100;
	
	if (N == n) {

		Benchmarck<N> benchmarck;
		benchmarck.RunSetOnPointers();
		benchmarck.RunSetOnClass();
		benchmarck.RunSetOnList();
		benchmarck.RunSetOnSet();
		benchmarck.RunSetOnBitset();

		cout << benchmarck.GetTable();
	}

	return 0;
}



