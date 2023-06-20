#include <iostream>
#include <deque>

using namespace std;

template <typename T>
class Queue
{
private:
    deque<T> elements;

public:
    void enqueue(const T &item)
    {
        elements.push_back(item);
    }

    void dequeue()
    {
        if (!elements.empty())
        {
            elements.pop_front();
        }
    }

    const T &front() const
    {
        return elements.front();
    }

    bool empty() const
    {
        return elements.empty();
    }

    size_t size() const
    {
        return elements.size();
    }
};

int main()
{
    Queue<int> queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Print front and size
    cout << "Front: " << queue.front() << endl;
    cout << "Size: " << queue.size() << endl;

    // Dequeue elements
    queue.dequeue();

    // Print front and size again
    cout << "Front: " << queue.front() << endl;
    cout << "Size: " << queue.size() << endl;

    return 0;
}
