#pragma once

#include <cstdint>

class Stack {
  // The pointer to the start of the stack.
  int32_t *stack;

  // The pointer to the end of the stack.
  int32_t *stack_ptr;

  // A new frame is pushed to the stack each time a method is called.
  // This points to the start of the current frame.
  int32_t *frame_ptr;

  public:
    Stack();

    void PushFrame();
    void PopFrame();

    void Push(int32_t);

    int32_t Pop();
    int32_t Peek();

    int32_t At(int32_t position);
};
