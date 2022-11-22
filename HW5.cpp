#include <iostream>
#include <vector>
#include <limits>
#include <string>   
#include<fstream>

using namespace std;

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

    string infixToPostfix(string expressions)
    {
        functions stack; 
        string PostFix; 

        for (int i = 0; i < expressions.size(); i++)
        {

            if (expressions[i] >= '0' && expressions[i] <= '9') //if operand we add to the output string
            {
                PostFix += expressions[i];
            }

            else if (expressions[i] == '(') // if '(' add to the stack
            {
                stack.add('(');
            }

            else if (expressions[i] == ')') // if ')' add to the stack, but if there is '(' then they cancel and any character between '(' and ')' will be moved to output string
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
                stack.add(expressions[i]);
            }
        }

        while (stack.size() != 0) //adding from stack to postfix
        {
            PostFix += stack.top();
            stack.pop();
        }

        return PostFix;
    }
    
//----------------
//evaluation
//----------------
  
    int Evaluate(string evaluation)
    {
        functions stack;

        for (int i = 0; i < evaluation.size(); i++) //goes through string of operands and characters
        {
            if (evaluation[i] >= '0' && evaluation[i] <= '9') //checks if postfix expressions is correct
            {
                stack.add(evaluation[i] - '0');
            }
            else
            {
                // top two numbers from stack are popped and we then perform operations
                if (stack.size() == 0)
                {
                    return INT_MIN;
                }
                int first = stack.pop();

                if (stack.size() == 0)
                {
                    return INT_MIN;
                }
                int second = stack.pop();

                //performing operation on top two numbers 

                if (evaluation[i] == '+')
                {
                    stack.add(second + first);
                }
                else if (evaluation[i] == '-')
                {
                    stack.add(second - first);
                }
                else if (evaluation[i] == '*')
                {
                    stack.add(second * first);
                }
                else if (evaluation[i] == '/')
                {
                    stack.add(second / first);
                }
                else if (evaluation[i] == '^')
                {
                    stack.add(pow(second, first));
                }                        
            }  
        }

        int result = stack.pop();

        if (stack.size() != 0)
        {
            return INT_MIN;
        }

        return result;
    }

    int main(int argc, char** argv)
    {
     
        char* programme = argv[0];
        char* Part = argv[1];
        string String = argv[2];
        char* File = argv[3];

        int part = atoi(Part);

        ofstream fileWrite;
        fileWrite.open(File);

        if (part == 2)
        {
            string postfix = infixToPostfix(String);
            fileWrite << postfix << endl;
        }

        else if (part == 3)
        {
            int result = Evaluate(String);
            if (result != INT_MIN)
            {
                fileWrite << Evaluate(String) << ".0" << endl;
            }
            else if (result == INT_MIN)
            {
                
                fileWrite << "nv" << endl;
            }
        }

        fileWrite.close();
        return 0;
    }

    int mainTest(int argc, char** argv)
    {
        string input = "((4+2)*(2+6*(6-4)))/2";
        string postfix = infixToPostfix(input);
        int result = Evaluate(postfix);
        cout << "Input: " << input << endl;
        cout << "Postfix: " << postfix << endl;
        cout << "Output: " << result << endl;
        return 0;
    }

