#include "mbed.h"
#include "uLCD_4DGL.h"

AnalogOut Aout(DAC0_OUT);
Serial pc( USBTX, USBRX );
AnalogIn Ain(A0);
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
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
    uLCD.circle(10 , 10 , 2, BLUE);

    uLCD.printf("\nGrace\n"); //Default Green on black text

    uLCD.text_width(4); //4X size text

    uLCD.text_height(4);

    uLCD.color(RED);

  }

}