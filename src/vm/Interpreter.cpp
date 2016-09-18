#include <vm/Interpreter.h>

void Interpreter::ExecuteContext(Context *context, int32_t *instructions)
{
    context->instruction_ptr = instructions;
    context->stack_ptr = context->stack;

    while (true)
    {
        switch ((Instruction)*context->instruction_ptr)
        {
            case Load_Constant_Integer:
                *context->stack_ptr = *(context->instruction_ptr + 1);

                context->stack_ptr += 1;
                context->instruction_ptr += 2;
                break;

            case Add:
                context->instruction_ptr += 1;
                break;

            case Halt:
                return;
                break;
        }
    }
}