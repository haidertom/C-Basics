#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fp;
int i, j;
float w1, whelp1, whelp2, erw = 0, erwhelp, var, A=0;
int azahlen[900] = {{0}};
int anzahl[6];
float wahrscheinlich[6];
int temp;



int zahlenerzeugen()
{
    fp = fopen("abc.txt", "w");

    if(fp == NULL)
        {
        printf("Datei konnte nicht geoeffnet werden.\n");
        return 0;
        }


    for(i=0; i<=100; i++) // Dokument mit 300 Zufallszahlen erzeugen
        {
            fprintf(fp,"%d\n", rand()%6+1);
        }
    fclose(fp);
    return ;
}

int zahleneinlesen()
{
    fp = fopen("abc.txt", "r");

    if(fp == NULL)
        {
        printf("Datei konnte nicht geoeffnet werden.\n");
        return 0;
        }

    for(i=0; i<=100; i++) // Dokument in array einlesen
        {
            fscanf(fp,"%d\n", &azahlen[i]);
            //printf("%d\n", azahlen[i]);
        }
    fclose(fp);
    return 0;
}

int berechnunganzahl()
{
    for(i=0; i<=100; i++)
    {
        if (azahlen[i] == 1)
        {
            anzahl[0]++;
        }
        if (azahlen[i] == 2)
        {
            anzahl[1]++;
        }
        if (azahlen[i] == 3)
        {
            anzahl[2]++;
        }
        if (azahlen[i] == 4)
        {
            anzahl[3]++;
        }
        if (azahlen[i] == 5)
        {
            anzahl[4]++;
        }
        if (azahlen[i] == 6)
        {
            anzahl[5]++;
        }
    }
    return 0;
}

int wahrscheinlichkeit()
{
    for(i=0; i<6; i++)
    {
    whelp1 = anzahl[i];
    whelp2 = whelp1/100;
    printf("Wahrscheinlichkeit fuer die Zahl %d ist : %f \n",i+1, whelp2);
    wahrscheinlich[i] = whelp2;                                                 //Wahrscheinlichkeit in array speichern
    }

    return 0;
}

int erwartungswert()
{
    for(i=0; i<6; i++)
    {
    whelp2 = wahrscheinlich[i];

    erwhelp = whelp2*(i+1);
    erw = erw + erwhelp;                                                     // Erwartungswert =Summer aller  (Augenzahl * Wahrscheinlichkeit)
    }
    printf("\nDer Erwartungswert ist: %f\n\n", erw);

    return 0;
}

int autokorrel()
{


    for(i=0; i<6; i++)
    {
        whelp2 = wahrscheinlich[i];
        var = var+((i-erw)*(i-erw)*whelp2);
    }
    printf("Die Varianz ist: %f\n\n", var);

    for(j=2; j<=6;j++)
    {
        for(i=0; i<(100-j); i++)
        {
            A=A+((azahlen[i+j]-erw)*(azahlen[i]-erw));
        }
        A=A/((100-j)*var);
        printf("Autokorrleationskoeffizient %d ist %f\n", j, A);
    }


}

int main()
{
    zahlenerzeugen();
    zahleneinlesen();
    berechnunganzahl();
    wahrscheinlichkeit();
    erwartungswert();
    autokorrel();

    return 0;
}
