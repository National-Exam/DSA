#include <iostream>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *head;
    std::size_t size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList()
    {
        clear();
    }

    void insert(const T &value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        size++;
    }

    void remove(const T &value)
    {
        Node *current = head;
        Node *previous = nullptr;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                if (previous == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                delete current;
                size--;
                return;
            }

            previous = current;
            current = current->next;
        }
    }

    bool contains(const T &value) const
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    std::size_t getSize() const
    {
        return size;
    }

    void clear()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    void display() const
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList<int> linkedList;

    linkedList.insert(10);
    linkedList.insert(20);
    linkedList.insert(30);
    linkedList.display(); // Output: 10 20 30

    linkedList.remove(20);
    linkedList.display(); // Output: 10 30

    std::cout << "Size: " << linkedList.getSize() << std::endl; // Output: Size: 2

    std::cout << "Contains 30? " << (linkedList.contains(30) ? "Yes" : "No") << std::endl; // Output: Contains 30? Yes
    std::cout << "Contains 40? " << (linkedList.contains(40) ? "Yes" : "No") << std::endl; // Output: Contains 40? No

    linkedList.clear();
    std::cout << "Size after clearing: " << linkedList.getSize() << std::endl; // Output: Size after clearing: 0

    return 0;
}
