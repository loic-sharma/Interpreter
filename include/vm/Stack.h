#pragma once

#include <cstdint>

class Stack {
  int32_t *stack;
  int32_t *stack_ptr;

  public:
    Stack();

    void Push(int32_t);

    int32_t Pop();
    int32_t Peek();

    int32_t At(int32_t position);
};
