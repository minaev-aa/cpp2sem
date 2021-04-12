#include <iostream>

      int n;  
     int d;  
     int r; 
int main()
{
 
	 std::cin >> n;
     d = 2;  
	 r = n % d;
     if (r != 0) d++;
	 while ( r != 0) {
        r = n % d;
        if (r != 0) d++;
     }

     if (d == n)
       std::cout << 1;
     else  
		 std::cout << 0;
 
   return 0;
}