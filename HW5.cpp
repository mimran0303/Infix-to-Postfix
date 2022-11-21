#include <iostream>
#include <vector>
#include <limits>
#include<fstream>

using namespace std;

ofstream fileWrite;

//------------
//class stack
//------------

class functions
{
   
private: vector<int> stack;

public:

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

    int top() //finding top most element
    {
        if (stack.size() == 0)
        {
            return INT_MIN;
        }

        int i = stack.at(stack.size() - 1);
        return i;
    }

    int size() //number of elements
    {
        return stack.size();
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

        fileWrite << PostFix << endl;


    }
    
//----------------
//evaluation
//----------------
  
    int Evaluate(string evaluation)
    {
        functions stack;

        for (int i = 0; i < evaluation.size(); i++) //goes through string of operands and characters
        {
            char character = evaluation[i];

            if (character >= '0' && character <= '9')
            {
                stack.add(character - '0');
            }
            else
            {
                // top two numbers from stack are popped and we then perform operations

                int first = stack.top();
                stack.pop();

                int second = stack.top();
                stack.pop();

                //performing operation on top two numbers 

                if (character == '+')
                {
                    stack.add(second + first);
                }
                else if (character == '-')
                {
                    stack.add(second - first);
                }
                else if (character == '*')
                {
                    stack.add(second * first);
                }
                else if (character == '/')
                {
                    stack.add(second / first);
                }
                else if (character == '^')
                {
                    stack.add(pow(second, first));
                }
            }
        }

        //returning result
        return stack.top();
    }

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
             fileWrite<< Evaluate(String) << ".0" << endl;
        }

        fileWrite.close();
    }