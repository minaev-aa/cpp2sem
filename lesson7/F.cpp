#include <iostream>
#include <list>
#include <math.h>

int main()
{
	double n;
	int y = 0;
    char oper;
	int nomer;
    std::list <int> vec;
	std::list <int> vecout;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> oper;

		if(oper == '+')
		{
			 std::cin >> nomer;
			 vec.push_back(nomer);
		}
		if(oper == '*')
		{
			std::cin >> nomer;
			
			std::list<int>::iterator it = vec.begin();
			if (vec.size() % 2 == 1)
				std::advance(it, 1 + std::distance(vec.begin(), vec.end())/2);
			else
				std::advance(it, std::distance(vec.begin(), vec.end())/2);
			vec.insert(it, nomer);
		}
		if(oper == '-')
		{
			y++;
			vecout.push_back(vec.front());
			vec.pop_front();
		}
		
    }
	int ik = vecout.size();
	for(int i = 0; i < ik; i++)
	{
		std::cout << vecout.front() << std::endl;
		vecout.pop_front();
	}
     return 0;
}
