#include <stdio.h>
#include <stdlib.h>





void printBitLine(unsigned short us)
{
    int i;
    for(i=0; i<16; i++)
    {
        if(us & (0x8000>>i))
            printf("O");
        else
            printf("-");
    }
    printf("\n");
}







int main()
{

unsigned short us[16];

us[0]=0x0002;
us[1]=0x7ffc;
us[2]=0x1fef;
us[3] =0x0c70;
us[4]=0x0c70;
us[5]=0x0ce0;
us[6]=0x0cc0;
us[7] =0x0f8f;
us[8]=0x0fcf;
us[9]=0x0cc0;
us[10]=0x0ce0;
us[11] =0x0c70;
us[12]=0x0c70;
us[13]=0x0ce0;
us[14]=0x1fcf;
us[15] =0x7f8f;

    us[0]= 0x0000;
    us[1]= 0x7ffc;                                                                 //EINZELSCHRITTE:
    us[2]= us[2] & 0xff00 | (us[2]&0x00f0)>>4 | (us[2]&0x000f)<<4;                //A1 sind die ersten acht Spalten, A2 die darauf folgenden vier Spalten, A3 sind die letzten vier Spalten
    us[3]= us[3] & 0xff00 | (us[3] & 0x00f0) >> 4 | (us[3] & 0x000f) << 4;        //A1 bleibt stehen wie es ist
    us[4]= us[4] & 0xff00 | (us[4] & 0x00f0) >> 4 | (us[4] & 0x000f) << 4;        //us wird so verundet, dass nur noch A2 stehen bleibt und wird dann um 4 nach rechts geshiftet
    us[5] = us[5] & 0xff00 | (us[5] & 0x00f0) >> 4 | (us[5] & 0x000f) << 4;       //us wird so verundet, dass nur noch A3 stehen bleibt und wird dann um 4 nach links geshiftet
    us[6] = us[6] & 0xff00 | (us[6] & 0x00f0) >> 4 | (us[6] & 0x000f) << 4;
    us[7] = us[7] & 0xff00 | (us[7] & 0x00f0) >> 4 | (us[7] & 0x000f) << 4;
    us[8] = us[8] & 0xff00 | (us[8] & 0x00f0) >> 4 | (us[8] & 0x000f) << 4;
    us[9] = us[9] & 0xff00 | (us[9] & 0x00f0) >> 4 | (us[9] & 0x000f) << 4;
    us[10] = us[10] & 0xff00 | (us[10] & 0x00f0) >> 4 | (us[10] & 0x000f) << 4;
    us[11] = us[11] & 0xff00 | (us[11] & 0x00f0) >> 4 | (us[11] & 0x000f) << 4;
    us[12] = us[12] & 0xff00 | (us[12] & 0x00f0) >> 4 | (us[12] & 0x000f) << 4;
    us[13] = us[13] & 0xff00 | (us[13] & 0x00f0) >> 4 | (us[13] & 0x000f) << 4;
    us[14] = us[14] & 0xff00 | (us[14] & 0x00f0) >> 4 | (us[14] & 0x000f) << 4;
    us[15] = us[15] & 0xff00 | (us[15] & 0x00f0) >> 4 | (us[15] & 0x000f) << 4;

    int i;
    for(i=0; i<16; i++)
    printBitLine(us[i]);

    return 0;
}
