#include "vm/Stack.h"
#include "test.h"

int main()
{
    Stack stack;

    stack.Push(5);
    stack.Push(3);

    Assert(stack.At(0) == 5, "stack[0] != 5");
    Assert(stack.At(1) == 3, "stack[1] != 3");
    Assert(stack.Peek() == 3, "stack.Peek() != 3");

    stack.Pop();

    Assert(stack.At(0) == 5, "stack[0] != 5");
    Assert(stack.Peek() == 5, "stack.Peek() != 5");

    stack.Push(7);

    Assert(stack.At(0) == 5, "stack[0] != 5");
    Assert(stack.At(1) == 7, "stack[1] != 7");
    Assert(stack.Peek() == 7, "stack.Peek() != 7");
}
