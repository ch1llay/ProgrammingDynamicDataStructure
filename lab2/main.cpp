#include "Lab2.h"

void print(std::string string1, Node* set) {
    std::cout << string1 << toString(set, ',') << std::endl;
}
void print(std::string string1, std::string string2) {
    std::cout << string1 << string2 << std::endl;
}
int main() {

    Node* A = createSet(5, 0, 40, 6);
    Node* B = createSet(5, 0, 40, 3);

    print("a set of A is: ", A);
    print("a set of B is: ", B);
    print("a is subset of B - ", isSubSet(A, B) ? "True" : "False");
    print("A is subset of B - ", isSubSet(A, B) ? "True" : "False");
    print("A is equil B - ", equils(A, B) ? "True" : "False");
    print("A intersection B - ", intersection(A, B));
    print("A difference B - ", difference(A, B));
    print("B difference A - ", difference(B, A));
    print("A symmetric B - ", difference(A, B));
    

    std::cout << std::endl;

    return 0;
}