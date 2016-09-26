#pragma once

#include <Execution/Value.h>

class Stack {
  // The pointer to the start of the stack.
  Value *stack;

  // The pointer to the end of the stack.
  Value *stack_ptr;

  // A new frame is pushed to the stack each time a method is called.
  // This points to the start of the current frame.
  Value *frame_ptr;

  public:
    Stack();

    void PushFrame();
    void PopFrame();

    void Push(Value);

    Value Pop();
    Value Peek();

    Value At(int32_t position);
};
