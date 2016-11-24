//
//  function.c
//  Dictionnaire
//
//  Created by Ludwig Roger on 03/11/2016.
//  Copyright © 2016 LudwigRgr. All rights reserved.
//

#include "function.h"

int menu(){
    int choix = 0;
    printf("APPLICATION DE GESTION D'UN DICTIONNAIRE \n");
    printf("Menu : \n");
    printf("1 - Créer un fichier dictionnaire \n");
    printf("2 - Utiliser un dictionnaire existant \n");
    printf("3 - Créer un dictionnaire à partir d'un fichier texte \n");
    printf("4 - Supprimer un fichier dictionnaire \n");
    printf("5 - Ajouter un mot à un fichier dictionnaire \n");
    printf("6 - Rechercher un mot dans un fichier dictionnaire \n\n");
    
    while(choix < 1 || choix > 6){
        printf("Selectionner un choix : ");
        scanf("%d", &choix);
    }
    system("cls");
    return choix;
}

void start(){
    int choix = 0;
    choix = menu();
    
    switch(choix){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
    }
}

struct LinkedList {
    char* value;
    struct LinkedList* next;
};

struct Dictionary {
    char* filepath;
    struct LinkedList* list;
};

void orderList(Dictionary* _Dictionary) {
    
}

void displayDictionary(Dictionary* _Dictionary) {
    FILE* f = fopen(_Dictionary->filepath, "r+");
    char carac;
    if(f != NULL){
        while((carac = fgetc(f)) != EOF){
            printf("%c", carac);
        }
        fclose(f);
    } else{
        printf("Impossiblie d'ouvrir le fichier %s", _Dictionary->filepath);
    }
}

int checkWord(Dictionary* _Dictionary, char* word) {
    return 0;
}

Dictionary createDictionaryFromList(LinkedList* list, char* filepath) {
    Dictionary dico;
    return dico;
}

Dictionary createDictionaryFromFile(char* filepath, int isFromDictionary) {
    Dictionary dico;
    return dico;
}

Dictionary selectDictionary() {
    Dictionary dico;
    return dico;
}

void createFile(Dictionary* _Dictionary) {
    FILE* f = fopen(_Dictionary->filepath,"w");
    char* element = _Dictionary->list->value;
    
    if(f != NULL) {
        while(element != NULL) {
            fputs(strcat(_Dictionary->list->value,"\n"),f);
            element = _Dictionary->list->next->value;
        }
    }
    
}

void deleteFile(Dictionary* _Dictionary) {
    
}

Dictionary createDictionaryFromUser() {
    char word[44];
    Dictionary _dictionary;
    _dictionary.filepath = "User/Desktop/Dictionary";
    
    do {
        printf("Entrer un mot pour l'ajouter au disctionnaire, taper FIN pour terminer");
        scanf("%s",word);
        _dictionary.list->value = word;
        _dictionary.list->next = NULL;
        
    }
    while (strcmp(word,"FIN") != 0);
    
    createFile(&_dictionary);
    
    return _dictionary;
}

void insertWordInDictionary(Dictionary* _Dictionary, char* word) {
    _Dictionary->list->value = word;
    _Dictionary->list->next = NULL;
    orderList(_Dictionary);
    
    deleteFile(_Dictionary);
    createFile(_Dictionary);
}

LinkedList readFile_Dictionary(char* filepath) {
    LinkedList list;
    return list;
}

LinkedList readFile_Text(char* filepath) {
    LinkedList list;
    return list;
}
