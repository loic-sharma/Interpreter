#pragma once

typedef enum {
    Load_Constant_Short,
    Load_Constant_Integer,

    Jump,
    Branch_True,

    Add,

    Print,
    Halt,
} Instruction;
