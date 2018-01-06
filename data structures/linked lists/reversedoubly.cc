/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
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
