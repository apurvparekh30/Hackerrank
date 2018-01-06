/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head == NULL) 
        return 0;
    if(head->next == NULL)
            return 0;
    if(head->next->next == NULL)
            return 0;
    Node *slow,*fast;
    slow = fast = head;
    slow = head->next;
    fast = head->next->next;
    while(fast->next->next != NULL) {
        if(slow == fast) {
            return 1;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}

