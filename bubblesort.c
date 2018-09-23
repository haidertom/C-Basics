#include <stdio.h>
#include <stdlib.h>


// BubbleSort


/*int a[8];

void eingabe()
{


    int i;

    for( i=0; i<8; i++)
    {
        printf("Bitte geben sie Zahl %d ein", i+1);
        scanf("\n %d", &a[i]);

    }

    return a;

}

void sort()
{

    int i, j;

    for(j=1; j<=7; j++)
    {
        for(i=0; i<=6;i++)
        {
            if(a[i]>a[i+1])
            {
            int tmp = 0;
            tmp = a[i];
            a[i] = a[i+1];
            a[i+1] = tmp;
        }
    }
}

return 0;

}

void ausgabe()
{
int i;
for(i=0; i<8; i++)
    {
    printf("\n %d", a[i]);
    }
}


int main()
{
    eingabe();
    sort();
    ausgabe();

    return 0;
}

*/
// Gluecksspiel



void eingabe()
{


    int array1[9];
    int i, g;


        for(i=1; i<=3; i++)
        {
            printf("Spieler 1, bitte geben sie Zahl %d ein", i);
            scanf("\n %d", &array1[i]);
        }


        for(i=4; i<=6; i++)
        {
            printf("Spieler 2, bitte geben sie Zahl %d ein", i-3);
            scanf("\n %d", &array1[i]);
        }


        for(i=7; i<=9; i++)
        {
            printf("Spieler 3, bitte geben sie Zahl %d ein", i-6);
            scanf("\n %d", &array1[i]);
        }




    printf("Geben sie die Gewinnerzahl ein");
    scanf("%d", &g);






    if (g == array1[1] | g == array1[2] | g == array1[3])
        {
            printf("Der Gewinner ist Spieler 1");
        }
    else if (g == array1[4] | g == array1[5] | g == array1[6])
        {
            printf("Der Gewinner ist Spieler 2");
        }
    else if  (g == array1[7] | g == array1[8] | g == array1[9])
        {
            printf("Der Gewinner ist Spieler 3");
        }
    else
        {
            printf("Falsche Eingabe");
        }


}



int main()
{
    eingabe();


    return 0;
}

