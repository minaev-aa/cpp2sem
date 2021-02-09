#include <iostream>
#include <string>

int main() {
    int speed;
    char num1, num2, num3;
    char let1, let2, let3;
    int pay;
    pay = 0;
    std::string car;
    while(true){
        std::cin >> speed >> car;
        let1 = car[0];
        num1 = car[1];
        num2 = car[2];
        num3 = car[3];
        let2 = car[4];
        let3 = car[5];     
        if (let1 == 'A' && let2 == 'A' && let3 == 'A' && num1 == '9' && num2 == '9' && num3 == '9'){
            std::cout << pay;
            return 0;
        }
        if (speed > 60){
            if (num1 == num2 && num2 == num3)
                pay += 1000;
            else if (num1 == num2 || (num1 == num3) || (num2 == num3))
                pay += 500;
            else
                pay += 100;
        }   
        
    }
}