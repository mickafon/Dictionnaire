#include <stdio.h>
#include <stdlib.h>

#include "gestbib.h"
#include "gestbib.h"    // Partie 1
#include "gestrech.h"   // Partie 2
#include "gestorth.h"   // Partie 3
#include "gestexpr.h"   // Partie 4

int main(){

    printf("Hello World !");
    char filepath_txt[] = "documents/texte1.txt";
    char filepath_dico[] = "documents/dico1.txt";

    printf("---------------PARTIE 1-----------------\n");
    Dictionary* dico_liste = NULL;
    dico_liste = readFile(filepath_dico, 1);
    displayLinkedList(dico_liste->liste);
    printf("--------------------------------\n");
    Dictionary* dico_txt = NULL;
    dico_txt = readFile(filepath_txt, 0);
    displayLinkedList(dico_txt->liste);

    printf("--------------PARTIE 2------------------\n");
    //TEST PARTIE 2 :
    LinkedList* liste_mot = NULL;
    liste_mot = findSimilarWord(dico_liste, "ENANAS", 5);
    displayLinkedList(liste_mot);

    return 0;
}
