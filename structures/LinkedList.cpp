#include <iostream>

namespace std;

// Node class representing a single node in the linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class
class LinkedList
{
private:
    Node *head; // Pointer to the first node in the list

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to deallocate memory
    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to insert a new node at the beginning of the list
    void insert(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to print the linked list
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList myList;

    // Inserting nodes
    myList.insert(3);
    myList.insert(7);
    myList.insert(12);

    // Displaying the list
    myList.display();

    return 0;
}
