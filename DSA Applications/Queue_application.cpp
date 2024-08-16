
#include <iostream>
#include <string>
using namespace std;
#define SIZE 5
string items[SIZE];
int prices[SIZE];
int front = -1;
int rear = -1;

void addItem()
{

    if (rear == SIZE - 1)
    {
        cout << "Order list is full." << endl;
    }
    else if (front == -1 && rear == -1)
    {
        string item;
        int price;
        front = 0;
        rear = 0;
        cout << "Enter Items: ";
        cin >> item;
        items[rear] = item;
        cout << "Enter Price: ";
        cin >> price;
        prices[rear] = price;
        rear++;
    }
    else
    {
        string item;
        int price;
        cout << "Enter Items: ";
        cin >> item;
        items[rear] = item;
        cout << "Enter Price: ";
        cin >> price;
        prices[rear] = price;
        rear++;
    }
}

void removeItem()
{
    if (front == -1 && rear == -1)
    {
        cout << "No items to remove." << endl;
    }
    else if (front > rear)
    {
        cout << "Order list is empty." << endl;
    }
    else
    {
        cout << "Removed item: " << items[front] << " costing " << prices[front] << " from the order." << endl;
        front++;
    }
}

void printReceipt()
{
    if (front == -1 && rear == -1)
    {
        cout << "No items in the order." << endl;
    }
    else
    {
        int total = 0;
        cout << "Receipt:" << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << items[i] << " : " << prices[i] << " Rs" << endl;
            total += prices[i];
        }
        cout << "Total: " << total << " Rs" << endl;
    }
}

int main()
{
    int c = 2 + 2;
    int choice;
    while (c != 5)
    {
        cout << "Enter choice: 1) Add Item 2) Remove Item 3) Print Receipt 4) Exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addItem();
            break;

        case 2:
            removeItem();
            break;

        case 3:
            printReceipt();
            break;

        case 4:
            c = 5;

        default:
            cout << "No" << endl;
        }
    }
}