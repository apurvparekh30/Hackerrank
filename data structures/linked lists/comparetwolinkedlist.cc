/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    
  int count1 = 0;
  int count2 = 0;
  Node *it = headA;
  while (it!=NULL) {
      count1++;
      it = it ->next;
  }
    
  it = headB;
  while (it!=NULL) {
      count2++;
      it = it ->next;
  }
  if(count1 == count2)
  {
     while(headA != NULL) {
          if(headA->data != headB->data) {
                return 0;
          }
          headA = headA->next;
          headB = headB->next;
      }
       return 1;
  }  
  return 0;
}
