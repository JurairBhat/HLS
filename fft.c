#include "fft.h"
void fft(int * re , int *im)
{
	double twiddle_arr[N];
	Init_twiddlefactors(twiddle_arr);
	int i,j,k,r,noofStages,n1, n2;
	double twiddle_re=0,twiddle_im=0, t1, t2;
  int noofShifts = 0 ;
	bitreverse(re,im);	// Rearrange the input samples in bitreverse order.

	noofStages = mylog2(N);			// Total number of stages in the butterfly diagram

	n1 = 0; /* FFT */
	n2 = 1;

	for (i=0; i < noofStages; i++){
		n1 = n2;
		n2 = n2 + n2;
		r=0;

		for (j=0; j < n1; j++){
			twiddle_re=twiddle_arr[r];

			if(r >= 3*N/4)                // Get the pre-calculated twiddle factor (sin(-2*pi*r/N))
				twiddle_im = twiddle_arr[r-3*N/4];
			else
				twiddle_im = twiddle_arr[r+N/4];    // Adjustment for getting sin value from pre-calculated cos value

			for (k=j; k < N; k=k+n2){
				t1 = twiddle_re*(double)re[k+n1] - twiddle_im*(double)im[k+n1];
				t2 = twiddle_im*(double)re[k+n1] + twiddle_re*(double)im[k+n1];

				if(myabs(t1) >= MAX_INTBY2 || myabs(t2) >= MAX_INTBY2){
					t1/=2;
					t2/=2;
				}

				re[k+n1] = re[k] - t1;
				im[k+n1] = im[k] - t2;
				re[k] = re[k] + t1;
				im[k] = im[k] + t2;

				if(myabs(re[k]) >= MAX_INTBY2 || myabs(im[k]) >= MAX_INTBY2 || myabs(re[k+n1]) >= MAX_INTBY2 || myabs(im[k+n1]) >= MAX_INTBY2)
					noofShifts = 1;

			}

			r=r-N/n2;
			if(r<0)
				r+=N;
		}

		if(noofShifts > 0)
				rightshiftCURR(re,im,&noofShifts);
	}
}

int twopower(int a){
       int result=1;

       for(;a>0;a--)
               result*=2;

       return result;
}

int mylog2(int n){
	int i;
	for(i=0;n>1;i++)
		n/=2;

	return i;
}

int myabs(int a){
	if (a < 0)
		return -a;
	else
		return a;
}

void bitreverse(int *x,int *y){
	int i,j,n1,n2,t1;

	j = 0;
	n2 = N/2;

	for (i=1; i < N - 1; i++){
		n1 = n2;
        for(;j >= n1 ;j -=(2*n1))
				{
          n1 = n1/2;
				}
//		while ( j >= n1 ){
//			j = j - n1;
//			n1 = n1/2;
//		}

		j = j + n1;

		if (i < j){
			t1 = x[i];
			x[i] = x[j];
			x[j] = t1;
			t1 = y[i];
			y[i] = y[j];
			y[j] = t1;
		}
	}
}

void rightshiftCURR(int * re , int *im , int * noofShifts){
	int i;

	for(i=0;i < N;i++){
		re[i] = re[i] >> (*noofShifts);
		im[i] = im[i] >> (*noofShifts);
	}

	*noofShifts = 0;
}


void Init_twiddlefactors(double *twiddle_arr){
	int i;
	for(i=0; i < N; i++)
		twiddle_arr[i] = cos(minus2PI*i/N);
}
