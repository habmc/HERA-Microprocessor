# HERA-Microprocessor
A 16-bit microprocessor built by Logisim which can perform a number of logical, arithmetic, memory and branching operations 

---------------------
# Operations

**Arithmetic & Logic**
SETLO(d, v) Rd← v E d v v set Rd to signed quantity v (8-bits)
SETHI(d, v) (Rd)15:8 ← v F d v v set high 8 bits of Rd
AND(d, a, b) Rd(i) ← Ra(i) ∧ Rb(i) 8 d a b bit-wise logical and
OR(d, a, b) Rd(i) ← Ra(i) ∨ Rb(i) 9 d a b bit-wise logical or
XOR(d, a, b) Rd(i) ← Ra(i) ⊕Rb(i) D d a b bit-wise logical exclusive or
ADD(d, a, b) Rd← Ra + Rb + (c ∧F4′) A d a b addition, use carry unless blocked
SUB(d, a, b) Rd← Ra − Rb − (c′ ∧F4′) B d a b subtraction, use carry unless blocked
MUL(d, a, b) Rd← (Ra ∗Rb)15:0 [Or 31:16] C d a b multiplication: low bits if F4 = 1...
INC(d, δ) Rd← Rd + δ 3 d 10ǫǫ ǫǫǫǫ increment Rd by δ (where ǫ = δ − 1)
DEC(d, δ) Rd← Rd − δ 3 d 11ǫǫ ǫǫǫǫ decrement Rd by δ (where ǫ = δ − 1)

**Shifts and Rotates**
LSL(d, b) Rd← shl/rolc (Rb) 3 d 0 b logical shift left, possibly with carry
LSR(d, b) Rd← shr/rorc (Rb) 3 d 1 b logical shift right, possibly with carry
LSL8(d, b) Rd← shl8 (Rb) 3 d 2 b logical shift left 8 bits
LSR8(d, b) Rd← shr8 (Rb) 3 d 3 b logical shift right 8 bits
ASL(d, b) Rd← asl/aslc (Rb) 3 d 4 b arithmetic shift left, possibly with carry
ASR(d, b) Rd← asr(Rb) 3 d 5 b arithmetic shift right

**Flag Management**
FON(v) F ← F ∨v 3 000v 6 vvvv Set to true any flags for which v is true
FOFF(v) F ← F ∧v′ 3 100v 6 vvvv Set to false any flags for which v is true
FSET5(v) F ← v 3 010v 6 vvvv Set all flags to have the values v
FSET4(v) F3:0 ← v 3 1100 6 vvvv Set flags other than carry-block
SAVEF(d) Rd← F 3 d 7 0 Save flags to Rd
RSTRF(d) F ← Rd 3 d 7 8 Restore flags from Rd

**Memory**
LOAD(d, o, b) Rd← M[Rb + o] 010o d oooo b load from Rb + o (o is 5-bit unsigned)
STORE(d, o, b) M[Rb + o] ← Rd 011o d oooo b store to Rb + o (o is 5-bit unsigned)

**Branches**
BR(b) PC ← Rb 1 0 0 b Unconditional branch – true
BL(b) PC ← Rb if (s ⊕ v) 1 2 0 b Branch if signed result <0
BGE(b) PC ← Rb if (s ⊕ v)′ 1 3 0 b Branch if signed result >0
BLE(b) PC ← Rb if ((s ⊕ v)∨ z) 1 4 0 b Branch if signed result 60
BG(b) PC ← Rb if ((s ⊕ v)∨ z)′ 1 5 0 b Branch if signed result >0
BULE(b) PC ← Rb if (c′ ∨z) 1 6 0 b Branch if unsigned result 60
BUG(b) PC ← Rb if (c′ ∨z)′ 1 7 0 b Branch if unsigned result >0
BZ(b) PC ← Rb if z 1 8 0 b Branch if zero/if equal
BNZ(b) PC ← Rb if z′ 1 9 0 b Branch if not zero/not equal
BC(b) PC ← Rb if c 1 A 0 b Branch if carry/unsigned result >0
BNC(b) PC ← Rb if c′ 1 B 0 b Branch if not carry/unsigned result <0
BS(b) PC ← Rb if s 1 C 0 b Branch if sign (negative)
BNS(b) PC ← Rb if s′ 1 D 0 b Branch if not sign (non-negative)
BV(b) PC ← Rb if v 1 E 0 b Branch if overflow
BNV(b) PC ← Rb if v′ 1 F 0 b Branch if not overflow

**Functions**
CALL(a,b) PC ← Rb, Rb←PC + 1, 2 0 a b Call function at address Rb, with stack at Ra
FP ← Ra, Ra← FP (or, equivalently, return or co-routine switch)
RETURN(a,b) PC ← Rb, Rb←PC + 1, 2 1 a b Return from function, expecting
FP ← Ra, Ra← FP return address in Rb and caller’s FP in Ra




