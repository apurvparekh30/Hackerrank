#include <bits/stdc++.h>
using namespace std;

struct node {
	char data;
	node *left=NULL;
	node *right=NULL;
};

node* newnode(char ch) {
	node *temp=new node();
	temp->data=ch;
	return temp;
}
node* build_tree(vector<char> in,vector<char> pre,int& preindex,int start,int end) {
	if(start>end)
		return NULL;
	
	char ch=pre[preindex];
	node *root=newnode(ch);

	if(start==end)
		return root;
	int pivot=(find(in.begin(),in.end(),ch) - in.begin());
	preindex++;
	root->left=build_tree(in,pre,preindex,start,pivot-1);
	preindex++;
	root->right=build_tree(in,pre,preindex,pivot+1,end);
	return root;
	
}

void postorder(node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<< " " <<root->data;
	}
}

void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		cout<<" "<<root->data; 
		inorder(root->right);
		//cout<< " " <<root->data;
	}
}


int main(){
	char i[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  	char p[] = {'A', 'B', 'D', 'E', 'C', 'F'};

	vector<char> in(i,i+sizeof(i)/sizeof(char));
	vector<char> pre(p,p+sizeof(p)/sizeof(char));
	int start=0;
	int end=in.size()-1;	
	int preindex=0;
	node* root=build_tree(in,pre,preindex,start,end);
	
	inorder(root);
	
	cout<<endl;
	return 0;
}
