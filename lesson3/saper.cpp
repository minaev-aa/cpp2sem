#include <iostream>
#include <vector>

int main() {
  int str, stolb, count, x, y;
  std::cin >> str >> stolb >> count;
  std::vector <std::vector <int> > tabl(str, std::vector <int> (stolb) );
	for (int i = 0; i < str; i++)
	{
	   for (int j = 0; j < stolb; j++)
	   {
		  tabl[i][j] = 0;
	   }
	}

 while(count > 0){
    std::cin >> x >> y;
	x -= 1;
	y -= 1;
	count--;
    tabl[x][y] = -1;
    if(x+1 < str  && y+1 < stolb ){
		if(tabl[x+1][y+1] != -1)
			tabl[x+1][y+1] = tabl[x+1][y+1] + 1;
	}

    if(x+1 < str){
		if(tabl[x+1][y] != -1)
		 tabl[x+1][y] =tabl[x+1][y] + 1;
	}

    if(y+1 < stolb){
		if(tabl[x][y+1] != -1)
			tabl[x][y+1] = tabl[x][y+1] + 1;
	}

    if(x-1 < str && y+1 < stolb && x-1 >= 0){
		if(tabl[x-1][y+1] != -1)
			tabl[x-1][y+1] =tabl[x-1][y+1] + 1;
	}

    if(x+1 < str && y-1 < stolb && y-1 >= 0){
		if(tabl[x+1][y-1] != -1)
			tabl[x+1][y-1] = tabl[x+1][y-1] + 1;
	}

    if(x-1 < str && x-1 >= 0){
		if(tabl[x-1][y] != -1)
			tabl[x-1][y] = tabl[x-1][y] + 1;
	}

    if(y-1 < stolb && y-1 >= 0){
		if(tabl[x][y-1] != -1)
			tabl[x][y-1] = tabl[x][y-1] + 1;
	}

    if(x-1 < str && y-1 < stolb && x-1 >= 0 && y-1 >= 0){
		if(tabl[x-1][y-1] != -1)
			tabl[x-1][y-1] = tabl[x-1][y-1] + 1;
	}
  }
  for (int i = 0; i < str; i++)
    {
      for (int j = 0; j < stolb; j++)
      {
        std::cout<<tabl[i][j]<<" ";
      }
      std::cout<< std::endl;
    }
  tabl.clear();
  return 0;
}
