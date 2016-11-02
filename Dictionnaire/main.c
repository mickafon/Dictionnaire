#include <stdio.h>
#include <stdlib.h>

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
Description : Fonction de tri de la liste chainée d'un Dictionary
En Paramètre : struct Dictionary
Sortie : void
*/
void orderList(Dictionary* _Dictionary);


/*
Description : Fonction d'affichage à partir d'un Dictionary
En Paramètre : struct Dictionary
Sortie : void
*/
void displayDictionary(Dictionary* _Dictionary);


/*
Description : Fonction de recherche simple (saisi d'un mot et vérification de sa présence ou non dans le dictionnaire)
En Paramètre : struct Dictionary : dictionnaire dans lequel faire la recherche, char* word : le mot a chercher
Sortie : int - 1 lorsque le mot est présent / 0 lorsque le mot est absent
*/
int checkWord(Dictionary* _Dictionary, char* word);


/*
Description : Fonction de création d'un Dictionary à partir d'une liste chainée
En Paramètre : struct LinkedList, string filepath
Sortie : struct Dictionary
*/
Dictionary createDictionaryFromList(LinkedList* list, char* filepath);


/*
Description : Fonction de création d'un Dictionary à partir d'un fichier
En Paramètre : struct LinkedList, string filepath
Sortie : struct Dictionary, int isFromDictionary -> 1 pour fichier dictionnaire, 0 pour fichier texte
Fait Appel à : readFile_Dictionary()/readFile_Text() pour la création de la liste, createDictionaryFromList() pour la création du Dictionary à partir de la liste
*/
Dictionary createDictionaryFromFile(char* filepath, int isFromDictionary);


/*
Description : Fonction de sélection d'un Dictionary
On demande à l'utilisateur la localisation du 'fichier dictionnaire' puis on créer le dictionnaire
En Paramètre : -
Sortie : struct Dictionary
Fait Appel à : createDictionaryFromFile() pour la création du Dictionary à partir du fichier
*/
Dictionary selectDictionary();


/*
Description : Fonction d'insertion d'un mot dans la liste chainée
/!\ ne pas oublié le cas du premier mot inséré
En Paramètre : struct Dictionary, string word
Sortie : void
Fait Appel à : orderList() pour trier la liste après l'insertion
deleteFile() et createFile() pour actualiser le fichier.
*/
void insertWordInDictionary(Dictionary* _Dictionary, char* word);


/*
Description : Fonction de création d'un fichier dictionnaire à partir d'une liste de mot saisie par l'user
On demande l'utilisateur la localisation, on créer un dictionnaire, on demande le nombre de mot et on boucle sur la fonction d'insertion
En Paramètre : -
Sortie : struct Dictionary
Fait Appel à : createFile() pour créer le fichier.
*/
Dictionary createDictionaryFromUser();

/*
Description : Fonction de lecture du fichier dictionnaire -> création liste chainée
/!\ a utiliser dans createDictionaryFromFile() pour la création du Dictionary à partir d'un fichier dictionnaire
En Paramètre : string filepath
Sortie : struct LinkedList
*/
LinkedList readFile_Dictionary(char* filepath);


/*
Description : Fonction de création d'un fichier à partir de Dictionary
En Paramètre : struct Dictionary
Sortie : void
*/
void createFile(Dictionary* _Dictionary);


/*
Description : Fonction de suppression d'un fichier à partir de Dictionary
En Paramètre : struct Dictionary
Sortie : void
*/
void deleteFile(Dictionary* _Dictionary);


/*
Description : Fonction de lecture du fichier texte -> création liste chainée
/!\ a utiliser dans createDictionaryFromFile() pour la création du dictionnaire à partir d'un fichier texte
En Paramètre : string filepath
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


