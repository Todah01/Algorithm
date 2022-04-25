#ifndef __BitSet
#define __BitSet

typedef unsigned long BitSet;

#define BitSetNull (BitSet)0;
#define BitSetBits 32
#define SetOf(no) ((BitSet)1 <<(no))

int IsMember(BitSet s, int n);

void Print(BitSet s);

void PrintLn(BitSet s);
#endif