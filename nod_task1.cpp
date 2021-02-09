#include<iostream>


int main(void) {
    int delimoe, delitel, nod;
    std::cin >> delimoe >> delitel;
    while (delitel) {
	nod = delimoe % delitel;
	delimoe = delitel;
	delitel = nod;
    }
std::cout << delimoe;
}