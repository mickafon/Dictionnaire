#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestorth.h"

/* PARTIE 3 : PROPOSITION DE CORRECTION */

void addElementMissingWordList(MissingWordList* liste, char* value, int* lines)
{
    
    MissingWordList* newElement = malloc(sizeof(MissingWordList));
    
    strcpy(newElement->missingWord, value);
    
    newElement->lineOfMissingWord = lines;
    newElement->next = liste;
    //return newElement;
}

int* positionMissingWord(char* filePath, char* word){
    int size = 0; // taille tableau occurence
    FILE f = fopen(filpath,"r");
    
    LinkedList* dico = dictionary->list;
    LinkedList* text = fileTxt->list;
    
    while(dico != NULL){
        while(text != NULL){
            if(strcmp(dico->value,text->value) =! 0){
                size++;
            }
            text->next;
        }
        dico->next;
    }
    
    int* lines[size];
    int incr = 0;
    int line = 1;
    
    while(dico != NULL){
        while(text != NULL){
            if(strcmp(dico->value,text->value) =! 0){
                if(strcmp(text->value,"\n") =! 0){
                    line++
                }
                else{
                    lines[incr] = line;
                    incr++;
                }

            }
            text->next;
        }
        dico->next;
    }
    return lines;
}

missingWordList* missingWord(Dictionary* fileTxt, Dictionary* dictionary) {
    LinkedList* dico = dictionary->list;
    LinkedList* text = fileTxt->list;
    
    missingWordList* list = null;
    
    while(dico != NULL){
        while(text != NULL){
            if(strcmp(dico->value,text->value) =! 0){
                int* lines = positionMissingWord(fileTxt->filepath,text->value);
                addElementMissingWordList(list,text->value,lines);
            }
            text->next;
        }
        dico->next;
    }

    return miss;
}

proposalList* missingWordWithProposal() {
    proposalList* list;
    return list;
}

void createCorrectedFile();
