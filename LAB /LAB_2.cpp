#include <iostream>
using namespace std;
#define MAX_SIZE 10

class SStack
{
public:
    int stack[MAX_SIZE];
    int top = 0;
    int choice;
    int num;

    void push(int n)
    {
        if (top >= MAX_SIZE)
        {
            cout << "MAX SIZE REACHED" << endl;
        }
        else
        {
            stack[top] = n;
            top++;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Popped number: " << num << endl;
            num = stack[top];
            top--;
        }
    }

    void peek()
    {
        if (top <= -1)
        {
            cout << "Stack underflow";
        }
        else
        {
            cout << "Top element: " << stack[top - 1];
        }
    }

    void display()
    {
        for (int i = 0; i < top; i++)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty()
    {
        return top == 0;
    }
    bool isFull()
    {
        return top >= MAX_SIZE;
    }
    void insertSorted(int element)
    {
        if (isEmpty() || stack[top - 1] <= element)
        {
            push(element);
        }
        else
        {
            int temp = stack[top - 1];
            pop();
            insertSorted(element);
            push(temp);
        }
    }

    void sortStack()
    {
        if (!isEmpty())
        {
            int temp = stack[top - 1];
            pop();
            sortStack();
            insertSorted(temp);
        }
    }
};

int main()
{
    SStack stack;
    int loop = 1;
    while (loop == 1)
    {
        cout << "\n Main menu ";
        cout << "\n1) Add element to stack\n";
        cout << "\n2) Delete from the stack\n";
        cout << "\n3) Peek from the stack\n";
        cout << "\n4) Display the stack\n";
        cout << "\n5) Sort the stack\n";
        cout << "\nEnter choice: ";
        cin >> stack.choice;

        switch (stack.choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> stack.num;
            stack.push(stack.num);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.peek();
            break;
        case 4:
            stack.display();
            break;
        case 5:
            stack.sortStack();
            cout << "Stack sorted." << endl;
            break;
        default:
            cout << "\n Invalid choice" << endl;
        }

        cout << "\nDo you want to do more operations on the stack (1 for yes, any other key for exit): ";
        cin >> loop;
    }

    return 0;
}
