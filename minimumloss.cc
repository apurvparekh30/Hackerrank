#include <bits/stdc++.h>

using namespace std;

bool mycompare(long a,long b)
{
	return a>b;
}
int main() {
	int n;
	//cin>>n;


	ifstream inFile;
    inFile.open("input.txt");
    inFile>>n;
	std::vector<long> v(n);
	map <long,int> mp;
	for(int i=0;i<n;i++){
		inFile>>v[i];
		//cin>>v[i];
		mp[v[i]] = i;
	}

	sort(v.begin(),v.end(),mycompare);
	long min = LONG_MAX;

	for(int i=0;i<n-1;i++){
		int j = i+1;
		while(mp[v[j]] < mp[v[i]] && j<n){
			j++;
		}
        if(j<n){
            long temp = v[i] - v[j];
            if(min > temp){
                min = temp;
            }
        }
		
	}
	cout<<min;
	return 0;
}