#include "Lab2.h"

int randomInt(int min, int max) {
    return min + rand() % (max - min);
}

void print(std::string string1, Node* set) {
    std::cout << string1 << toString(set, ', ') << std::endl;
}
void print(std::string string1, std::string string2) {
    std::cout << string1 << string2 << std::endl;
}
int main() {

    Node* A = createSet(randomInt(6, 9), 0, 100, 6);
    Node* B = createSet(randomInt(6, 9), 0, 100, 3);

    print("A: ", A);
    print("B: ", B);
    print("A is subset of B - ", isSubSet(A, B) ? "True" : "False");
    print("A is subset of A - ", isSubSet(A, A) ? "True" : "False");
    print("A is equil B - ", equils(A, B) ? "True" : "False");
    print("A is equil A - ", equils(A, A) ? "True" : "False");
    print("A combinining B - ", combining(A, B));
    print("A intersection B - ", intersection(A, B));
    print("A difference B - ", difference(A, B));
    print("B difference A - ", difference(B, A));
    print("A symmetric B - ", symmetricDifference(A, B));
    

    std::cout << std::endl;

    return 0;
}