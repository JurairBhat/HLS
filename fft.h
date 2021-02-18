#ifndef FFT_H
#define FFT_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N         1024
#define TRUE			1
#define SPECTRUM_SIZE 	N
#define FALSE			0
#define MAX_INT 		0x7FFF
#define MAX_INTBY2 		MAX_INT/2
#define minus2PI 		-6.283185307179586
#define TWO_PI 			6.283185307179586


void Init_twiddlefactors(double *);
void fft(int * ,  int *);
void bitreverse(int *,int *);
int mylog2(int);
void calculate_powerspectrum(void);
int maxindexofabsolute(void);
int twopower(int);
void rightshiftCURR(int *re,int *im,int *);
int myabs(int);
//double twiddle_arr[N];
int noofShifts = 0;

#endif
