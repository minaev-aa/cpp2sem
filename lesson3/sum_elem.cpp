#include <iostream>

int main() {
    int n, sum, temp, itog;
    itog = 0;
    sum = 0;
    float average;
    std::cin >> n;
    int *chisla = new int[n];
    
    for (int i = 0; i < n; i++) {
            std::cin >> temp;
            chisla[i] = temp;
            sum += temp;
        }
    average = sum / n;
    for (int i = 0; i < n; i++) {
        if (chisla[i] > average)
            itog += chisla[i];
        }
    std::cout << itog;
    delete [] chisla;
    return 0;
}