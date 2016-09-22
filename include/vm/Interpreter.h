#pragma once

#include <cstdint>

#include <vm/Instructions.h>
#include <vm/Stack.h>

struct Context {
    int32_t *instruction_ptr;
    Stack stack;
};

class Interpreter {
  public:
    void ExecuteContext(Context *, int32_t *);
};
