#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestbib.h"
#include "gestrech.h"

/* PARTIE 2 : RECHERCHE AVANCEE */
LinkedList* SpecificListToSimpleList(SpecificLinkedList* SpecificListe)
{
    LinkedList* liste = NULL;

    while(SpecificListe != NULL) {
        liste = addElement(liste, SpecificListe->char_value);
        SpecificListe = SpecificListe->next;
    }

    return liste;
}

void orderSpecificLinkedList(SpecificLinkedList* liste)
{
    SpecificLinkedList* c_liste;
    SpecificLinkedList* counter;
    SpecificLinkedList* min;
    char char_tmp[40];
    int int_tmp;

    for(c_liste = liste; c_liste->next != NULL; c_liste = c_liste->next){
        min = c_liste;

        for(counter = c_liste->next; counter != NULL; counter = counter->next){
            if (counter->int_value > min->int_value){
                min = counter;
            } else if (counter->int_value == min->int_value) {
                if(order_word(counter->char_value, min->char_value) == 2){
                    min = counter;
                }
            }

        }

        strcpy(char_tmp, c_liste->char_value);
        int_tmp = c_liste->int_value;
        strcpy(c_liste->char_value,  min->char_value);
        c_liste->int_value = min->int_value;
        strcpy(min->char_value, char_tmp);
        min->int_value = int_tmp;

    }


}

SpecificLinkedList* addSpecificElement(SpecificLinkedList* liste, char* char_newvalue, int int_newvalue)
{
    SpecificLinkedList* newElement = malloc(sizeof(SpecificLinkedList));

    strcpy(newElement->char_value, char_newvalue);
    newElement->int_value = int_newvalue;
    newElement->next = liste;

    return newElement;
}

LinkedList* findSimilarWord(Dictionary* dico, char* word, int seuil)
{
    //Initialisation
    unsigned int count = 0;
    int taille_word = strlen(word);
    int taille_motdico = 0;
    int i = 0;
    LinkedList* dico_liste = dico->liste;
    SpecificLinkedList* tmp = NULL;
    word = strupr(word);

    //Parcours de la liste
    while(dico_liste != NULL){
        count = 0;
        taille_motdico = strlen(dico_liste->value);

        if (taille_motdico != taille_word)
            count = strcmp(word, dico_liste->value);

        if (taille_word <= taille_motdico) {
            for (i = 0; i < taille_motdico; i++){
                if(word[i] != dico_liste->value[i])
                    count++;
            }
        } else {

            for (i = 0; i < taille_word; i++){
                if(word[i] != dico_liste->value[i])
                    count++;
            }

        }

        //Si le nombre de différence entre les mots est inférieur ou égal au seuil
        if(count <= seuil){
            tmp = addSpecificElement(tmp, dico_liste->value, count);
        }

        dico_liste = dico_liste->next;
    }

    //tri de la liste
    if (tmp != NULL)
        orderSpecificLinkedList(tmp);

    LinkedList* result = NULL;
    result = SpecificListToSimpleList(tmp);

    return result;

}
