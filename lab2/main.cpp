#include "Lab2.h"


int main() {

    Node* A = createSet(5, 0, 40, 6);
    Node* B = createSet(5, 0, 40, 3);

    std::cout << "a set of A is: " << toString(A, ',') << std::endl;
    std::cout << "a set of B is: " << toString(B, ',') << std::endl;
    std::cout << "size the set of A is: " << getLength(A) << std::endl;
    std::cout << "size the set of B is: " << getLength(B) << std::endl;
    std::cout << "deleting sets  A and  B ..." << std::endl;
    clear(A);
    clear(B);
    std::cout << "a set of A after deleted is: " << toString(A, ',') << std::endl;
    std::cout << "a set of B after deleted is: " << toString(B, ',') << std::endl;

    std::cout << std::endl;

    return 0;
}