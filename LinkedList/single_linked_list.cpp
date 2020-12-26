#include <bits/stdc++.h>
#include <algorithm>
using namespace std; 

class Node {
    public:
    // Public Variables
    Node *next;

    // Constructors 
    Node();
    Node (int data): _data(data){}

    // setters
    void setData (int data) {_data = data;}
    //getters
    int getData(){return _data;}
    private :
    int _data;
};

class LinkedList {
    public:
    // Public Variables
    Node* head;
    //  linkedlist methods
    void append (int); 
    void prepend (int);
    void deleteWithValue(int);
    void printList();
    void free_singly_linked_list(Node*);
};

void LinkedList::append (int data) {
    if (head == NULL) {
        cout << "head has a pointer issue"<<endl;
        head = new Node(data);
        } 
    Node* Current = head;
    while (Current->next != NULL) {
        Current = Current->next;
    }
    Current->next = new Node(data);
    cout << Current->next->getData()<<endl;

} 

void LinkedList::prepend (int data) {
    Node *newHead = new Node(data);
    newHead->next = head;
    head = newHead;
}

void LinkedList::deleteWithValue(int data){
    // Check if the head is the one to be deleted, then just remove it. 
    if (head->getData() == data){
        head = head->next;
    }
    // Check for each node until null
    Node* Current = head;
    while (Current->next != NULL){
        if (Current->next->getData() == data){
            Current->next = Current->next->next;
            break;
        }
        Current = Current->next;
    }

}

void LinkedList::printList(){
    if (head == NULL) {
        cout << "The list is empty !" << endl;
    }
    Node* current = head;
    while (current->next != NULL){
        cout << current->next->getData() << '\t';
        current = current->next;
    }
    cout << endl;
}

void LinkedList::free_singly_linked_list(Node* node) {
    while (node) {
        Node* temp = node;
        node = node->next;

        free(temp);
    }
}
int main () {
    cout << "Please insert the linked list head " << endl;
    int a,b,c,d,e;
    cin >> a;
    cin >>b;
    cin>> c;
    cin >>d;
    cin >>e;
    cout << a<<b<<c<<d<<e<< endl;
    auto linkedList = LinkedList();
    linkedList.append(a);
    linkedList.append(b);
    linkedList.append(c);
    linkedList.append(d);
    linkedList.prepend(e);
    linkedList.printList();
    linkedList.deleteWithValue(3);
    linkedList.printList();
    linkedList.free_singly_linked_list();
}