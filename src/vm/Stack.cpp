#include "vm/Stack.h"

Stack::Stack()
{
    this->stack = new int32_t[1024];
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
    this->frame_ptr = *this->stack_ptr + this->stack;
}

void Stack::Push(int32_t value)
{
    *this->stack_ptr = value;

    ++this->stack_ptr;
}

int32_t Stack::Pop()
{
    --this->stack_ptr;

    return *this->stack_ptr;
}

int32_t Stack::Peek()
{
    return *(this->stack_ptr - 1);
}

int32_t Stack::At(int32_t position)
{
    return this->stack[position];
}
