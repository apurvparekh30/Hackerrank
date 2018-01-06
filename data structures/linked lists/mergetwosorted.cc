/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    
    Node *newList = NULL;
	Node *temp = newList;
    
    while(1) {
        if(headA == NULL) {
            while(headB != NULL) {
                if(temp == NULL) {
                    temp = new Node();
                    temp->data = headB->data;
                    temp->next = NULL;
                    newList = temp;
                }
                else {
                    Node *newNode = new Node();
                    newNode->data = headB->data;
                    newNode->next = NULL;
                    temp->next = newNode;
                    temp = temp->next;
                }
                headB = headB->next;
            }
            break;
        }
        if(headB == NULL) {
            while(headA != NULL) {
                if(temp == NULL) {
                    temp = new Node();
                    temp->data = headA->data;
                    temp->next = NULL;
                    newList = temp;
                }
                else {
                    Node *newNode = new Node();
                    newNode->data = headA->data;
                    newNode->next = NULL;
                    temp->next = newNode;
                    temp = temp->next;
                }
                headA = headA->next;
            }
            break;
        }
        
        if(headA->data <= headB->data && headA!=NULL ) {
        	if(temp == NULL) {
        		temp = new Node();
        		temp->data = headA->data;
        		temp->next = NULL;
        		newList = temp;
        	}
        	else {
        		Node *newNode = new Node();
        		newNode->data = headA->data;
        		newNode->next = NULL;
        		temp->next = newNode;
                temp = temp->next;
        	}
            headA = headA->next;
        }
        else {
        	if(temp == NULL) {
        		temp = new Node();
        		temp->data = headB->data;
        		temp->next = NULL;
        		newList = temp;
        	}
        	else {
        		Node *newNode = new Node();
        		newNode->data = headB->data;
        		newNode->next = NULL;
        		temp->next = newNode;
                temp = temp->next;
        	}
            headB = headB->next;
        }
    }
    return newList;
}
