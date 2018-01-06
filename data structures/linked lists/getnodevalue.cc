/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    int count = 0;
    Node * temp;
    for(temp=head;temp!=NULL;temp=temp->next) {
        count++;
    }
    int i =0;
    count = count - positionFromTail;
    while(i<count-1) {
        head = head->next;
        i++;
    }
    return head->data;
}
