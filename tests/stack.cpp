#include "Execution/Stack.h"
#include "test.h"

void TestSimple()
{
    Stack stack;

    stack.Push(5);
    stack.Push(3);

    Assert(stack.At(0).AsInteger() == 5, "stack[0] != 5");
    Assert(stack.At(1).AsInteger() == 3, "stack[1] != 3");
    Assert(stack.Peek().AsInteger() == 3, "stack.Peek() != 3");

    stack.Pop();

    Assert(stack.At(0).AsInteger() == 5, "stack[0] != 5");
    Assert(stack.Peek().AsInteger() == 5, "stack.Peek() != 5");

    stack.Push(7);

    Assert(stack.At(0).AsInteger() == 5, "stack[0] != 5");
    Assert(stack.At(1).AsInteger() == 7, "stack[1] != 7");
    Assert(stack.Peek().AsInteger() == 7, "stack.Peek() != 7");
}

void TestFrames()
{
    Stack stack;

    stack.Push(5);

    Assert(stack.At(0).AsInteger() == 5, "stack[0] != 5");

    stack.PushFrame();

    stack.Push(7);
    stack.Push(4);

    Assert(stack.At(0).AsInteger() == 5, "stack[0] != 5");
    Assert(stack.At(1).AsInteger() == 1, "stack[1] != 1");
    Assert(stack.At(2).AsInteger() == 7, "stack[2] != 7");
    Assert(stack.At(3).AsInteger() == 4, "stack[3] != 4");
    Assert(stack.Peek().AsInteger() == 4, "stack.Peek() != 4");

    stack.PopFrame();

    stack.Push(9);

    Assert(stack.At(0).AsInteger() == 5, "stack[0] != 5");
    Assert(stack.At(1).AsInteger() == 9, "stack[0] != 9");
    Assert(stack.Peek().AsInteger() == 9, "stack.Peek() != 9");
}

int main()
{
    TestSimple();
    TestFrames();
}
