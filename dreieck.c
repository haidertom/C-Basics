#include <stdio.h>
#include <stdlib.h>

int main()
{



double Seitea , Seiteb, Seitec , Flaeche, Umfang;

//Eingabe
    printf ("Bitte Seiten A, B eingeben \n") ;
    scanf ("%lf %lf", &Seitea, &Seiteb);

//Berechne
    Flaeche = (Seitea*Seiteb)*0.5;
    Seitec = sqrt((Seitea*Seitea)+(Seiteb*Seiteb));

    Umfang = Seitea+Seiteb+Seitec;

//Ausgeben
    if(Flaeche <= 10)
    {
        printf ("\nLaenge = %0.1lf", Seitea);
        printf ("\nBreite = %lf", Seiteb);
        printf ("\nSeite C = %lf\n", Seitec);
        printf ("\nFlaeche = %lf", Flaeche);
        printf ("\nUmfang = %g\n",Umfang);
    }


    else
    {
        printf("anderer Text");
    }
return 0;
}
