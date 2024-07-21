#include "stack-vm.h"

/*
    Instruction format
    header: 2 bits
    data: 30 bits

    header format:
    0 => positive integer
    1 => primitive instruction
    2 => negative integer
    3 => undefined
*/

// functions
StackVM::StackVM()
{
    memory.reserve(1000000);
}

i32 StackVM::getType(i32 instruction)
{
    i32 type = 0xc0000000;
    type = (type & instruction) >> 30;
    return type;
}

i32 StackVM::getData(i32 instruction)
{
    i32 data = 0x3fffffff;
    data = data & instruction;
    return data;
}

void StackVM::fetch()
{
    pc++;
}

void StackVM::decode()
{
    typ = getType(memory[pc]);
}