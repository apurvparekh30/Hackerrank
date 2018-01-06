/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  Node *it = head;
  while(it->next != NULL) {
      if(it->next ==NULL) {
          break;
      }
      if(it->data == it->next->data) {
          Node *temp = it->next;
          it->next = temp ->next;
          delete temp;
          continue;
      }
      it = it->next;
      
  }
    
  return head;
    
}
