#include <iostream>

using namespace std;

int dotProduct(int* vec1, int* vec2, int size) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

int main() {
    int vec1A[] = {8, 16, 32};
    int vec2A[] = {5, 9, 13};
    int sizeA = sizeof(vec1A) / sizeof(vec1A[0]);
    int resultA = dotProduct(vec1A, vec2A, sizeA);
    cout << "Dot Product of [8, 16, 32] and [5, 9, 13] = " << resultA << endl;
    int vec1B[] = {3, 8};
    int vec2B[] = {11, 22};
    int sizeB = sizeof(vec1B) / sizeof(vec1B[0]);
    int resultB = dotProduct(vec1B, vec2B, sizeB);
    cout << "Dot Product of [3, 8] and [11, 22] = " << resultB << endl;
    return 0;
}
