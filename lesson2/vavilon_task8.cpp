#include <iostream>
#include <string>

int main() {
    int chislo, del, cel, ost;
    std::string itog, temp;
    itog = "";
    temp = "";
    std::cin >> chislo;
    cel = chislo;
    del = 60;
    
    while(chislo != 0){
        ost = chislo % del;
        chislo = chislo / del;
        while (true){
            for (int i = 0; i < (ost / 10); i++)
                temp += "<";
            for (int i = 0; i < (ost % 10); i++)
                temp += "v";
            break;
        }
        if (chislo != cel)
            temp += ".";
        temp += itog;
        itog = temp;
        temp = "";
    }
    itog.erase(itog.length() - 1);
    std::cout << itog;
    return 0;
}