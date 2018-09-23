#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "libminibmp.h"

#define XSIZE 800
#define YSIZE 600



#define PI 3.141593
#define PYLEN 52

int main()
{

    int i, j,z, innen = 0, aussen = 0;
    bmp mybmp1;
    mybmp1 = newBMP(1200, 800);

    BMPclear(mybmp1, COL_white);


int polygon_x [PYLEN] = {571 , 523 , 484 , 411 , 337 , 331 , 295 , 237 , 229 , 141 ,
65 , 65 , 133 , 90 , 146 , 235 , 140 , 64 , 61 , 184 ,
119 , 154 , 238 , 264 , 221 , 196 , 274 , 282 , 310 , 285 ,
353 , 321 , 423 , 515 , 622 , 775 , 806 , 790 , 791 , 715 ,
622 , 673 , 615 , 612 , 636 , 626 , 651 , 649 , 628 , 573 ,
610 , 571};

int polygon_y [PYLEN] = {134 , 506 , 313 , 373 , 520 , 349 , 189 , 189 , 286 , 291 ,
307 , 415 , 472 , 585 , 611 , 624 , 689 , 674 , 747 , 773 ,
734 , 711 , 676 , 611 , 519 , 372 , 370 , 525 , 609 , 716 ,
753 , 566 , 561 , 735 , 548 , 740 , 533 , 309 , 108 , 362 ,
389 , 194 , 197 , 260 , 223 , 212 , 207 , 229 , 320 , 347 ,
129 , 134};



double x, y, sichtwinkel, winkelsumme = 0;


    for(i=0;i<51; i++)
   {
       drawLine (mybmp1, polygon_x [i+1], polygon_y [i+1], polygon_x [i], polygon_y [i], COL_black);
   }
        drawLine (mybmp1, 806, 773, 61, 773, COL_blue);
        drawLine (mybmp1, 806, 108, 61, 108, COL_blue);
        drawLine (mybmp1, 806, 773, 806, 108, COL_blue);
        drawLine (mybmp1, 61, 773, 61, 108, COL_blue);


    for(j=0; j<100000; j++)
     {
         x=rand()%745+61;
         y=rand()%665+108;



        for(i=0; i<51; i++)
        {save_BMP("Myimage.bmp", mybmp1);
        return 0;
            sichtwinkel = atan2(polygon_y[i+1]-y,polygon_x[i+1]-x) - atan2(polygon_y[i]-y, polygon_x[i]-x);

            if (sichtwinkel>PI)
            {
                sichtwinkel = sichtwinkel - PI;
            }
            else if (sichtwinkel<-PI)
            {
                sichtwinkel = sichtwinkel + PI;
            }
            else
            {
                sichtwinkel = sichtwinkel;
            }

            winkelsumme=winkelsumme+sichtwinkel;
        }


        if (abs(winkelsumme)<(PI/2))
        {
            z=0;
            innen++; //Innenfläche um 1 vergrößern
        }
        else
        {
            z=1;
            aussen ++; // Außenfläche um 1 vergrößern
        }

        if(z==0)
        {
            setPixel(mybmp1, x, y, COL_red);
        }
        if (z==1)
        {
            setPixel(mybmp1, x, y, COL_green);
        }
     }


    int A = (806-61)*(773-108);
    double faktor = ((double)innen/((double)innen+(double)aussen));
    double ppolygon = faktor*A;



    printf("Pixelanzahl Innen %d \n", innen);
    printf("Pixelanzahl Aussen %d \n", aussen);
    printf("Faktor Innen/Gesamt %lf \n", faktor);
    printf("Flaeche Polygon %.lf squarePixel \n",  ppolygon);
    printf("Flaeche Rechteck %d squarePixel \n", A );

        save_BMP("Myimage.bmp", mybmp1);
        return 0;
}
