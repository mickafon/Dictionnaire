//
//  function.h
//  Dictionnaire
//
//  Created by Ludwig Roger on 03/11/2016.
//  Copyright © 2016 LudwigRgr. All rights reserved.
//

#ifndef function_h
#define function_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct LinkedList;
typedef struct LinkedList LinkedList;

struct Dictionary;
typedef struct Dictionary Dictionary;

void orderList(Dictionary* _Dictionary);

void displayDictionary(Dictionary* _Dictionary);

int checkWord(Dictionary* _Dictionary, char* word);

Dictionary createDictionaryFromList(LinkedList* list, char* filepath);

Dictionary createDictionaryFromFile(char* filepath, int isFromDictionary);

Dictionary selectDictionary();

void insertWordInDictionary(Dictionary* _Dictionary, char* word);

void start();



#endif /* function_h */
