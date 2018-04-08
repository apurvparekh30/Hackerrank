#include <bits/stdc++.h>

using namespace std;

void printline(int len) {
	for(int i=0;i<len;i++) {
		cout<<"-";
	}
	cout<<'\n';
}

int main() {
	while(1){
		string no1,no2;
		cin>>no1>>no2;
		if(no1=="0" && no2=="0")
			break;
		vector<long long> numbers;
		vector<string> s_numbers;
		long long count=1;
		string temp=no2;
		reverse(temp.begin(),temp.end());
		int num1=stoll(no1,NULL);
		int zeros=0;
		for(auto i:temp) {
			int rem= i-'0';
			if(rem==0){
				zeros++;
			}
			else{
				long long newnumber=rem*num1;
				numbers.push_back(newnumber*count);
				long long int s_newnumber=(long long int )newnumber*pow(10,zeros);
				s_numbers.push_back(to_string(s_newnumber));
				zeros=0;	
			}
			count=count*10;
		}	
		long long sum=0;
		for(auto i:numbers) {
			sum+=i;
		}
		int len=to_string(sum).length();
		//cout<<"hello";
		string n1(len,' ');
		n1.insert(len-no1.length(),no1);
		string n2(len,' ');
		n2.insert(len-no2.length(),no2);
		cout<<n1<<'\n';
		cout<<n2<<'\n';
		printline(len);
		/*string spaces="";
		int spacelen=no2.length()-1;
		for(int i=0;i<spacelen;i++) {
			spaces+=" ";
		}*/
		int spaces=0;
		vector<string> :: iterator it=s_numbers.begin();
		zeros=0;
		for(auto i:temp) {
			if(i=='0'){
				zeros++;
			}
			else {
				string toprint(len,' ');
				int some_var=spaces-zeros;
				long long printlength=some_var+(*it).length();
				toprint.insert((len-printlength),*it);
				it++;	
				cout<<toprint<<'\n';
				zeros=0;
			}
			spaces++;
			//spacelen--;
			//spaces=spaces.substr(0,spacelen+zeros);
		}
		printline(len);
		cout<<sum<<'\n';
	}
	return 0;
}
