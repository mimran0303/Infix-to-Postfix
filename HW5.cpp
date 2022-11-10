#include <iostream>
#include <vector>

using namespace std;

class functions
{
    // https://www.programiz.com/cpp-programming/vectors 
    //
private: vector<int> stack;

public:

    // a = 10;
    // b = 20;
    // c = 5;
    // a = c then a will have value of 5
    // c = a then c will have value of 10

    void add(int e) //use pushback in here
    {
        stack.push_back(e);
    }

    int pop() // use popback here to return top element
    {
        if (stack.size() == 0)
        {
            return INT_MIN;
        }

        int i = stack.at(stack.size() - 1);
        stack.pop_back();
        return i;
    }

    int top() //working
    {
        if (stack.size() == 0)
        {
            return INT_MIN;
        }

        int i = stack.at(stack.size() - 1);
        cout << "value is: " << i << endl;;
        return i;
    }

    //int _size() //working
    //{
    //    return stack.size();
    //}

    void size()//working
    {
        if (stack.size() == 0)
        {
            return;
        }

        int length = 0;
        for (int elements : stack)
            length++;
        cout << "length is: " << length << endl;;
    }

    void Print() //working
    {
        if (stack.size() == 0)
        {
            cout << "stack is empty " << endl;
            return;
        }

        for (int i = 0; i < stack.size(); i++)
        {
            int value = stack.at(i);
            cout<<value<<endl;
        }
        cout << endl;
    }
};

int main()
{
    
    functions stack;

    //stack.add(90);
    //stack.add(50);
    //stack.add(500);
    //stack.add(50);
    //stack.add(5);

    stack.Print();

  /*  stack.pop();

    stack.Print();

    stack.top();

    stack.size();*/


}