#include "Lab3.h"

using namespace lab3;
int randomInt(int min, int max) {
    return min + rand() % (max - min);
}

void print(std::string string1, Set& set) {
    std::cout << string1 << set.toString(', ') << std::endl;
}
void print(std::string string1, std::string string2) {
    std::cout << string1 << string2 << std::endl;
}
int main() {

    srand(time(nullptr));
    Set A(randomInt(6, 9), 0, 100, 6);
    Set B(randomInt(6, 9), 0, 100, 3);

    print("A: ", A);
    print("B: ", B); 
    std::cout << "powerful A " << A.getLength() << std::endl;
    std::cout << "powerful B " << B.getLength() << std::endl;
    print("A is subset of B - ", A.isSubSet(B) ? "True" : "False");
    print("A is subset of A - ", A.isSubSet(A) ? "True" : "False");
    print("A is subset of B - ", A.isSubSet(B) ? "True" : "False");
    print("A is subset of A - ", A.isSubSet(A) ? "True" : "False");
    print("A is equil B - ", A.equils(B) ? "True" : "False");
    print("A is equil A - ", A.equils(A) ? "True" : "False");
    Set comb = A.combining(B);
    print("A combinining B - ", comb);
    Set intersec = A.intersection(B);
    print("A intersection B - ", intersec);
    print("A difference B - ", A.difference(B));
    print("B difference A - ", B.difference(A));
    print("A symmetric B - ", A.symmetricDifference(B));
    print("Cleaing A...", "");
    A.clear();
    print("A: ", A);
    print("Cleaing B...", "");
    B.clear();
    print("B: ", B);

    

    std::cout << std::endl;

    return 0;
}