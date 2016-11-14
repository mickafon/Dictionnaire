#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestbib.h"

/* PARTIE 1 : CREATION ET GESTION DU DICTIONNAIRE */

//Read File
Dictionary* readFile(char* filepath, int isDictionary)
{
    Dictionary* dictionnaire = malloc(sizeof(Dictionary));
    LinkedList* liste = NULL;
    int count = 0 ;

    switch(isDictionary){
        case 0 :
            liste = readFile_Text(filepath);
            break;
        case 1 :
            liste = readFile_Dictionary(filepath);
            break;
        default :
            return dictionnaire;

    }

    count = LinkedListLenght(liste);
    dictionnaire->nb_mots = count;
    dictionnaire->liste = liste;
    dictionnaire->filepath = filepath;

    return dictionnaire;
}

LinkedList* readFile_Text(char* filepath)
{
    FILE* fichier = fopen(filepath, "r");
    int taillemax = 4000;
    LinkedList* liste = NULL;

    if (fichier != NULL){

        char* phraseLu = malloc(sizeof(char)*taillemax);

        //Lecture paragraphe fichier
        while (fgets(phraseLu , sizeof(char)*taillemax , fichier) != NULL) {
            int i = strlen(phraseLu);
            if (phraseLu[i-1] == '\n'){
                phraseLu[i-1] = '\0';
            } else {
                phraseLu[i] = '\0';
            }
            phraseLu = strupr(phraseLu);
            clear_str(phraseLu);
            liste = split_str(liste, phraseLu, "\n");
        }

    } else {
        printf("Impossible d'ouvrir le fichier");
    }

    orderLinkedList(liste);
    supprimer_doublons(liste);

    return liste;

}

LinkedList* readFile_Dictionary(char* filepath)
{
    FILE* fichier = fopen(filepath, "r");
    int taillemax = 40;

    LinkedList* liste = NULL;

    if (fichier != NULL){

        char* motLu = malloc(sizeof(char)*taillemax);

        while (fgets(motLu , sizeof(char)*taillemax , fichier) != NULL) {
            int i = strlen(motLu);

            if (motLu[i-1] == '\n'){
                motLu[i-1] = '\0';
            }else {
                motLu[i] = '\0';
            }

            motLu = strupr(motLu);

            liste = addElement(liste, motLu);
        }

    } else {
        printf("Impossible d'ouvrir le fichier");
    }

    orderLinkedList(liste);
    supprimer_doublons(liste);

    return liste;
}

//Liste chainée
void displayLinkedList(LinkedList* liste)
{
    LinkedList* tmp = liste;

    if(tmp == NULL)
        printf("Liste vide");

    while(tmp != NULL)
    {
        printf("%s\n", tmp->value);
        tmp = tmp->next;
    }

    printf("\n");
}

int LinkedListLenght(LinkedList* liste)
{
    int i = 1;

    LinkedList* tmp = liste;

    if(tmp == NULL)
        return 0;

    while(tmp->next != NULL)
    {
        i++;
        tmp = tmp->next;
    }

    return i;
}

LinkedList* addElement(LinkedList* liste, char* newValue)
{

    LinkedList* newElement = malloc(sizeof(LinkedList));

    strcpy(newElement->value, newValue);

    newElement->next = liste;

    return newElement;
}

void orderLinkedList(LinkedList* liste)
{
    LinkedList* c_liste;
    LinkedList* counter;
    LinkedList* min;
    char tmp[40];

    for(c_liste = liste; c_liste->next != NULL; c_liste = c_liste->next){
        min = c_liste;

        for(counter = c_liste->next; counter != NULL; counter = counter->next){
            if(order_word(counter->value, min->value) == 1){
                min = counter;
            }

        }

        strcpy(tmp, c_liste->value);
        strcpy(c_liste->value,  min->value);
        strcpy(min->value, tmp);
    }
}

int order_word(char* str1, char* str2)
{
    int i = 0;

    if (strcmp(str1, str2) == 0)
        return 0;

    if (strlen(str1)>= strlen(str2)){
        for (i = 0; i < strlen(str1); i++){
            if (str1[i] < str2[i]){
                return 1;
            }
            else if (str1[i] > str2[i]){
                return 2;
            }
        }
    }
    else {
        for (i = 0; i < strlen(str2); i++){
            if (str1[i] < str2[i]){
                return 1;
            }
            else if (str1[i] > str2[i]){
                return 2;
            }
        }
    }

    return 0;
}

void supprimer_doublons(LinkedList* liste)
{
    LinkedList* c_liste = liste;

    while(c_liste != NULL) {

        LinkedList* current = c_liste;
        LinkedList* suivant = c_liste->next;

        while (suivant != NULL) {
            if(strcmp(current->value, suivant->value) == 0){
                current->next = suivant->next;
                suivant = current->next;
            }else{
                current = suivant;
                suivant = suivant->next;
            }

        }
        c_liste = c_liste->next;
    }
}


//Utilitaire
void clear_str(char* str)
{

    int i = 0;

    for (i = 0; i < strlen(str); i++){
        if(str[i] < 65 || str[i] > 90) {
            str[i] = '\n';
        }
    }

}

LinkedList* split_str(LinkedList* liste, char* str, char* delimiter)
{
    LinkedList* tmp = liste;
    char *mot;
    mot = strtok(str, delimiter);

    while( mot != NULL )
    {
      tmp = addElement(tmp, mot);
      mot = strtok(NULL, delimiter);
    }

    return tmp;
}

int checkWord(Dictionary* _Dictionary, char* word){
    FILE* f = fopen(_Dictionary->filepath, "r+");
    int i = 0;
    char carac;
    if(f != NULL){
        while((carac = fgetc(f)) != EOF){
            if(word[i] == carac){
                i++;
                if(word[i] == '\0' && fgetc(f) == '\n'){
                    return -1;
                }
            } else{
                i = 0;
            }
        }
        fclose(f);
    } else{
        printf("Impossiblie d'ouvrir le fichier %s", _Dictionary->filepath);
    }
    return 0;
}

//Afficher
void launcher(){
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
int menu(){
    int choix = 0;
    printf("APPLICATION DE GESTION D'UN DICTIONNAIRE \n");
    printf("Menu : \n");
    printf("1 - Créer un fichier dictionnaire \n");
    printf("2 - Utiliser un dictionnaire existant \n");
    printf("3 - Créer un dictionnaire à partir d'un fichier texte \n");
    printf("4 - Supprimer un fichier dictionnaire \n");
    printf("5 - Ajouter un mot a un fichier dictionnaire \n");
    printf("6 - Rechercher un mot dans un fichier dictionnaire \n\n");

    while(choix < 1 || choix > 6){
        printf("Selectionner un choix : ");
        scanf("%d", &choix);
    }

    system("cls");

    return choix;
}

