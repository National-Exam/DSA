#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> elements;

public:
    void push(const T &item)
    {
        elements.push_back(item);
    }

    void pop()
    {
        if (!elements.empty())
        {
            elements.pop_back();
        }
    }

    const T &top() const
    {
        return elements.back();
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
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top: " << stack.top() << endl;   // Output: Top: 30
    cout << "Size: " << stack.size() << endl; // Output: Size: 3

    stack.pop();

    cout << "Top: " << stack.top() << endl;   // Output: Top: 20
    cout << "Size: " << stack.size() << endl; // Output: Size: 2

    return 0;
}
