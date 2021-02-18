#include "fft.h"
//#include "fft.c"

void generate_sine_wave( int array[], int f1, int f2, int a1, int a2){
	unsigned int i;
	double t;
  float Fs = 512.0;
	t=0;
	for (i=0;i<N;i++){
		array[i] = (((double) a1 * sin(TWO_PI*f1*t)) + ((double) a2 * sin(TWO_PI*f2*t)));
		t+=1.0/Fs;
	}

}

#define HW_COSIM 1;
int main(){
	unsigned int i;
	const unsigned int MAXBINS = SPECTRUM_SIZE, MINBINS = 0;
	double absolute;
  //FILE *fp;
	//fp = fopen("sine.txt","w");
// input sequence for which fft is to be calculated
  int re_sw[N] ,im_sw[N], re_hw[N] , im_hw[N];


	int a1 = 100;
	int a2 = 10 ;
	int f1 = 100 ;
	int f2 = 50 ;

 generate_sine_wave(re_sw, f1, f2, a1, a2);
 generate_sine_wave(re_hw, f1, f2, a1, a2);

  int err_cnt = 0 ;
  for(i = 0 ; i < N ; i++)
	{
    im_sw[i] = 0 ;
    im_hw[i] = 0 ;
	}
	//////
  fft(re_sw,im_sw);

  unsigned int power_spectrum[N];
  #ifdef HW_COSIM
  fft(re_hw,im_hw);
  #endif


  for (int i = 0 ; i < N ; i++)
  {
    power_spectrum[i]=((double)re_hw[i]*(double)re_hw[i])+((double)im_hw[i]*(double)im_hw[i]);
    printf("%d+i%d S: %d \n",re_hw[i],im_hw[i],power_spectrum[i]);

  }
  #ifdef HW_COSIM

  for(i = 0; i < N; i++){
    if((re_sw[i] != re_hw[i]) && (im_sw[i] != im_hw[i]))
       err_cnt = err_cnt + 1 ;
      }
 if(err_cnt > 0)
   {
     printf("\n------SIMULATION FAILED------\n");
     return 1 ;
   }
  else
  {
         printf("\n-------SIMULATION PASSED -----\n");
         return 0;
  }
 #endif
	//fclose(fp);
printf("\n------- HARDWARE NOT INVOKED -----\n");
return 0;
}
