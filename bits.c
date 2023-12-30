/* 
 * CS:APP Data Lab 
 * 
 * Joshua Schuurman - joshschuurman
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 * 
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
       //set i to 0101, then shift it and make it 0101 0101, make a copy and then shift the copy, &'ing the copy and i to get the end result.
       int i;
       int s;
       
       i = 0x55;
       i = i << 8;
       i = i | 0x55;
       s = i;
       s = (s << 16) | i;
       return s;
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  //~ the integers and & them
  int x2;
  int y2;
  
  x2 = ~x;
  y2 = ~y;
  return x2 & y2;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  //int shift takes n and shifts it to the left 3, giving 0, 8, 16, or 24. Then, shift the result by int shift to get the desired byte into the LSB position, and & it with 0xFF to get only that byte.
  int shift;
  int result;

  shift = n << 3;
  result = x >> shift;
  return result & 0xFF;
}
/* 
 * tc2sm - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: tc2sm(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int tc2sm(int x) {
  //int Mask gets the sign bit, and newmask is either 0xFFFFFFFF or 0 depending on the mask. Then, xor new mask and mask to get 0xEFFFFFFF or 0xFFFFFFFF, if x was negative or positive respectively. Add is newmask & 1 so the LSB is always 1. xor y (y=x) and mask, and add add to get the result.
  int mask;
  int add;
  int y;
  int newmask;

  mask = 0x80;
  mask = mask << 24;
  mask = mask & x;
  newmask = mask >> 31;
  mask = newmask ^ mask;
  add = newmask & 1;
  y = x ^ mask;
  return y + add;
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  //mem is the n-most significant bits, shifted to the n-least significant bytes. It is then &ed with a mask of n 1's in the n least significant bits to get all zeros and the least n-most significant bits of X in the least significant bytes of mem. Ret is x shifted to the left by n bits, which is then |ed with mem to get the correct value.
  int mem;
  int ret;
  int mask;
  
  mem = x >> (32 + (~n + 1));
  ret = x << n;
  mask = ~0;
  mask = mask << n;
  mask = ~mask;
  mem = mem & mask;
  ret = ret | mem;
  return ret;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  //This one is hard to explain - shift x over by powers of 2 - (1, 2, 4, 8, and 16). For the first operation, use a mask of a series of bits 01. & that mask and the shited x over to get a "01" bit if the original 2 bis in x are 11 or 10. By subtracting that from x, we get a number that has a series of bit pairs representing how many bits were in that pair in x. Step two 
  int mask;
  int helperMask;
  int shiftedX;
  
  mask = 0x55;
  helperMask = mask << 8;
  mask = mask | helperMask;
  helperMask = mask << 16;
  mask = mask | helperMask;

  shiftedX = x >> 1;
  shiftedX = (shiftedX & mask);
  x = x + (~shiftedX + 1);

  mask = 0x33;
  helperMask = mask << 8;
  mask = mask | helperMask;
  helperMask = mask << 16;
  mask = helperMask | mask;

  shiftedX = x>>2;
  shiftedX = shiftedX & mask;
  x = shiftedX + (x & mask);
    
  mask = 0x0f;
  helperMask = mask << 8;
  mask = mask | helperMask;
  helperMask = mask << 16;
  mask = helperMask | mask;
    
  shiftedX = x >> 4;
  x = x + shiftedX;
  x = x & mask;
  
  mask = 0xff;
  helperMask = mask << 16;
  mask = mask | helperMask;
  
  shiftedX = x >> 8;
  x = x + shiftedX;
  x = x & mask;
  
  mask = 0xff;
  helperMask = mask << 8;
  mask = mask | helperMask;
  
  shiftedX = x >> 16;
  x = x + shiftedX;
  x = x & mask;

  return x;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  //returns 0x80000000
  int x;

  x = 0x80;
  return x << 0x18;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  //y is 0 if x is 0, otherwise 1; z is -1 if x is negative, otherwise 0. by using or, you get -1, 0, or 1 dependent on the sign.
  int y;
  int z;

  y = !!x;
  z = x >> 31;
  return y | z;
  
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  //Shifts x left and then right so that only the n least significant bits are remaning, leaving either all 1's and the least sig bits or all 0's and the least sig bits. Xor this with the original number to see if any of the bits have changed (information outside the n-bit number range) and return true if no information has been lost, otherwise false.
  int shift;
  int y;

  shift = 32 + (~n + 1);
  y = x << shift;
  y = y >> shift;
  return !(y ^ x);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  //mimic condition codes to mimic the setg instruction.
  int a;
  int asign;
  int b;
  int bsign;
  int t;
  int tsign;
  int of;
  int sf;
  int zf;

  a = x;
  asign = a >> 31;
  b = y;
  bsign = b >> 31;
  t = x + (~y + 1);
  tsign = t >> 31;
   
  of = (asign^bsign) & (tsign^asign);
    
  zf = !t;
  sf = !!(t >> 31);
    
  return (~(sf^of) & ~zf) & 1;
}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
  //Check if x is negative, and get te absolute value using -x = ~x + 1 if it is. Then, find the remainder of |x|%n by using a mask to grab the n-least significant bits and store it in res. If x was originally negative, convert res to -res using -x = ~x + 1;
  int pow;
  int zf;
  int add;
  int posx;
  int res;
    
  pow = 1 << 31;
  zf = x >> 31;
  add = zf & 1;
  posx = zf ^ x;
  posx = posx + add;
  pow = pow >> 31;
  pow = pow << n;
  pow = ~pow;
  res = pow & posx;
  res = res ^ zf;
  res = res + add;
  return res;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  //perform shifts on x until all bits right of the most-signficant 1 bit are 1s, then perform bit count. The result is off by one because the original most significant one bit, so return the result of bit count - 1.
  int shiftedX;
  int mask;
  int helperMask;
  
  shiftedX = x >> 1;
  x = x | shiftedX;
  shiftedX = x >> 2;
  x = x | shiftedX;
  shiftedX = x >> 4;
  x = x | shiftedX;
  shiftedX = x >> 8;
  x = x | shiftedX;
  shiftedX = x >> 16;
  x = x | shiftedX;

  mask = 0x55;
  helperMask = mask << 8;
  mask = mask | helperMask;
  helperMask = mask << 16;
  mask = mask | helperMask;

  shiftedX = x >> 1;
  shiftedX = (shiftedX & mask);
  x = x + (~shiftedX + 1);

  mask = 0x33;
  helperMask = mask << 8;
  mask = mask | helperMask;
  helperMask = mask << 16;
  mask = helperMask | mask;

  shiftedX = x>>2;
  shiftedX = shiftedX & mask;
  x = shiftedX + (x & mask);
    
  mask = 0x0f;
  helperMask = mask << 8;
  mask = mask | helperMask;
  helperMask = mask << 16;
  mask = helperMask | mask;
    
  shiftedX = x >> 4;
  x = x + shiftedX;
  x = x & mask;
  
  mask = 0xff;
  helperMask = mask << 16;
  mask = mask | helperMask;
  
  shiftedX = x >> 8;
  x = x + shiftedX;
  x = x & mask;
  
  mask = 0xff;
  helperMask = mask << 8;
  mask = mask | helperMask;
  
  shiftedX = x >> 16;
  x = x + shiftedX;
  x = x & mask;

  return x + (~1 + 1);
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  //Isolate the exponent into exp. If uf is NaN, return uf. Otherwise, return uf with a positive sign bit.
  unsigned abs;

  int exp = (uf >> 23) & 0xff;
  if((exp == 0xff) && ((uf & 0x7fffff) != 0)){
    abs = uf;
  }
  else{
    abs = uf & 0x7fffffff;
  }
  return abs;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  int exp;
  int frac;
  int fracmask;
  int expmask;

  exp = uf >> 23;
  exp = (exp & 0xff); 
  if(exp == 0xff){
    return uf;
  }
  else if(exp == 0 || exp == 1){
    frac = uf & 0xffffff;
    if((frac & 3) == 3){
	frac++;
    }
    frac = frac >> 1;
    fracmask = ~0xffffff;
    uf = uf & fracmask;
    return uf | frac;
  }
  else{
    exp = (exp & 0xff) - 1;
    exp = exp << 23;
    expmask = 0x807fffff;
    uf = uf & expmask;
    return uf | exp;
  }
}
