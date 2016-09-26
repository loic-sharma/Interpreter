#include <Execution/Interpreter.h>

int32_t ConvertBytesToInteger(int8_t *bytes)
{
    return bytes[0] << 24
             | bytes[1] << 16
             | bytes[2] << 8
             | bytes[3];
}

void Interpreter::ExecuteContext(Context *context, int8_t *instructions)
{
    context->instruction_ptr = instructions;

    while (true)
    {
        switch ((Instruction)*context->instruction_ptr)
        {
            case Load_Constant_Short:
                context->stack.Push(*(context->instruction_ptr + 1));

                context->instruction_ptr += 2;
                break;

            case Load_Constant_Integer:
            {
                int32_t value = ConvertBytesToInteger(context->instruction_ptr + 1);

                context->stack.Push(value);

                context->instruction_ptr += 5;
                break;
            }

            case Jump:
                context->instruction_ptr += *(context->instruction_ptr + 1) + 2;
                break;

            case Branch_True:
                if (context->stack.Pop().AsInteger() != 0)
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
                // TODO: Generic so that it works with non-integers?
                context->stack.Push(context->stack.Pop().AsInteger() + context->stack.Pop().AsInteger());

                context->instruction_ptr += 1;
                break;

            case Call:
            {
                int32_t offset = context->instruction_ptr - instructions;

                context->stack.Push(offset + 2);
                context->stack.PushFrame();

                // TODO: Right now method calls are relative jumps to the start
                // of the function. In the future I'll add in a method table
                // similar to .NET's.
                context->instruction_ptr += *(context->instruction_ptr + 1) + 1;
                break;
            }

            case Return:
                context->stack.PopFrame();
                context->instruction_ptr = instructions + context->stack.Pop().AsInteger();
                break;

            case Halt:
                return;
                break;
        }
    }
}
