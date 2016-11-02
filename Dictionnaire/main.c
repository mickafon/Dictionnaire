#include <stdio.h>
#include <stdlib.h>

#include "gestbib.h"


/*
PROJET DICTIONNAIRE :
PARTIE 1
*/

/*
Liste des structures
*/
struct LinkedList {
    char* value;
    struct LinkedList* next;
};
typedef struct LinkedList LinkedList;

struct Dictionary {
    char* filepath;
    struct LinkedList* list;
};
typedef struct Dictionary Dictionary;

/*
Liste des fonctions
*/

/*
Description : Fonction de tri de la liste chain�e d'un Dictionary
En Param�tre : struct Dictionary
Sortie : void
*/
void orderList(Dictionary* _Dictionary);


/*
Description : Fonction d'affichage � partir d'un Dictionary
En Param�tre : struct Dictionary
Sortie : void
*/
void displayDictionary(Dictionary* _Dictionary);


/*
Description : Fonction de recherche simple (saisi d'un mot et v�rification de sa pr�sence ou non dans le dictionnaire)
En Param�tre : struct Dictionary : dictionnaire dans lequel faire la recherche, char* word : le mot a chercher
Sortie : int - 1 lorsque le mot est pr�sent / 0 lorsque le mot est absent
*/
int checkWord(Dictionary* _Dictionary, char* word);


/*
Description : Fonction de cr�ation d'un Dictionary � partir d'une liste chain�e
En Param�tre : struct LinkedList, string filepath
Sortie : struct Dictionary
*/
Dictionary createDictionaryFromList(LinkedList* list, char* filepath);


/*
Description : Fonction de cr�ation d'un Dictionary � partir d'un fichier
En Param�tre : struct LinkedList, string filepath
Sortie : struct Dictionary, int isFromDictionary -> 1 pour fichier dictionnaire, 0 pour fichier texte
Fait Appel � : readFile_Dictionary()/readFile_Text() pour la cr�ation de la liste, createDictionaryFromList() pour la cr�ation du Dictionary � partir de la liste
*/
Dictionary createDictionaryFromFile(char* filepath, int isFromDictionary);


/*
Description : Fonction de s�lection d'un Dictionary
On demande � l'utilisateur la localisation du 'fichier dictionnaire' puis on cr�er le dictionnaire
En Param�tre : -
Sortie : struct Dictionary
Fait Appel � : createDictionaryFromFile() pour la cr�ation du Dictionary � partir du fichier
*/
Dictionary selectDictionary();


/*
Description : Fonction d'insertion d'un mot dans la liste chain�e
/!\ ne pas oubli� le cas du premier mot ins�r�
En Param�tre : struct Dictionary, string word
Sortie : void
Fait Appel � : orderList() pour trier la liste apr�s l'insertion
deleteFile() et createFile() pour actualiser le fichier.
*/
void insertWordInDictionary(Dictionary* _Dictionary, char* word);


/*
Description : Fonction de cr�ation d'un fichier dictionnaire � partir d'une liste de mot saisie par l'user
On demande l'utilisateur la localisation, on cr�er un dictionnaire, on demande le nombre de mot et on boucle sur la fonction d'insertion
En Param�tre : -
Sortie : struct Dictionary
Fait Appel � : createFile() pour cr�er le fichier.
*/
Dictionary createDictionaryFromUser();

/*
Description : Fonction de lecture du fichier dictionnaire -> cr�ation liste chain�e
/!\ a utiliser dans createDictionaryFromFile() pour la cr�ation du Dictionary � partir d'un fichier dictionnaire
En Param�tre : string filepath
Sortie : struct LinkedList
*/
LinkedList readFile_Dictionary(char* filepath);


/*
Description : Fonction de cr�ation d'un fichier � partir de Dictionary
En Param�tre : struct Dictionary
Sortie : void
*/
void createFile(Dictionary* _Dictionary);


/*
Description : Fonction de suppression d'un fichier � partir de Dictionary
En Param�tre : struct Dictionary
Sortie : void
*/
void deleteFile(Dictionary* _Dictionary);


/*
Description : Fonction de lecture du fichier texte -> cr�ation liste chain�e
/!\ a utiliser dans createDictionaryFromFile() pour la cr�ation du dictionnaire � partir d'un fichier texte
En Param�tre : string filepath
Sortie : struct LinkedList
*/
LinkedList readFile_Text(char* filepath);

int main(){
    Dictionary dico;
    dico.filepath = "C:/Users/Micka/Desktop/dico.txt";
    char test[] = "test";
    if(checkWord(&dico, test) == -1){
        printf("eee");
    } else{
        printf("nop");
    }
    return 0;
}

void demarrer(){
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
    printf("1 - Cr�er un fichier dictionnaire \n");
    printf("2 - Utiliser un dictionnaire existant \n");
    printf("3 - Cr�er un dictionnaire � partir d'un fichier texte \n");
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

void displayDictionary(Dictionary* _Dictionary){
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


