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

            case Jump:
                context->instruction_ptr = instructions + *(context->instruction_ptr + 1);
                break;

            case Branch_True:
                if (*(context->stack_ptr - 1) != 0)
                {
                    // TODO: Re-use Branch instruction?
                    context->instruction_ptr = instructions + *(context->instruction_ptr + 1);
                }
                else
                {
                    context->instruction_ptr += 2;
                }

                context->stack_ptr -= 1;
                break;

            case Add:
                *(context->stack_ptr - 2) = *(context->stack_ptr - 1) + *(context->stack_ptr - 2);

                context->stack_ptr -= 1;
                context->instruction_ptr += 1;
                break;

            case Halt:
                return;
                break;
        }
    }
}
