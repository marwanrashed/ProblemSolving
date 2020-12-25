#include <bits/stdc++.h>
#include <algorithms>
using namespace std; 

class Node {
    public:
    // Public Variables
    Node next;

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
    Node head;
    //  linkedlist methods
    void append (int); 
    void prepend (int);
};

void LinkedList::append (int data) {
    if (head == null) {
        head.setData(data);
    } 
    Node Current = head;
    while (Current.next != NULL) {
        Current = Current.next;
    }
    Current.next = Node(data);
} 

void LinkedList::prepend (int data) {
    Node newHead = Node(data);
    newHead.next = head;
    head = newHead;
}