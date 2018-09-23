#include <stdio.h>
#include <stdlib.h>




   int i = 0;
   int *pi = 0;


   short *ps = 0;
   char *pc = 0;

   int *vi[]={0,1,2,3};
   char *vc[] ={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o"};

    int const lit_i =0x4321;
    // 2.2 Literalkonstante


void set4711(int *pi)
{
    printf("\nIn 4711 Vor Zuweisung:\n Adresse von pi: %p\ Wert der Zieladresse von pi: %i",pi,*pi);

    *pi = 4711;
    printf("\nIn 4711 Nach Zuweisung:\n Adresse: %p Wert der Zieladresse von pi: %i\n",pi,*pi);

}

void set4712(int i) //i wird temporär in Stack gespeichert, Stack wird verändert, i nicht
{
    printf("\nIn 4712 Nor Zuweisung:\n Adresse von i: %p Wert der Zieladresse von i: %i",&i,i);

    i = 4712;
    printf("\nIn 4712 Nach Zuweisung:\n Adresse von: %p Wert der Zieladresse von i: %i\n",&i,i);

}



int main()
{


i = lit_i;
pi = &i;


// 2.3
    printf("Wert von i: %d\n", i);
    printf("Adresse von i: %p\n\n", &i);

    printf("Wert der Pointervariablen: %d\n", pi);
    printf("Adresse von pi: %p\n\n", &pi);



// 2.4

// e)
/*
    ps=&i;      //funktioniert nicht da i unter integer gespeichert ist, und ps bzw. pc unter char
    pc=&i;
*/

//f)


    ps=(short*)&i;      //Typumwandlung --> funktioniert
    pc=(char*)&i;       //Typumwandlung --> funktioniert nicht



    printf("Ueber Namen: %d\n", i);
    printf("Ueber Pointer pi: %d\n", *pi);
    printf("Ueber Pointer ps: %d\n", *ps);
    printf("Ueber Pointer pc: %c\n", *pc); //33?

//g)

    int const lit_pi=0x4433;
    *ps=lit_pi;

    printf("\ni ueber ps:%i\n", i); //Wo ändere ich i?

//h)
    char const lit_pc=('X');
    *pc=lit_pc;

    printf("\ni ueber pc:%i\n", i);

// 2.5

// i)
    printf("\nAdresse vi: %i\n", vi);
    printf("Adresse vc: %c\n", vc); //?

// j)


    pi=&vi[0];
    pc=&vc[0];

    printf("\nWert von vc[0] ueber pc ist %c\n",*pc); //ist d
    printf("Wert von vi[0] ueber pi ist %i\n",*pi);   //ist 0

//k)

    pi=vi;
    pc=vc;

    printf("\nWert von vc ueber pc ist %c\n",*pc); //ist d
    printf("Wert von vi ueber pi ist %i\n",*pi);   //ist 0

//l)

    pc++;
    pi++;
    printf("\nWert von pc ist %p\n",pc);    // Frage: Wert = Zieladresse?
    printf("Wert von pi ist %p\n",pi);
    printf("Adresse von pc ist %i\n",&pc);
    printf("Adresse von pi ist %i\n",&pi);

//m)

    printf("\nWert nach ++ von pc ist %c\n",*pc); // char kann man nicht inkrementieren
    printf("Wert nach ++ von pi ist %i\n",*pi);

//n)

    printf("\nWert von i: %i\n",i);
    set4711(&i);
    printf("\nWert von i: %i\n\n",i);

//o)

    set4712(i);
    printf("\nWert von i: %i\n",i);

  return 0;
}











/*
int main()                                      // Internet-Versuch
{
    int zahl=7;
    int *zeiger = &zahl;

    printf("Adresse zahl: %p\n", &zahl);
    printf("Wert zahl: %d\n\n", zahl);

    printf("Adresse zeiger: %p\n", &zeiger);
    printf("Zieladresse: %p\n\n", zeiger);

    printf("Wert der Zieladresse:%d \n", *zeiger);
}
*/
