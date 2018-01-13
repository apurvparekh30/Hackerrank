#include <bits/stdc++.h>

using namespace std;

void getFib(int n,list<int> t1,list<int>t2) {
	for(int i=3;i<=n;i++){
		list<int> temp((t2.size * 2)-1,0);
		int k=0;
		for(list::reverse_iterator rit=t2.rbegin();rit!=t2.rend();rit++){
			list::reverse_iterator ittemp = temp.rbegin();
			for(int l=0;l<k;l++){
				itemp++;
			}
			for(list::reverse_iterator it=t2.ittemp;it!=t2.rend();it++) {

			}

			k++;
		}
	}
}

int main() {
	int a,b,n;

	cin>>a>>b>>n;

	list<int> t1,t2;

	while(a>0){
		t1.push_front(a%10);
		a=a/10;
	}
	while(b>0){
		t2.push_front(b%10);
		b=b/10;
	}

	getFib(n,t1,t2);
	return 0;
}