#include "definitions.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
    uint16_t s1, s2, s3, s4, s5;
    char msg[160];


    while (true)
    {
        
        s1 = GPIO_PA02_Get();
        s2 = GPIO_PA03_Get();
        s3 = GPIO_PA06_Get();
        s4 = GPIO_PA07_Get();
        s5 = GPIO_PA08_Get();
         
        SYS_Initialize(NULL);
         TCC0_PWMInitialize();
         TCC0_PWMStart();
        
          if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 ==1))

        {    
              
             TCC0_PWM24bitDutySet(TCC0_CHANNEL0,30);
             TCC0_PWM24bitDutySet(TCC0_CHANNEL1,30);
        }

        

       else if ((s2 == 0) || ((s2 == 0) && (s3 == 0)))

       {

            TCC0_PWM24bitDutySet(TCC0_CHANNEL0,20);
            TCC0_PWM24bitDutySet(TCC0_CHANNEL1,45); 

       }

       

       else if ((s1 == 0) || ((s1 == 0) && (s2 == 0)))

       {

            TCC0_PWM24bitDutySet(TCC0_CHANNEL0,0);
            TCC0_PWM24bitDutySet(TCC0_CHANNEL1,45);

       }

       

       else if ((s4 == 0) || ((s3 == 0) && (s4 == 0)))

       {

          TCC0_PWM24bitDutySet(TCC0_CHANNEL0,45);
          TCC0_PWM24bitDutySet(TCC0_CHANNEL1,20);

       }

       

       else if ((s5 == 0) || ((s4 == 0) && (s5 == 0)))

       {

           TCC0_PWM24bitDutySet(TCC0_CHANNEL0,45);
           TCC0_PWM24bitDutySet(TCC0_CHANNEL1,0);

       }

       

       else

       {

         TCC0_PWM24bitDutySet(TCC0_CHANNEL0,0);
         TCC0_PWM24bitDutySet(TCC0_CHANNEL1,0);

       }
         
        for (volatile uint32_t d = 0; d < 2000000; d++);
        
    }

    return 0;
}