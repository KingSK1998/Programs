#include <bits/stdc++.h>

class Node{
    public:
        int data;
        Node* next;
};

void insertAtFront(Node** head, int newData){
    // Create New Node
    Node* newNode = new Node();
    // Add Data to New Node
    newNode->data = newData;
    // Make next of new node as head
    newNode->next = *head;
    // Move head to new node
    *head = newNode;
}

void insertAtLast(Node** head, int newData){
    Node* newNode = new Node();     // Create new node
    newNode->data = newData;        // Assign data to new node
    newNode->next = NULL;           // Assign NULL to new node as end point

    if(head == NULL){               // If Linked List is empty
        *head = newNode;            // Make new node as head
        return;                     // Exit
    }

    Node* lastNode = *head;         // Make use this for traversal
    while (lastNode->next != NULL)  // If last of next element is not NULL
        lastNode = lastNode->next;  // Increment the pointer
    
    lastNode->next = newNode;       // Last Node point to new node which contain NULL
}

void insertAfterData(Node** head, int previousData, int newData){
    
    if (head == NULL){
        std::cout << "Sorry Bro! Add something first!!!" << std::endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;
    
    Node* currentNode = *head;
    while (currentNode->data != previousData)
        currentNode = currentNode->next;
    
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void printList(Node* head){
    while(head != NULL){
        std::cout << head->data << " --> ";
        head = head->next;
    }
    std::cout << "NULL";
}

int main(){
    Node* head = NULL;
    
    insertAtFront(&head, 12);

    insertAtLast(&head, 2);

    insertAtLast(&head, 5);

    insertAfterData(&head, 2, 3);

    printList(head);

    return 0;
}