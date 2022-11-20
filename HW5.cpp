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
       // if (logging == true)
           // cout << "Added " << e << endl;
    }

    int pop() // use popback here to return top element
    {
        if (stack.size() == 0)
        {
            return INT_MIN;
        }

        int i = stack.at(stack.size() - 1);
        stack.pop_back();
        //if (logging == true)
            //cout << "Popped " << i << endl;

        return i;
    }

    int top() //working
    {
        if (stack.size() == 0)
        {
            return INT_MIN;
        }

        int i = stack.at(stack.size() - 1);
       // if (logging == true)
           // cout << "Top Value " << i << endl;;
        return i;
    }

    int size()    
    {
        //if (logging == true)
            //cout << "Size " << stack.size() << endl;;
        return stack.size();
    }
    
    void Print()
    {
        cout << "Print: " << endl;
        if (stack.size() == 0)
        {
            //cout << "  Stack is Empty " << endl;
            return;
        }

        for (int i = stack.size() - 1; i >= 0; i--)
        {
            int value = stack.at(i);
           // cout << "  " << value << endl;
        }
    }
};



//------------
//expressions
//------------


    int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    void infixToPostfix(string expressions)
    {
        functions stack; //where all characters are added
        string PostFix; //where all operands are added


        for (int i = 0; i < expressions.size(); i++)
        {
            char c = expressions[i];

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) //if operand we add to the output string
            {
                PostFix += c;
            }

            else if (c == '(') // if '(' add to the stack
            {
                stack.add('(');
            }

            else if (c == ')') // if ')' add to the stack, but if there is '(' then they cancel and any character between '(' and ')' will be moved to output string
            {
                while (stack.top() != '(') {
                    PostFix += stack.top();
                    stack.pop();
                }
                stack.pop();
            }

            else
            {
                while (!stack.size() == 0 && prec(expressions[i]) <= prec(stack.top())) //adding charcaters from stack to postfix
                {
                    PostFix += stack.top();
                    stack.pop();
                }
                stack.add(c);
            }
        }

        while (!stack.size() == 0) //adding from stack to postfix
        {
            PostFix += stack.top();
            stack.pop();
        }

        cout << PostFix << endl;


    }
    
//------------
//evaluation
//------------
  


int main()
{

    string exp = "K+L-M*N+(O^P)*W/U/V*T+Q";
    cout << "infix expression: " << exp << endl;
    cout<<"postfix expression: ";
    infixToPostfix(exp);

    /*functions stack;

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
    stack.Print();*/
}