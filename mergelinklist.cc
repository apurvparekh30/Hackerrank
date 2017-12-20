#include <bits/stdc++.h>

using namespace std;

struct Node
{
 int data;
 struct Node *next;
};

int main() {


	return 0;
}

Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    
    while(headA != NULL && headB != NULL) {
        if(headA->data <= headB->data ) {
        	printf("%d -> ",headA->data);
        	headA = headA->next;
        }
        else {
        	printf("%d -> ",headB->data);
        	headB = headB->next;
        }
    }

    printf("NULL");
}