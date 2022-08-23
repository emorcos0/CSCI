// who: emorcos
// what: Implement a stack
// why: Why not?
// when: 2021-10-05

// includes go here
#include <iostream>

//prototypes go here
void push(int);
int pop();
int peek();
void printArray(int[], int);

const int SIZE{1000};
int stack[SIZE];
int qtyItems{0};
bool isEmpty();


//definition goes here

int main(int argc, char const *argv[])
{
   // printStack();
   // push(10);
   // printStack();
   // push(20);
   // printStack();
   // push(30);
   // printStack();
   // std::cout << "Popped value " << pop() << std::endl;
   // printStack();
   // std::cout << "Peeked value " << peek() << std::endl;
   // printStack();

    int array[] {1,2,3,4,5};

    printArray(array, 5);

    for (int i = 0; i < 5; i++)
        push(array[i]);

  //  for (int i = 0; i < 5; i++)
  //     array[i] = pop();
    
    while(!isEmpty())
        std::cout << pop() << std::endl;

    printArray(array, 5);

	return 0;
}


void push(int value)
{
    if(qtyItems >= SIZE)
        return;

    stack[qtyItems++] = value;
}

int pop()
{
    if(qtyItems == 0)
        return -1000000;
    return stack[--qtyItems];
}

int peek()
{
    if(qtyItems == 0)
        return -1000000;
    return stack[qtyItems - 1];
}

void printArray(int array[], int size)
{
    std::cout << "array = { ";
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    
    std::cout << "}\n";
}

bool isEmpty()
{
    return qtyItems == 0;
}