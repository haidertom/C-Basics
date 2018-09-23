#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


FILE *pDatei;
FILE *eDatei;

void verschl(char *text, char *schluessel)
{
    int i=0, n=0, l=0;
    char a, b;
    //char endtext[200];
    //char endtext2[200];
    char vbit;
    //printf("text:\n%s\n", text);
   // printf("\nschluessel:\n%s\n", schluessel);

//---- Verschlüsseln ----

    for(i=0; i<(strlen(text)); i++)
    {
        if(l==(strlen("Kirschsaft!")))
           {
               l = 0;
           }

        if(text[i] < 0x20) // überprüfe ob Steuerzeichen
            {
            l++;
            continue;
            }

        vbit = (text[i])^(schluessel[l]) & (0x0F);       //text und schluessel exklusiv verodern, dann mit 0000 1111 verunden -->  ersten vier fallen weg
        text[i] = ((text[i])&(0xF0))|(vbit);            // buschstaben mit 1111 0000 verodern --> nur die vorderen vier bleiben stehen
        l++;
    }
}
   // printf("\nVerschluesseln:\n%s\n", endtext);


//---- Entlüsseln ----
/*
    for(i=0; i<(strlen(text)-1); i++)
    {
        if(text[i]<0x1F )
        {
            endtext[i] = endtext2[i];
            endtext2[i] = endtext[i];
        }
        else
        {
            a = endtext2[i];
            b = schluessel[i];
            endtext[i] = a^b;
            endtext2[i] = endtext[i];
        }
    }
    printf("\nEntschluesseln:\n%s\n\n\n", endtext);
*/



int main()
{

    //char text[]={};
    char buffer[200] = {};
    char schluessel[] = "Kirschsaft!";

    pDatei = fopen("geheim.txt", "r");
    eDatei = fopen("entschluesselt.txt", "w");

    if(pDatei == NULL)
    {
        printf("Datei konnte nicht geoeffnet werden.\n");
        return 0;
    }
    else
    {
        while (!feof(pDatei))
        {
            fgets(buffer, 200, pDatei);
            verschl(buffer, schluessel);
            fprintf(eDatei, "%s", buffer);
            printf("\n%s", buffer);
        }
    }
	return 0;
}
