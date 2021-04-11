#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	double n;
	int num;
    std::vector <int> vec;
	std::vector <int> minik;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> num;
		vec.push_back(num);
	}
	for(int i = 0; i < n; i++)
    {
		int in = vec[i];
		if (in < 0){
		auto x = vec.begin() + i;
		auto y = vec.end();
        std::vector<int>::iterator it = std::find(x, y, (-1)*in);
		if (it!=y){
		int q = std::distance(x, it);
		minik.push_back(q);}
		}
	}
	int minElement = 0;
	if(minik.size()>0)
		minElement = *std::min_element(minik.begin(), minik.end());
	std::cout << minElement;
    return 0;
}