#pragma once

#include <cstdint>

#include <vm/Instructions.h>

struct Context {
    int32_t stack[1024];

    int32_t *stack_ptr;
    int32_t *instruction_ptr;
};

class Interpreter {
  public:
    void ExecuteContext(Context *, int32_t *);
};
