/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    if(position == 0) {
        head = head -> next;
        return head;
    }
    int i =0;
    Node *it = head;
    while(i< position-1){
        it = it ->next;
        i++;
    }   
    Node *temp = it->next;
    it->next = temp->next;
    delete temp;
    return head;
}
