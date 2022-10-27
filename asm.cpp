#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdint>

uint32_t generate_i(int rd, int rs1, int imm, int func3) {
    uint32_t instr = 0;
    instr |= (uint32_t)(0b0010011);    // Opcode i
    instr |= (uint32_t)(rd << 7);
    instr |= (uint32_t)(func3 << 12);
    instr |= (uint32_t)(rs1 << 15);
    instr |= (uint32_t)(imm << 20);
    return instr;
}

int main(int argc, char **argv) {
    uint32_t instr = 0;
    
    // addi x1, x2, 10
    instr = generate_i(1, 2, 10, 0b110);
    printf("%X\n", instr);
    
    instr = generate_i(4, 5, 10, 0);
    printf("%X\n", instr);

    return 0;
}

