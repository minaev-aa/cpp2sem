#include <iostream>

int main() {
    int n;
	std::cin >> n;
	int x;
    int **arr = new int*[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = new int[n];
        for(int f=0; f<n; f++)
        {
			std::cin >> x;
            arr[i][f] = x;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int f=n-1; f>=0; f--)
        {
            std::cout << arr[f][i] << " ";
        }
        std::cout << "\n";
    }
 
return 0;
}