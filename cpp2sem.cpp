// cpp2sem.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
# include <iostream>
#include <cmath>

void stars(int count){
	for (int i = 0; i < count; i++) {
		std::cout << "*";
	}
}

int main(){
	//задание 1
	std::cout << "Hello, World!" << std::endl;
	std::cout << "mipt" << 2016 << '.' << true << std::endl;
	//задание 2
	double katet1, katet2;
	std::cin >> katet1;
	std::cin >> katet2;
	std::cout << sqrt((katet1 * katet1) + (katet2 * katet2)) << std::endl;
	//задание 3
	int amount_stars;  // оличество звЄздочек
	std::cin >> amount_stars;
	for (int n = 0; n < amount_stars; n++) {
		stars(amount_stars);
		std::cout << std::endl;
	}

	std::cout << std::endl;
	//задание 4
	for (int n = 0; n < amount_stars; n++) {
		stars(n);
		std::cout << std::endl;
	}

	std::cout << std::endl;
	//задание 5
	for (int n = 0; n < amount_stars; n++) {
		stars(amount_stars-n);
		std::cout << std::endl;
	}

	std::cout << std::endl;
	//задание 6
	for (int n = 0; n < amount_stars; n += 2) {
		stars(amount_stars-n);
		std::cout << std::endl;
		for (int a = 0; a <= n; a += 2){
			std::cout << " ";
		}
	}

	system("pause");
	return 0;
}

