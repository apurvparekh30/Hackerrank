#include <bits/stdc++.h>

using namespace std;


int main() {

	int q;
	ifstream inFile;
	inFile.open("input.txt");
	inFile >>q;
	list<long> *adj;
	
	//scanf("%d",&q);
	for (int i = 0; i < q; ++i)
	{
		long n,m,clib,croad;
		long cost = 0;
		inFile >> n;
		inFile >> m;
		inFile >> clib;
		inFile >> croad;
		
		//scanf("%d %d %d %d",&n,&m,&clib,&croad);

		bool visited [n+1];
		adj = new list<long>[100000];
		memset(visited,false,sizeof(visited));

		for (long j = 0; j < m; ++j)
		{
			long city1;
			long city2;
			inFile >> city1;
			inFile >> city2;
			//scanf("%d %d",&city1,&city2);
			

			adj[city1].push_back(city2);
			adj[city2].push_back(city1);
		}

		if(clib <= croad) {
			cost = n * clib;
			printf("%ld\n",cost);
			//printf("0\n");
			continue;
		}
		long k;
		for(k = 1; k<=n /*&& !visited[k]*/; k++) {
		
			if(visited[k] == false) {
				long nodeCount = 1;
				stack <long> st;
				st.push(k);
				visited[k] = true;
				while(!st.empty()) {
					long temp = st.top();
					st.pop();
					
					list<long>::iterator it;
				    for(it = adj[temp].begin(); it != adj[temp].end(); ++it)
				        if(!visited[*it]) {
				        	st.push(*it);
				        	visited[*it] = true;
				        	nodeCount++;
				        }
				}
				cost = cost + clib + croad * (nodeCount - 1);
			}
			
		}

		printf("%ld\n",cost);
		
	}

	inFile.close();
	return 0;
}