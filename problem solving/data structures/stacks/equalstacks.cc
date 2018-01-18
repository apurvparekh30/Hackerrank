#include <bits/stdc++.h>

using namespace std;

int getSmall(int a,int b,int c) {
	if(a==b && a==c)
		return 0;

	if(a <= b && a <= c){
		return 1;
	}
	if(b <= a && b <= c){
		return 2;
	}
	if(c <= b && c <= a){
		return 3;
	}
	return 0;
}

int main () {
	int n1,n2,n3;
	scanf("%d %d %d",&n1,&n2,&n3);
	int arr1[n1],arr2[n2],arr3[n3];
	for(int i=n1-1;i>=0;i--) {
		scanf("%d",&arr1[i]);
	}
	for(int i=n2-1;i>=0;i--) {
		scanf("%d",&arr2[i]);
	}
	for(int i=n3-1;i>=0;i--) {
		scanf("%d",&arr3[i]);
	}

	stack<int> st1,st2,st3;
	int temp;
	temp = 0;
	for(int i=0;i<n1;i++){
		if(!st1.empty()) {
			temp = st1.top();
		}
		temp = temp + arr1[i];
		st1.push(temp);
	}
	temp = 0;
	for(int i=0;i<n2;i++){
		if(!st2.empty()) {
			temp = st2.top();
		}
		temp = temp + arr2[i];
		st2.push(temp);
	}
	temp = 0;
	for(int i=0;i<n3;i++){
		if(!st3.empty()) {
			temp = st3.top();
		}
		temp = temp + arr3[i];
		st3.push(temp);
	}

	bool flag = false;

	while(!flag) {
		if(st1.empty() || st2.empty() || st3.empty()){
			printf("0");
			flag = true;
			continue;
		}
		int small = getSmall(st1.top(),st2.top(),st3.top());
		if(small == 1) {
			if(st1.top() < st2.top())
				st2.pop();
			if(st1.top() < st3.top())
				st3.pop();
		}
		else if(small == 2) {
			if(st2.top() < st1.top())
				st1.pop();
			if(st2.top() < st3.top())
				st3.pop();
		}
		else if(small == 3) {
			if(st3.top() < st2.top())
				st2.pop();
			if(st3.top() < st1.top())
				st1.pop();
		} 
		else {
			printf("%d",st1.top());
			flag = true;
		}
	}
	return 0;
}