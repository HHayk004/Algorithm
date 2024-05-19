#include <iostream>
#include <stack>

void printStack(std::stack<int>& stack)
{
    std::stack<int> tmp_stack;
    while (!stack.empty())
    {
        int tmp_val = stack.top();

        std::cout << tmp_val << ' ';

        tmp_stack.push(tmp_val);
        stack.pop();
    }
    std::cout << std::endl;

    while (!tmp_stack.empty())
    {
        stack.push(tmp_stack.top());
        tmp_stack.pop();
    }
}

std::stack<int> reverseStack(std::stack<int> stack)
{
    std::stack<int> answer;
    while (!stack.empty())
    {
        answer.push(stack.top());
        stack.pop();
    }

    return answer;
}

int sizeStack(std::stack<int> stack)
{
    int size = 0;
    while (!stack.empty())
    {
        ++size;
        stack.pop();
    }

    return size;
}

void sortStack(std::stack<int>& stack)
{
    int size = sizeStack(stack);

    std::stack<int> tmp_stack;
    while (size)
    {
        int count = 1;
        int max_val = stack.top();

        stack.pop();
        tmp_stack.push(max_val);

        for (int i = 0; i < size - 1; ++i)
        {
            int tmp_val = stack.top();
            if (tmp_val > max_val)
            {
                count = 1;
                max_val = tmp_val;
            }

            else if (tmp_val == max_val)
            {
                ++count;
            }

            stack.pop();
            tmp_stack.push(tmp_val);
        }

        for (int i = 0; i < count; ++i)
        {
            stack.push(max_val);
        }

        while (!tmp_stack.empty())
        {
            int tmp_val = tmp_stack.top();
            if (tmp_val != max_val)
            {
                stack.push(tmp_val);
            }

            tmp_stack.pop();
        }

        size -= count;
    }
}

int main()
{
    std::stack<int> stack;
    
    for (int elem : {2, 3, 1, 4, 1, 4, 5, 0, 5, 1, 2})
    {
        stack.push(elem);
    }

    sortStack(stack);

    printStack(stack);

    stack = reverseStack(stack);

    printStack(stack);

    return 0;
}