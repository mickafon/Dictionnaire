#ifndef GESTBIB_H_INCLUDED
#define GESTBIB_H_INCLUDED

struct LinkedList {
	char value[40];
	struct LinkedList* next;
};
typedef struct LinkedList LinkedList;

struct Dictionary {
	char* filepath;
	int nb_mots;
	struct LinkedList* liste;
};
typedef struct Dictionary Dictionary;

//Aimée
LinkedList* addElement(LinkedList* liste, char* newValue);
Dictionary* readFile(char* filepath, int isDictionary);
LinkedList* readFile_Dictionary(char* filepath);
LinkedList* readFile_Text(char* filepath);
LinkedList* split_str(LinkedList* liste, char* str, char* delimiter);
void supprimer_doublons(LinkedList* liste);
void displayLinkedList(LinkedList* liste);
void clear_str(char* str);
void orderLinkedList(LinkedList* liste);
int order_word(char* str1, char* str2);
int LinkedListLenght(LinkedList* liste);

//Mickael
void launcher();
int menu();
int checkWord(Dictionary* _Dictionary, char* word);
void deleteFile(Dictionary* _Dictionary);

//Ludwig



#endif // GESTBIB_H_INCLUDED
