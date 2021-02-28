#include<iostream>


int main() {
    int chislo;
    std::cin >> chislo;
    while (true) {
        if (chislo % 2 == 0 && chislo != 1) {
            chislo = chislo / 2;
        }
        if (chislo == 1){
            std::cout << "YES";
            return 0;
        }
        if (chislo % 2 == 1) {
            std::cout << "NO";
            return 0;
        }
    }      
}