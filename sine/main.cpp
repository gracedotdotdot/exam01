#include "mbed.h"

AnalogOut Aout(DAC0_OUT);
Serial pc( USBTX, USBRX );
AnalogIn Ain(A0);
float ADCdata;



int main(){

  float i, j;

  while(1){

    for(j=0; j<=10; j++){
        for( i=0; i<2; i+=0.05 ){

            Aout = 0.5 + 0.5*sin(i*2*3.14159*100*j);
            ADCdata = Ain;
            wait(0.1);
            pc.printf("%1.3f\n", ADCdata);
        }
        wait(0.5);
    }

  }

}