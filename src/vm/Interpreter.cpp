#include <vm/Interpreter.h>

void Interpreter::ExecuteContext(Context *context, int32_t *instructions)
{
    context->instruction_ptr = instructions;

    while (true)
    {
        switch ((Instruction)*context->instruction_ptr)
        {
            case Load_Constant_Integer:
                context->stack.Push(*(context->instruction_ptr + 1));

                context->instruction_ptr += 2;
                break;

            case Jump:
                context->instruction_ptr += *(context->instruction_ptr + 1) + 1;
                break;

            case Branch_True:
                if (context->stack.Pop() != 0)
                {
                    // TODO: Re-use Branch instruction?
                    context->instruction_ptr += *(context->instruction_ptr + 1) + 1;
                }
                else
                {
                    context->instruction_ptr += 2;
                }

                break;

            case Add:
                context->stack.Push(context->stack.Pop() + context->stack.Pop());

                context->instruction_ptr += 1;
                break;

            case Halt:
                return;
                break;
        }
    }
}
