#include <iostream>

int main()
{
  int n, div = 2;
  std::cin >> n;
  while (n > 1)
  {
    while (n % div == 0)
    {
      std::cout << div << '\n';
      n = n / div;
    }
    div++;
  }
  return 0;
}