/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    if(head == NULL) {
        head = new Node();
        head->data = data;
        head->next = NULL;
    }
    else {
        Node *it = head;
        while(it->next!=NULL){
            it = it->next;
        }
        Node *temp = new Node();
        temp -> data = data;
        temp->next = NULL;
        it->next = temp;
    }
   
    
    return head;
}
