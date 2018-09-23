#include "Hilfs.h"
#include <stdio.h>
#include <math.h>

#define _DEMO

char text[128];

int main(void)
{
    unsigned short adcWert = 0;
    unsigned short vergleichswert[8] = {0,0,0,0,0,0,0,0};
    unsigned int counter = 0;
    unsigned short shifter = 0;
    unsigned short light = 0;
    unsigned short position = 0;
    unsigned short direction = 0;
    unsigned short a = 0;
    unsigned short b = 0;

    initAll();


    // lcd beschriften
    LCD_clear();
    lcdPrint(0, 0, "TOM");
    lcdPrint(1, 4, "ADC");

    PORTB = 0x00;

    while(1)
    {
        if(counter == adcWert)
        {
            counter = 0;
            adcWert = getAdc();
            adcWert = adcWert*2;
            sprintf(text, "%4d", adcWert);
            lcdPrint(1, 12, text);

//Richtung Bestimmen------------------------------------------------
            if (direction == 0)
            {
                position++;
                if (position == 8) direction = 1;
            }
            if (direction == 1)
            {
                position--;
                if (position == 0) direction = 0;
            }

//Lauflicht---------------------------------------------------------
        for(a=0; a <= 7; a++)
        {
            if (a == position)
            {
                vergleichswert[a]= 256;
            }
            else vergleichswert[a] = 0;
        }
//Nachlauflicht R n L------------------------------------------------
        if(direction == 0 && position >= 1)
            {
                for(b = (position-1); b >= 1; b--)
                {
                    vergleichswert[b] = vergleichswert[b+1]/2;
                    if(vergleichswert[0] == 0)
                    {
                        vergleichswert[0] = vergleichswert[1]/2;
                    }
                }
            }
//Nachlauflicht L n R----------------------------------------------
        if(direction == 1 && position <= 6)
            {
                for(b = (position+1); b <= 6; b++)
                {
                    vergleichswert[b] = vergleichswert[b-1]/2;

                    if(vergleichswert[7] == 0)
                    {
                        vergleichswert[7] = vergleichswert[6]/2;
                    }
                }
            }
        }
//Dimmen------------------------------------------------------------
        for(a = 0; a <= 7; a++)
        {
            if(counter < vergleichswert[a])
            {
                shifter = 1;
                shifter=shifter<<a;
            }
            else if (counter >= vergleichswert[a])
            {
                shifter = 0x00;
            }
            light = shifter | light;
        }

        PORTB = light;
        light = 0x00;
        delay_us(5);
        counter++;
    }
}


