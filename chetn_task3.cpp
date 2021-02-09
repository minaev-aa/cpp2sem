#include<iostream>


int main() {
    int chislo, count;
    count = 0;
    while (true){
        std::cin >> chislo;
        if (chislo % 2 == 0 && chislo != 0) {
            count++;
        }
        if (chislo == 0){
            std::cout << count;
            return 0;
        }
        
    }
}