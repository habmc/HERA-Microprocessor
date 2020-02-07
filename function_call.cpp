// CALL & RETURN with parameters on the stack (from HERA 2.4 docs)

#include <HERA.h>		/* required for HERA projects */
#include <HERA-print.h>	/* required for print_reg and print for debugging in HERA-C */

void HERA_main()
{
  // This program demonstrates function calls, using one simple
  // function to repeatedly add 2*R1+R2 into existing value of R3,
  // First with R1=100,R2=50, then with R1=10,R2=3.
  
  CBON() // Instruction 0
  SETLO(r1, 100) // Instruction 1
  SETLO(r2, 50) // Instruction 2

  // Auto-generated instructions 3&4 SETLO/SETHI(R13, updateR3)
  CALL(FP_alt, updateR3) // Instruction 5: CALL(R12, R13)
  SETLO(r1, 10) // Instruction 6
  SETLO(r2, 3) // Instruction 7

  // Auto-generated instructions 8&9 SETLO/SETHI(R13, updateR3)
  CALL(FP_alt, updateR3) // Instruction 10: CALL(R12, R13)
  HALT() // Instruction 11

  // The body of updateR3:
  // compute 2*r1 + r2, leaving the result in r3
  LABEL(updateR3)
  ADD(r1, r1,r1) // 2*r1 (Instruction 12)
  ADD(r1, r1,r2) // 2*r1+r2 (Instruction 13)
  ADD(r3, r3,r1) // r3+=2*r1+r2 (Instruction 14)
  RETURN(FP_alt, PC_ret) // go back (Instruction 15)
}
