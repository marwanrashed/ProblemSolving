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
    Node* Fast = head->next;
    Node* Slow = head;
    
    while ((Fast != nullptr) && (Fast->next != nullptr) && (Slow != nullptr)) {
        if (Fast == Slow) {
            return true;
        }        
        Fast = Fast->next->next;
        Slow = Slow->next;
    }
    return false;
}