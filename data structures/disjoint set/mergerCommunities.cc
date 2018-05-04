#include <bits/stdc++.h> 

using namespace std;

map<int,int>mymap;

int getParent(int i,int parent[]){
	/*if(i == parent[i]){
		return i;
	}
	else {
		int result = getParent(parent[i],parent);
		parent[i] = result;
		return result;
	}*/
	while(parent[i]!=i){
		i = parent[i];
	}
	return i;
}

void setParent(int g,int b,int parent[]) {
	int gp = getParent(g,parent);
	int bp = getParent(b,parent);
	if(gp == bp)
		return;
	if(gp > bp){
		parent[bp] = gp;
		mymap[gp]+=mymap[bp];
	}
	else {
		parent[gp] = bp;
		mymap[bp]+=mymap[gp];
	}
}

int main() {

	int n,q;

	ofstream outfile;
	outfile.open("output.txt");

    ifstream inFile;
    inFile.open("input.txt");
    inFile>>n;
    inFile>>q;
	//cin >>n>>q;


	int parent[n+1];
	for(int i=1;i<=n;i++) {
		parent[i]=i;
		mymap[i]=1;
	}
	for(int i=0;i<q;i++) {
		char ch;
		inFile>>ch;
		//cin>>ch;
		if(ch == 'M'){
			int g,b;
			inFile>>g;
			inFile>>b;
			//cin>>g>>b;
			setParent(g,b,parent);
		}
		else {
			int g;
			inFile>>g;
			//cin>>g;
			
			outfile<<mymap[getParent(g,parent)]<<endl;
			//cout<<mymap[getParent(g,parent)]<<endl;
		}
		
	}
	return 0;
}

