/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    
    if(head == NULL) {
        head = new Node();
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
        return head;
    }
    else {
        
        if(head->data > data){
            Node *temp = new Node();
            temp->data = data;
            temp->next = head;
            head->prev = temp;
            temp->prev = NULL;
            head = temp;
            return head;
        }
        Node *it = head;
        while(it->next!=NULL) {
            if(it->next->data < data)
                it=it->next;
            else break;
        }
        Node *temp = new Node();
        temp->data = data;
        temp->next = it->next;
        temp->prev = it;
        it->next = temp;
    }
    return head;
}
