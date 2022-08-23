const int MAX_STACK_QTY{1000};


class Stack
{
public:
    void push(double);

    double pop();

    double peek();

    bool isEmpty();

    void clear();

private: 
    double array[MAX_STACK_QTY];
    int top{0};
};