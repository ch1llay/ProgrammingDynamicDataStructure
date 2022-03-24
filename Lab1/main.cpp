#include "Lab1.h"


int randomInt(int min, int max) {
    return min + rand() % (max - min);
}
int main() {

    Node* A = createSet(randomInt(6, 9), 0, 40, 6);
    Node* B = createSet(randomInt(6, 9), 0, 40, 3);

    std::cout << "A: " << toString(A, ',') << std::endl;
    std::cout << "B: " << toString(B, ',') << std::endl;
    std::cout << "size A: " << getLength(A) << std::endl;
    std::cout << "size B: " << getLength(B) << std::endl;
    std::cout << "deleting sets  A and  B ..." << std::endl;
    clear(A);
    clear(B);
    std::cout << "A after deleted is: " << toString(A, ',') << std::endl;
    std::cout << "B after deleted is: " << toString(B, ',') << std::endl;

    std::cout << std::endl;

    return 0;
}