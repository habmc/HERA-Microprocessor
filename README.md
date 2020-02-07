# HERA-Microprocessor
A 16-bit microprocessor built by Logisim which can perform a number of logical, arithmetic, memory and branching operations 
Quick guide can be found at https://ww3.haverford.edu/computerscience/resources/software/HERA/HERA2_3_3-quick.pdf

## OPERATIONS
Logical:
SET, AND, OR, XOR, LSL (Logical Shift Left), LSR (Logical Shift Right)

Arithmetic:
ADD, SUB, MUL, INC, DEC, ASL (Arithmetic Shift Left), ASR (Arithmetic Shift Right)

Flag:
FON - set the given flags to true,
FOFF - set the given flags to false,
FSET5 - set all flags to the given value,
FSET4 - set all flags except carry-block to the given value,
SAVEF - save flags to the register with the write address,
RSTRF - restore flags from the current register

Memory:
LOAD, STORE

Function/Interrupt:
CALL, RETURN

Branching:
BR(b): Unconditional branch – true
BL(b): Branch if signed result <0
BGE(b): Branch if signed result >0
BLE(b): Branch if signed result 60
BG(b): Branch if signed result >0
BULE(b): Branch if unsigned result 60
BUG(b): Branch if unsigned result >0
BZ(b): Branch if zero
BNZ(b): Branch if not zero
BC(b): Branch if carry/unsigned result >0
BNC(b): Branch if not carry/unsigned result <0
BS(b): Branch if sign (negative)
BNS(b): Branch if not sign (non-negative)
BV(b): Branch if overflow
BNV(b): Branch if not overflow


