/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
    
  if(head == NULL)
       return head;
  int count = 0;
  Node *it = head;
  while(it!=NULL) {
      count++;
      it = it->next;
  }
  int arr[count];
  int j = count-1;
  it = head;
  while(it!=NULL) {
      arr[j--] = it->data;
      it = it ->next;
  } 
  j = 0;
  it = head;
  while(it!=NULL) {
      it->data = arr[j++];
      it = it ->next;
  } 
  return head;
}
