#include <iostream>

int main(){
	int a,b;
	std::cin>>a>>b;
	int *uka = &a;
	int *ukb = &b;
	std::cout << do_some_awesome_work(uka,ukb);
	return 0;
}