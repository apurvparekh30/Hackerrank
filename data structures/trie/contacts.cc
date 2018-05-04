#include <bits/stdc++.h>
using namespace std;

struct tree;

struct edge
{
	tree *c = NULL;
};

struct tree {
	bool visited = false;
	edge *e = new edge[27];
	bool isleaf = false;
	int count = 0;
};


int getCount(tree *r){
	int count = 0;
	if(r!=NULL) {
		r->visited = true;
		if(r->isleaf){
			count++;
		}
		for(int i=0;i<27;i++) {
			
			count = count + getCount(r->e[i].c);
		}
	}
	return count;
}
int main() {
    tree *root = new tree();
    tree * temp;
	int n;
	cin>>n;
	while(n--){
		string op;
		cin>>op;
		if(op[0] == 'a'){
			string name;
			cin>>name;
			int len = name.length();
			tree *r = root;
			for(int i=0;i<len;i++) {
				if(r->e[name[i] - 97].c == NULL) {
					temp = new tree();
					if(i == len-1) {
						temp->isleaf = true;
					}
					r->e[name[i] - 97].c = temp;

				}
				r = r->e[name[i] - 97].c;
				r->count++;
			}
		}
		else {
			string prefix;
			cin>>prefix;
			int len = prefix.length();
			tree *r = root;	
			int i=0;
			while(i<len && r!=NULL) {
				r=r->e[prefix[i]-97].c;
				i++;
			}
			if(r!=NULL)
				cout<<r->count<<endl;
			else 
				cout<<"0"<<endl;
			//cout<<getCount(r)<<endl;
		}
	}  
    return 0;
}
