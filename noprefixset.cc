#include <bits/stdc++.h>
using namespace std;

struct tree;

struct edge
{
	tree *c = NULL;
};

struct tree {
	bool isleaf = false;
	edge *e = new edge[10];
	int count = 0;
	int noStrings = 0;
};

int main() {
    tree *root = new tree();
    tree * temp;
	int n;
	cin>>n;
	while(n--){
			string name;
			cin>>name;
			int len = name.length();
			tree *r = root;
			int i;
			for(i=0;i<len;i++) {
				if(r->isleaf){
					cout<<"BAD SET"<<endl;
					cout<<name;
					return 0;
				}
				if(r->e[name[i] - 97].c == NULL) {
					temp = new tree();
					r->e[name[i] - 97].c = temp;
				}
				r->noStrings++;
				r = r->e[name[i] - 97].c;
				
			}
			r->isleaf = true;
			r->count++;
			if(r->count > 1 || r->noStrings > 0) {
				cout<<"BAD SET"<<endl;
				cout<<name;
				return 0;
			}
	}  
	cout<<"GOOD SET";
    return 0;
}
