#include<iostream>


int main() {
    int chislo, max_chet;
    max_chet = 0;
    while (true){
        std::cin >> chislo;
        if (chislo % 2 == 0 && chislo != 0) {
            if (max_chet < chislo)
                max_chet = chislo;
        }
        if (chislo == 0){
            std::cout << max_chet;
            return 0;
        }
        
    }
}