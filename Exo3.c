#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int data;
int rodata = 12;
int bss = 0;

int function();

int main() {
    printf("data : %d", &data);
    printf("rodata : %d", &rodata);
    printf("bss : %d", &bss);
    printf("text : %d", &function);
    /* On affiche les adresses de données se situant respctivement dans la zone data, rodata, bss, et text. */
    /* data n'est pas initialisée, donc elle est dans data; */
    /* rodata est initialisée, donc elle est dans rodata; */
    /* bss est initialisée à 0, donc elle est dans bss; */
    /* function est une fonction, donc elle est dans text. */
    int a = 0;
    int b = 1;
    /* On crée deux variables locales, qui vont donc être mises sur la pile. */
    printf("stack a : %d", &a);
    printf("stack b : %d", &b);
    /* Si l'adresse de b est plus grande que celle de a, la pile est remplie vers le haut. */
    /* Sinon, la pile est remplie vers le bas. */
    void * heap = malloc(8);
    /* Le malloc ajoute une variable sur le tas. */
    printf("heap : %d", heap);
    /* L'adresse de cette variable permet de connaître la position du tas par rapport aux autres zones de données.*/
}

int function() {
    return 0;
}

/* Réponses :
data : -729923560rodata : -729923568bss : -729923556text : -729935229stack a : 600360728stack b : 600360732heap : -729848144
- la pile est remplie vers le haut.
- l'ordre des sections est le suivant (du bas vers le haut) : bss, data, rodata, text, heap.
*/