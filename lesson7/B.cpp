#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    int n, x, k;
    k = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> x;
        if(x % 7 == 0)
        {
            if(x / 1000 != 7 && x / 1000 != 1)
                {
                    v.push_back(x);
                    k++;
                    
                }

        }
        if(x % 4 == 0)
        {
            if(x / 1000 != 4 && x / 1000 != 5)
                {
                    v.push_back(x);
                    k++;
                    
                }
        }
        if(x % 9 == 0)
        {
            if(x / 1000 != 9 && x / 1000 != 8)
                {
                    v.push_back(x);
                    k++;
                    
                }
        }
        int y = v.size();

		if(y>2){
        if (v.back() == v[y-2])
            v.pop_back();
			if (v.back() == v[y-3])
				v.pop_back();
		}
		if(y == 2)
		{
			if (v.back() == v[y-2])
            v.pop_back();
		}
      
    }
        if(k == 0)
            std::cout << 0 << "\n";
		else
		{
			for(int l = 0; l < v.size(); l++)
				std::cout << v[l] << "\n";
		}
	return 0;
}