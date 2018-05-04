/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
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
    
  for(int i =0;i<count;i++)
      printf("%d\n",arr[i]);
 
}
