#include<iostream>


int main() {
    int chislo, max_chet, count;
    max_chet = 0;
    while (true){
        std::cin >> chislo;
        if (chislo != 0) {
            if (max_chet < chislo) {
                count = 0;
                max_chet = chislo;
            }
            if (max_chet == chislo)
                count++;
        }
        else{
            std::cout << count;
            return 0;
        }
        
    }
}