#ifndef GESTORTH_H_INCLUDED
#define GESTORTH_H_INCLUDED

#include <stdio.h>
#include "function.h"
#include "gestrech.h"

#endif /* gestorth_h */


struct missingWordList{
    char missingWord;
    int* lineOfMissingWord;
    struct missingWordList* next;
};

typedef struct missingWordList missingWordList;

struct proposalList;
typedef struct proposalList proposalList;

//afficher la liste des mots du fichier n'existant pas dans le dictionnaire, ainsi que la ligne du fichier où ils sont utilisés

missingWordList* missingWord(char* filepathTxt, Dictionary* dictionary);

//afficher la liste des mots n'existant pas dans le dictionnaire et proposer une liste de mots proches (seuil deux lettres maximum) pour chacun d'entre eux

proposalList* missingWordWithProposal();

//construire automatiquement un fichier corrigé, en remplaçant les mots erronés par la première suggestion de la liste (seuil une lettre maximum)

void createCorrectedFile();

LinkedList* addElementMissingWordList(LinkedList* liste, char* newValue);

int* positionMissingWord(char* filePath, char* word);
#endif // GESTORTH_H_INCLUDED
