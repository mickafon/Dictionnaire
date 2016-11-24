#ifndef GESTRECH_H_INCLUDED
#define GESTRECH_H_INCLUDED

struct SpecificLinkedList {
	char char_value[40];
	int int_value;
	struct SpecificLinkedList* next;
};
typedef struct SpecificLinkedList SpecificLinkedList;

//Aimée
void displaySpecificLinkedList(SpecificLinkedList* liste);
LinkedList* SpecificListToSimpleList(SpecificLinkedList* SpecificListe);
void orderSpecificLinkedList(SpecificLinkedList* liste);
SpecificLinkedList* addSpecificElement(SpecificLinkedList* liste, char* char_newvalue, int int_newvalue);
LinkedList* findSimilarWord(Dictionary* dico, char* word, int seuil);


#endif // GESTRECH_H_INCLUDED
