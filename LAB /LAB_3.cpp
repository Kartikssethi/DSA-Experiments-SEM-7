
#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 10

class SStack
{
public:
    char stack[MAX_SIZE];
    int top = -1; 

    bool push(char n)
    {
        if (top >= MAX_SIZE - 1) 
        {
            return false;
        }
        else
        {
            top++;
            stack[top] = n;
            return true;
        }
    }

    bool pop()
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            top--;
            return true;
        }
    }

    char peek()
    {
        if (top >= 0)
        {
            return stack[top]; // Access the top element correctly
        }
        return '\0'; // Return null character if stack is empty
    }

    bool isEmpty()
    {
        return top == -1; // Empty when top is -1
    }

    bool isFull()
    {
        return top >= MAX_SIZE - 1;
    }
};

class CHECKER : protected SStack // Inherit as protected
{
public:
    bool isBalanced(string expr, int length)
    {
        char ch;

        for (int i = 0; i < length; i++)
        {
            if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
            {
                push(expr[i]);
                continue;
            }

            if (isEmpty())
                return false;

            ch = peek();
            pop();

            switch (expr[i])
            {
            case ')':
                if (ch != '(')
                    return false;
                break;

            case '}':
                if (ch != '{')
                    return false;
                break;

            case ']':
                if (ch != '[')
                    return false;
                break;
            }
        }

        return isEmpty(); // Ensure all opened brackets were closed
    }
};

int main()
{
    CHECKER c;
    string expr = "[][])";
    int length = expr.size();

    if (c.isBalanced(expr, length))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }

    return 0;
}
