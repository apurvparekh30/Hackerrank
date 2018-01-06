/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    for(Node *it=headA;it!=NULL;it=it->next){
        for(Node *t = headB; t!=NULL;t=t->next){
            if(t == it) {
                return t->data;
            }
        }
    }
    return 0;
}
