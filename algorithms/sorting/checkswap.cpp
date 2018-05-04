#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v(5);
	for(int i=0;i<5;i++)
		v[i]=i;
	
	swap(v[0],v[1]);
	for(int i=0;i<5;i++)
                cout<< " "<< v[i];

}
