#include "mbed.h"
#include "tsi_sensor.h"

/* This defines will be replaced by PinNames soon */
#if defined (TARGET_KL25Z) || defined (TARGET_KL46Z)
  #define ELEC0 9
  #define ELEC1 10
#elif defined (TARGET_KL05Z)
  #define ELEC0 9
  #define ELEC1 8
#else
  #error TARGET NOT DEFINED
#endif

Timer t;


int main()
{
    TSIAnalogSlider tsi(ELEC0, ELEC1, 40);
    PwmOut led(LED_GREEN);
    
    printf("\rBegin Program\n");
    while(1){
        t.reset();
        led = 1;
        if (tsi.readPercentage() > 0){
            wait(0.1);
            t.start();
            led = 0;
            printf("\rStart Timer\n");
            
            while(tsi.readPercentage() != 0){}
            led = 1;
            t.stop();
            printf("\rStop Timer\n");
            printf("\rThe time taken was %f seconds\n\n", t.read());
        }
        
    
    
        
    }
}
