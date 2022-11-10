#include <iostream>
#include <vector>
#include <limits>

using namespace std;

bool logging = true;

class functions
{
    // https://www.programiz.com/cpp-programming/vectors 
    //
private: vector<int> stack;

public:

    void add(int e) //use pushback in here
    {
        stack.push_back(e);
        if (logging == true)
            cout << "Added " << e << endl;
    }

    int pop() // use popback here to return top element
    {
        if (stack.size() == 0)
        {
            return INT_MIN;
        }

        int i = stack.at(stack.size() - 1);
        stack.pop_back();
        if (logging == true)
            cout << "Popped " << i << endl;

        return i;
    }

    int top() //working
    {
        if (stack.size() == 0)
        {
            return INT_MIN;
        }

        int i = stack.at(stack.size() - 1);
        if (logging == true)
            cout << "Top Value " << i << endl;;
        return i;
    }

    int size()    
    {
        if (logging == true)
            cout << "Size " << stack.size() << endl;;
        return stack.size();
    }

    
    void Print()
    {
        cout << "Print: " << endl;
        if (stack.size() == 0)
        {
            cout << "  Stack is Empty " << endl;
            return;
        }

        for (int i = stack.size() - 1; i >= 0; i--)
        {
            int value = stack.at(i);
            cout << "  " << value << endl;
        }
    }
};

int main()
{
    
    functions stack;

    stack.Print();

    stack.add(90);
    stack.add(50);
    stack.add(500);
    stack.add(50);
    stack.add(5);
    stack.Print();

    stack.pop();
    stack.Print();

    stack.top();
    stack.size();

    stack.pop();
    stack.pop();
    stack.Print();
}