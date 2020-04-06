#include "mbed.h"


Serial pc( USBTX, USBRX );

AnalogIn Ain(A0);

float ADCdata;


int main(){

  while(1){

    ADCdata = Ain;

    wait(0.1);

    pc.printf("%1.3f\r\n", ADCdata);

  }

}