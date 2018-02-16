#include <bits/stdc++.h>
using namespace std;


int main(){
	map <string,int> mp;
	string s;
	getline(cin,s);
	stringstream ss(s);
	int t;
	ss>>t;
	while(t--){
		
		while(1){
			getline(cin,s);
			if(s==""){
				break;
			}
			stringstream ss(s);
			
			string token;
			while(ss>>token){
				if(token[0]=='#'){
					token=token.substr(1);
					transform(token.begin(),token.end(),token.begin(),::tolower);
					int length=token.length();
					int j=length-1;
					while(j>=0){
						if(!isalpha(token[j])){
							length--;
						}
						else{
							break;
						}
						j--;
					}
					token=token.substr(0,length);
					mp[token]++;
				}
			}
		}
	}
	typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
	Comparator compFunctor = [](pair<string,int> a,pair<string,int> b)
								{ 
									if(a.second == b.second){
										return a.first<b.first;
									}
									return a.second>b.second;
								};
	std::set<std::pair<std::string, int>, Comparator> setOfWords(
			mp.begin(), mp.end(), compFunctor);

	for (std::pair<std::string, int> element : setOfWords){
		
		std::cout<<element.second<<" "<<element.first<<endl;
	}
	
}