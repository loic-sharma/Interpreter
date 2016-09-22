#include "vm/Interpreter.h"

#include <iostream>

void Assert(bool condition, const char *error)
{
    if (condition == false)
    {
        std::cerr << "\033[" << 31 << "m"
                  << error
                  << "\033[" << 39 << "m"
                  << std::endl;

        exit(1);
    }
}

void TestSingleLoadConstant()
{
    Interpreter i;
    Context context;

    int32_t instructions[] = {
        Load_Constant_Integer, 1,
        Halt,
    };

    i.ExecuteContext(&context, instructions);

    Assert(context.stack[0] == 1, "stack[0] != 1");
}

void TestMultipleLoadConstants()
{
    Interpreter i;
    Context context;

    int32_t instructions[] = {
        Load_Constant_Integer, 1,
        Load_Constant_Integer, 2,
        Halt,
    };

    i.ExecuteContext(&context, instructions);

    Assert(context.stack[0] == 1, "stack[0] != 1");
    Assert(context.stack[1] == 2, "stack[1] != 2");
}

void TestSimpleAdd()
{
    Interpreter i;
    Context context;

    int32_t instructions[] = {
        Load_Constant_Integer, 1,
        Load_Constant_Integer, 2,
        Add,
        Halt,
    };

    i.ExecuteContext(&context, instructions);

    Assert(context.stack[0] == 3, "stack[0] != 3");
}

void TestComplexAdd()
{
    Interpreter i;
    Context context;

    int32_t instructions[] = {
        Load_Constant_Integer, 1,
        Load_Constant_Integer, 2,
        Add,
        Load_Constant_Integer, 3,
        Add,
        Halt,
    };

    i.ExecuteContext(&context, instructions);

    Assert(context.stack[0] == 6, "stack[0] != 6");
}

void TestSimpleBranch()
{
    Interpreter i;
    Context context;

    // This program should terminate.
    int32_t instructions[] = {
        Jump, 2,
        Jump, 0,
        Halt,
    };

    i.ExecuteContext(&context, instructions);
}

void TestSimpleBranchTrue()
{
    Interpreter i;
    Context context;

    // Test the following program:
    //
    //   while (false) {}
    //
    //   if (false)
    //   {
    //       while (true) {}
    //   }
    //
    // This program should terminate.
    int32_t instructions[] = {
        Load_Constant_Integer, 0,
        Branch_True, -1,

        Load_Constant_Integer, 1,
        Branch_True, 5,

        Load_Constant_Integer, 1,
        Branch_True, -1,

        Halt,
    };

    i.ExecuteContext(&context, instructions);
}

int main()
{
    TestSingleLoadConstant();
    TestMultipleLoadConstants();
    TestSimpleAdd();
    TestComplexAdd();

    TestSimpleBranch();
    TestSimpleBranchTrue();
}
