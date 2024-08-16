
// #include <iostream>
// using namespace std;
// #define size 5
// int queue[size];
// int front=-1;
// int rear=-1;
// void enqueue()
// {
//     int data;
//     if(rear==size-1)
//     {
//         cout<<"queue overflow";

//     }
//     else if(front==-1&&rear==-1)
//     {
//         front=0;
//         rear=0;
//         cout<<"Enter data: ";
//         cin>>data;
//         queue[rear]=data;
//         rear++;
//     }
//     else
//     {
//         cout<<"Enter data: ";
//         cin>>data;
//         queue[rear] = data;
//         rear++;
//     }
// }
// void dequeue()
// {
//     if(front==-1 && rear==-1)
//     {
//         cout<<"Stack underflow";
//     }
//     else if(front>rear)
//     {
//         cout << "Stack overflow";
//     }
//     else
//     {
//         cout<<"Delete queue value: "<<queue[front]<<endl;
//         front++;
//         cout<<"New queue value: "<<queue[front]<<endl;
//     }
// }
// void display()
// {
//     if (front == -1 && rear == -1)
//     {
//         cout << "Stack underflow";
//     }
//     else
//     {
//     for(int i=front;i<rear;i++)
//     {
//         cout<<queue[i]<<" ";
//     }

//     }
// }
// int main()
// {
//     int meth = 2 + 2;
//     while (meth != 5)
//     {
//         int choice;
//         cout << "Enter choice: 1)enqueue 2)dequeue 3)display: ";
//         cin >> choice;
//         switch (choice)
//         {
//         case 1:
//             enqueue();
//             break;

//         case 2:
//             dequeue();
//             break;

//         case 3:
//             display();
//             break;

//         default:
//             cout << "No";
//             break;
//         }
//     }
// }

#include <iostream>
using namespace std;
#define size 5
int circular[size];
int front = -1;
int rear = -1;

void enqueue()
{
    int data;
    if (front == -1 && rear == -1)
    {
        cout << "Enter data";
        cin >> data;
        front = rear = 0;
        circular[rear] = data;
    }
    else if (((rear + 1) % size) == front) // if ever 2%5==front value then its full then it gave up
    {
        cout << "Queue full";
    }
    else // else example 0+1%5 gives 1 so it will have 1st index position
    {
        cout << "Enter data";
        cin >> data;
        rear = (rear + 1) % size;
        circular[rear] = data;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty";
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        cout << "The dequeued element is: " << circular[front];
         front = (front + 1) % size; // 0+1%5
        cout << "current front" << circular[front];
    }
}
void display()
{
    for (int i = rear; i < (i + 1) % size; i++)
    {
        cout << circular[i];
    }
}

int main()
{

    int meth = 2 + 2;
    while (meth != 5)
    {
        int choice;
        cout << "\nEnter choice: 1)enqueue 2)dequeue 3)display";
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        }
    }
}