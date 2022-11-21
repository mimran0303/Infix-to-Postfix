#include <iostream>
#include <vector>
#include <limits>
#include<fstream>

using namespace std;

ofstream fileWrite;

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


    int priority(char c)
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
            char e = expressions[i];

            if ((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z') || (e >= '0' && e <= '9')) //if operand we add to the output string
            {
                PostFix += e;
            }

            else if (e == '(') // if '(' add to the stack
            {
                stack.add('(');
            }

            else if (e == ')') // if ')' add to the stack, but if there is '(' then they cancel and any character between '(' and ')' will be moved to output string
            {
                while (stack.top() != '(') {
                    PostFix += stack.top();
                    stack.pop();
                }
                stack.pop();
            }

            else
            {
                while (stack.size() != 0 && priority(expressions[i]) <= priority(stack.top())) //adding charcaters from stack to postfix
                {
                    PostFix += stack.top();
                    stack.pop();
                }
                stack.add(e);
            }
        }

        while (stack.size() != 0) //adding from stack to postfix
        {
            PostFix += stack.top();
            stack.pop();
        }

        cout << PostFix << endl;


    }
    
//------------
//evaluation
//------------
  
    int Evaluate(string evaluation)
    {
        functions stack;

        for (int i = 0; i < evaluation.size(); i++) //goes through string of operands and characters
        {
            char e = evaluation[i];

            if (e >= '0' && e <= '9')
            {
                stack.add(e - '0');
            }

            else
            {
                // removes top two elements from stack

                int first = stack.top(); 
                stack.pop();

                int second = stack.top();
                stack.pop();

                // evaluates expressions and results are pushed back to the stack

                if (e == '+')                                                   
                {
                    stack.add(second + first);
                }
                else if (e == '-')
                {
                    stack.add(second - first);
                }
                else if (e == '*')
                {
                    stack.add(second * first);
                }
                else if (e == '/')
                {
                    stack.add(second / first);
                }
            }
        }

        return stack.top();
    }

//int main()
//{
//
//    string exp = "K+L-M*N+(O^P)*W/U/V*t+q";
//    string eval = "138*+";
//
//    cout << "infix expression: " << endl;
//    cout<<exp << endl;
//    cout << endl;
//
//    cout << "postfix expression: " << endl;
//    infixToPostfix(exp);
//    cout << endl;
//
//    cout << "TEST EVLUATION FUNCTION:" << endl;
//    cout << "ORIGINAL POSTFIX EXPRESSION: " << eval << endl;
//    cout<< "RESULT: " << Evaluate(eval)<<endl;

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
//}

    int main(int argc, char** argv)
    {
        char* programme = argv[0];
        char* Part = argv[1];
        string String = argv[2];
        char* File = argv[3];

        fileWrite.open(File);

        int part = atoi(Part);

        if (part == 2)
        {
            infixToPostfix(String);
        }
        else if (part == 3)
        {
            cout << Evaluate(String) << ".0" << endl;

        }

        fileWrite.close();
    }