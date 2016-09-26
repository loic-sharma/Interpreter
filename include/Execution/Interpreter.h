#pragma once

#include <cstdint>

#include <Execution/Instructions.h>
#include <Execution/Stack.h>

struct Context {
    int8_t *instruction_ptr;
    Stack stack;
};

class Interpreter {
  public:
    void ExecuteContext(Context *, int8_t *);
};
