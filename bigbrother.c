#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMEN 255


int main()
{
    char InputBuffer[MAX_NAMEN];
    char *namen[MAX_NAMEN];
    int zaehler[MAX_NAMEN];

    int n = 0;
    int j = 0;
    int eingetragen = 0;
    int sort;
    int temp1;
    char *temp2;
    char Eing_Name[15];

    for(j = 0; j < MAX_NAMEN; j++){zaehler[j] = 1;};            //Jedem Namen die Anzhal 1 zuweisen

    FILE* pDatei;
    pDatei = fopen(".\\Vornamen.txt","r");                 //relative Pfadangabe



    while(fscanf(pDatei, "%s", InputBuffer)!=EOF)
    {

      //Vergleich ob Name schon im Pointer eingetragen ist

        for(j = 0; j < (eingetragen); j++)                  //dadurch wird der erste Name ausgelassen, da kein Vergleich vorhanden
        {
            if (strcmp(namen[j], InputBuffer) == 0)         //Vergleich des Namen mit den schon eingetragenen Pointern ( wenn == 0 dann bereits vorhanden)
            {
                zaehler[j]++;                               //zählt Anzahl des Namens hoch
                break;                                      //Abbruch der Schleife
            }
        }


        //Namen eintragen

        if ((j == eingetragen)&&(eingetragen < (MAX_NAMEN-1)))          //verhindert das bereits hochgezählte Namen nochmals eingetragen werden
        {
            namen[eingetragen] = (char *)malloc(strlen(InputBuffer)+1); //Reservierung des Speichers an dem momentanen Eintragungswert
            strcpy(namen[eingetragen], InputBuffer);                    //einkopieren des Namens in die Stelle
            eingetragen++;                                              //Eintrag um 1+ , da neuer Name eingetragen wurde
        }
    }



    //Namen ordnen mit Bubblesort

    sort = 1;
    while (sort == 1)
    {
        sort = 0;
        for(j = 0;j < eingetragen; j++)
        {
            if(zaehler[j] < zaehler[j+1])
            {
                temp1 = zaehler[j];         //Anzahl der einzelnen Namen nach Größe ordnen
                temp2 = namen[j];           //Parralel dazu tauschen der Namen an die richtige Stelle

                zaehler[j] = zaehler[j+1];  //Zuweisung von einer Stelle in die andere
                namen[j] = namen[j+1];

                zaehler[j+1] = temp1;       //Einfügen der Temporaeren Variablen in die Stelle
                namen[j+1] = temp2;


                sort = 1;
            }
        }
    }

    //Anzeigen der Namen

    for(j = 0;j < eingetragen; j++)
    {
        //strcpy(Eing_Name, namen[j]);
        printf("\n%i mal Nummer %i---%s---",zaehler[j], j, namen[j]);
    }

    //Name suchen

    printf("\n\n Vornamen eingeben: ");
    scanf("%s", Eing_Name);                           //Einlesen des gewünschten Namen

    for(j = 0; j < eingetragen; j++)
    {
        if (strcmp(namen[j],Eing_Name) == 0)             //Namen gleich
        {
            printf ("\n %s", Eing_Name);
            printf("\n Stelle %i", j);
            printf("\n Anzahl %i", zaehler[j]);
            n=1;                                        // Name vorhanden
        }
    }

    if (n == 0)                                         // Name nicht vorhanden
    {
        printf("\nDer eingegebene Name %s ist nicht vorhanden!\n", Eing_Name);    //Ausgabe falls Name nicht vorhanden
    }

    fclose(pDatei);

    return 0;
}
