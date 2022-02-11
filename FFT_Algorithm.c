// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

typedef struct
{
    float Re;
    float Im;
}Z_Value;

typedef struct
{
    Z_Value y[32768];
    
}Z_Value_arr;

#define PI 3.141592653

Z_Value_arr Fast_transform(float *p,unsigned int n);

int main() {
    int l;  //= 16;
    float magnitude[32768],FFT_Magnitude_output[32768],FFT_Phase_output[32768];
    // float arr[] = {0,0.707107,1,0.707107,0,-0.707107,-1,-0.707107,
    //     0,0.707107,1,0.707107,0,-0.707107,-1,-0.707107,
    //     0,0.707107,1,0.707107,0,-0.707107,-1,-0.707107,
    //     0,0.707107,1,0.707107,0,-0.707107,-1,-0.707107
    // };
    float angle = 2*(float)PI/32,
        first_har = 0.95,//sqrt(5)-1,
        third_har = 0.26,//sqrt(2)-1,
        fifth_har = sqrt(3)-1,
        phase3 = (-2*PI/3),
        phase5 = (PI/6);
    float arr[] = {
first_har*sin(angle*0) + (third_har*sin((3*angle*0)+phase3)) + (fifth_har*sin((5*angle*0)+phase5)),
first_har*sin(angle*1) + (third_har*sin((3*angle*1)+phase3)) + (fifth_har*sin((5*angle*1)+phase5)),
first_har*sin(angle*2) + (third_har*sin((3*angle*2)+phase3)) + (fifth_har*sin((5*angle*2)+phase5)),
first_har*sin(angle*3) + (third_har*sin((3*angle*3)+phase3)) + (fifth_har*sin((5*angle*3)+phase5)),
first_har*sin(angle*4) + (third_har*sin((3*angle*4)+phase3)) + (fifth_har*sin((5*angle*4)+phase5)),
first_har*sin(angle*5) + (third_har*sin((3*angle*5)+phase3)) + (fifth_har*sin((5*angle*5)+phase5)),
first_har*sin(angle*6) + (third_har*sin((3*angle*6)+phase3)) + (fifth_har*sin((5*angle*6)+phase5)),
first_har*sin(angle*7) + (third_har*sin((3*angle*7)+phase3)) + (fifth_har*sin((5*angle*7)+phase5)),
first_har*sin(angle*8) + (third_har*sin((3*angle*8)+phase3)) + (fifth_har*sin((5*angle*8)+phase5)),
first_har*sin(angle*9) + (third_har*sin((3*angle*9)+phase3)) + (fifth_har*sin((5*angle*9)+phase5)),
first_har*sin(angle*10) + (third_har*sin((3*angle*10)+phase3)) + (fifth_har*sin((5*angle*10)+phase5)),
first_har*sin(angle*11) + (third_har*sin((3*angle*11)+phase3)) + (fifth_har*sin((5*angle*11)+phase5)),
first_har*sin(angle*12) + (third_har*sin((3*angle*12)+phase3)) + (fifth_har*sin((5*angle*12)+phase5)),
first_har*sin(angle*13) + (third_har*sin((3*angle*13)+phase3)) + (fifth_har*sin((5*angle*13)+phase5)),
first_har*sin(angle*14) + (third_har*sin((3*angle*14)+phase3)) + (fifth_har*sin((5*angle*14)+phase5)),
first_har*sin(angle*15) + (third_har*sin((3*angle*15)+phase3)) + (fifth_har*sin((5*angle*15)+phase5)),
first_har*sin(angle*16) + (third_har*sin((3*angle*16)+phase3)) + (fifth_har*sin((5*angle*16)+phase5)),
first_har*sin(angle*17) + (third_har*sin((3*angle*17)+phase3)) + (fifth_har*sin((5*angle*17)+phase5)),
first_har*sin(angle*18) + (third_har*sin((3*angle*18)+phase3)) + (fifth_har*sin((5*angle*18)+phase5)),
first_har*sin(angle*19) + (third_har*sin((3*angle*19)+phase3)) + (fifth_har*sin((5*angle*19)+phase5)),
first_har*sin(angle*20) + (third_har*sin((3*angle*20)+phase3)) + (fifth_har*sin((5*angle*20)+phase5)),
first_har*sin(angle*21) + (third_har*sin((3*angle*21)+phase3)) + (fifth_har*sin((5*angle*21)+phase5)),
first_har*sin(angle*22) + (third_har*sin((3*angle*22)+phase3)) + (fifth_har*sin((5*angle*22)+phase5)),
first_har*sin(angle*23) + (third_har*sin((3*angle*23)+phase3)) + (fifth_har*sin((5*angle*23)+phase5)),
first_har*sin(angle*24) + (third_har*sin((3*angle*24)+phase3)) + (fifth_har*sin((5*angle*24)+phase5)),
first_har*sin(angle*25) + (third_har*sin((3*angle*25)+phase3)) + (fifth_har*sin((5*angle*25)+phase5)),
first_har*sin(angle*26) + (third_har*sin((3*angle*26)+phase3)) + (fifth_har*sin((5*angle*26)+phase5)),
first_har*sin(angle*27) + (third_har*sin((3*angle*27)+phase3)) + (fifth_har*sin((5*angle*27)+phase5)),
first_har*sin(angle*28) + (third_har*sin((3*angle*28)+phase3)) + (fifth_har*sin((5*angle*28)+phase5)),
first_har*sin(angle*29) + (third_har*sin((3*angle*29)+phase3)) + (fifth_har*sin((5*angle*29)+phase5)),
first_har*sin(angle*30) + (third_har*sin((3*angle*30)+phase3)) + (fifth_har*sin((5*angle*30)+phase5)),
first_har*sin(angle*31) + (third_har*sin((3*angle*31)+phase3)) + (fifth_har*sin((5*angle*31)+phase5)),
    
    };
    // float arr[] = {0,1,0.5857864376,1,0,-1,-0.5857864376,-1,
    //     0,1,0.5857864376,1,0,-1,-0.5857864376,-1,
    //     0,1,0.5857864376,1,0,-1,-0.5857864376,-1,
    //     0,1,0.5857864376,1,0,-1,-0.5857864376,-1
    // };
    l = sizeof(arr)/sizeof(float);
    // float arr[] = {0,1,0,-1,0,1,0,-1};
    // float arr[] = {0.5,1,0.5,0,0.5,1,0.5,0};
    // float arr[] = {0,1,0,-1};
    // float arr[] = {0.707,0.707,-0.707,-0.707};//,0,1,0,-1};
    // float arr[] = {1,-1,1,-1};//,0,-1,0,1,0,-1};
    Z_Value_arr FFT_output;
    FFT_output = Fast_transform(arr,l);
    for(int i = 0;i<l;i++)
    {
        printf("%f\t%f\n",FFT_output.y[i].Re,FFT_output.y[i].Im);
    }
    printf("\nBelow_nyquist_frequency\n");
    for(int i = 0;i<l;i++)
    {
        magnitude[i] = sqrt(FFT_output.y[i].Re*FFT_output.y[i].Re + 
                        FFT_output.y[i].Im*FFT_output.y[i].Im);
        FFT_Phase_output[i] = atan2(FFT_output.y[i].Im,FFT_output.y[i].Re) + (PI/2);
        
        if(FFT_Phase_output[i]>PI)
        {
            FFT_Phase_output[i] = FFT_Phase_output[i] - (2*PI);
        }
    
    }
    for(int i = 0;i<(l>>1);i++)
    {
        FFT_Magnitude_output[i] = (magnitude[i] + magnitude[l-i])/l;
    }
    printf("Harmonic\tMagnitude\tPhase\n");
    for(int i = 0;i<(l>>1);i++)
    {
    printf("   %d\t\t%f\t%f\n",i,(FFT_Magnitude_output[i]),FFT_Phase_output[i]);
    }
    return 0;
}

Z_Value_arr Fast_transform(float *p,unsigned int n)
{
    float arg,Pe[16384],Po[16384],cos_val,sine_val;
    Z_Value_arr y,ye,yo;
    // printf("new\n");
    if(n==1)
       {
          y.y[0].Re = *p;
          y.y[0].Im = 0;
          return y;
       }
    for(int j =0;j<(n>>1);j++)
    {
        Pe[j] = *(p+(j<<1));// *(p+i);
        // printf("%d\t%f\n",i,Pe[j]);
    }
     for(int j =0;j<(n>>1);j++)// for(int i =1,j =0;i<n;i+=2,j++)
    {
        Po[j] = *(p+((j<<1) + 1));
        // printf("%d\t%f\n",i,Po[j]);
    }
    ye = Fast_transform(Pe,n>>1);
    // printf("Even completed\n");
    yo = Fast_transform(Po,n>>1);
    // printf("odd completed\n");
    // y.y[0].Re = 0;
    // y.y[0].Im = 0;
    for(int j = 0;j<(n>>1);j++)
    {
        arg =  (-2.0 * PI * (double) j )/ (double) n;
        cos_val = cos(arg);
        sine_val = sin(arg);
        // printf("omega %f\t%f\n",cos_val,sine_val);
        // y.y[j].Re = ye.y[j].Re + yo.y[j].Re;
        // y.y[j].Im = ye.y[j].Im + yo.y[j].Im;
        y.y[j].Re = ye.y[j].Re + ((yo.y[j].Re*cos_val) - (yo.y[j].Im*sine_val));
        y.y[j].Im = ye.y[j].Im + ((yo.y[j].Im*cos_val) + (yo.y[j].Re*sine_val));
y.y[j+(n>>1)].Re = ye.y[j].Re - ((yo.y[j].Re*cos_val) - (yo.y[j].Im*sine_val));
y.y[j+(n>>1)].Im = ye.y[j].Im - ((yo.y[j].Im*cos_val) + (yo.y[j].Re*sine_val));

    }
    return (y);
}