#include "Execution/Stack.h"

Stack::Stack()
{
    this->stack = new Value[1024];
    this->stack_ptr = stack;
    this->frame_ptr = nullptr;
}

void Stack::PushFrame()
{
    this->frame_ptr = this->stack_ptr;
    this->Push(this->frame_ptr - this->stack);
}

void Stack::PopFrame()
{
    this->stack_ptr = this->frame_ptr;
    this->frame_ptr = this->stack_ptr->AsInteger() + this->stack;
}

void Stack::Push(Value value)
{
    *this->stack_ptr = value;

    ++this->stack_ptr;
}

Value Stack::Pop()
{
    --this->stack_ptr;

    return *this->stack_ptr;
}

Value Stack::Peek()
{
    return *(this->stack_ptr - 1);
}

Value Stack::At(int32_t position)
{
    return this->stack[position];
}
