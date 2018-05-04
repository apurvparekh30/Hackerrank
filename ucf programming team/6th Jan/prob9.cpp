#include <bits/stdc++.h>

using namespace std;

string getResult(string s1,string s2) {
	if(s1.length() != s2.length())
		return "NO";

	s1.append(s1);
	string s3 = s1;
	reverse(s3.begin(),s3.end());
	std::string::size_type n = s1.find(s2);
	std::string::size_type m = s3.find(s2);
	if(n == std::string::npos && m == std::string::npos){
		return "NO";
	}
	return "YES";
}

int main() {

	string s1,s2;
	int c;
	cin>>c;

	for(int i=1;i<=c;i++){
		cin>>s1>>s2;
		cout<<"Case #"<<i<<": "<<getResult(s1,s2)<<endl;
	}
	return 0;
}