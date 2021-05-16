#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>



class Graph
{
private:
	std::vector <std::vector<int>> node;
	std::vector <bool> used;
	std::vector<int> comp;
	std::vector<int> p;
public:
	bool cycle;

	Graph(int n)
	{
		cycle = false;
		node.resize(n);
		used.resize(n);
		comp.resize(n);
		p.resize(n);
		
	}

	void add(int a, int b){
		node[a].push_back(b);
		if(a!=b)
			node[b].push_back(a);
	}

	void del(int a){
		for (size_t i=0;i<node[a].size();i++){
			auto it = std::find(node[node[a][i]].begin(), node[node[a][i]].end(), a);
			node[node[a][i]].erase(it);}
		node[a].clear();
	}
	void dfs (int v) { 
	  used[v] = true; 
	  comp.push_back(v);
	  for (size_t i=0; i<node[v].size(); ++i) 
	  { 
		int to = node[v][i]; 
		if (used[to] == false){  
			p[to] = v; 
			dfs (to); 
		} 
	  else if (used[to] == 1&&to!=p[v])  
		cycle=true; 
	} 
	}
	
	void find_comps() {
		int count = 0;
		for (size_t i=0; i<node.size(); ++i)
			used[i] = false;
		for (size_t i=0; i<node.size(); ++i)
			if (!used[i]) {
				comp.clear();
				dfs (i);
				std::cout << "Comp:";
				count++;
				for (size_t j=0; j<comp.size(); ++j)
					std::cout << ' ' << comp[j];
				std::cout << std::endl;
			}
			std::cout << "Count: " << count << std::endl;
	}
	void if_cyrcle()
	{
		for (int l=0; l<node.size();++l){ 
			if (!used[l])  
				dfs(l); 
				if (cycle) { 
					std::cout<<"Yes"; 
					return;
				} 
				
		} 
	 std::cout<<"No";
	}
};
int main()
{
	Graph G(6);
	G.add(0,1);
	G.add(0,2);
	G.add(1,4);
	G.add(3,4);
	G.add(3,5);
	G.add(4,5);

	G.find_comps();
	G.if_cyrcle();
	return 0;
}


