#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestexpr.h"
#include "gestbib.c"

/*LinkedList section_d(char* word, LinkedList* liste){
    LinkedList* liste = malloc(sizeof(LinkedList));
    int i, size = 0;
    char num[1];
    for(i == 0; i < 10; i++){
        sprintf(num, "%d", i);
        liste = addElement(liste, strcat(word, num));
    }
    return liste;
}

LinkedList section_s_d(char* word, LinkedList* liste){
    LinkedList* liste = malloc(sizeof(LinkedList));
    int i, j, size = 0;
    char space[] = " .\t\r\n";
    char num[2];
    for(i = 1; i < strlen(space); i++){
        for(j == 0; j < 10; j++){
            sprintf(num, "%c%d", space[i], j);
            liste = addElement(liste, strcat(word, num));
        }
    }
    return liste;
}

LinkedList section_s_w(char* word, LinkedList* liste){
    LinkedList* liste = malloc(sizeof(LinkedList));
    int i, j, size = 0;
    char space[] = " .\t\r\n";
    char letter[2];
    for(i = 1; i < strlen(space); i++){
        for(j == 65; j < 122; j++){
            if(j <= 90 || j >= 97){
                letter[0] = space[i];
                letter[1] = j;
                liste = addElement(liste, strcat(word, letter));
            }
        }
    }
    return liste;
}

LinkedList a_x(char letter, LinkedList* liste){
    LinkedList* liste = malloc(sizeof(LinkedList));
    int i, j, size = 0;
    char letter[2];
    for(i = 1; i < strlen(space); i++){
        for(j == 65; j < 122; j++){
            if(j <= 90 || j >= 97){
                letter[0] = space[i];
                letter[1] = j;
                liste = addElement(liste, strcat(word, letter));
            }
        }
    }
    return liste;
}*/

char caraList(LinkedList* liste, int index){
    char carac[] = liste->value;
    return carac[index];
}


LinkedList section_d(char* word, LinkedList* liste){
    LinkedList* result = malloc(sizeof(LinkedList));
    if(caraList(liste, strlen(liste->value) - 2) == ' ' && (caraList(liste, strlen(liste->value) - 1)) >= 48 && caraList(liste, strlen(liste->value) - 1) <= 57){
        result = addElement(result, liste->value);
    }
}

LinkedList section_sd(char* word, LinkedList* liste){
    LinkedList* result = malloc(sizeof(LinkedList));
    if((caraList(liste, strlen(liste->value) - 2) == ' ' || caraList(liste, strlen(liste->value) - 2) == '\t' ||
        caraList(liste, strlen(liste->value) - 2) == '\n' || caraList(liste, strlen(liste->value) - 2) == '\r' ||
        caraList(liste, strlen(liste->value) - 2) == '.') && (caraList(liste, strlen(liste->value) - 1)) >= 48 && caraList(liste, strlen(liste->value) - 1) <= 57){
        result = addElement(result, liste->value);
    }
}

LinkedList section_sw(char* word, LinkedList* liste){
    LinkedList* result = malloc(sizeof(LinkedList));
    if((caraList(liste, strlen(liste->value) - 2) == ' ' || caraList(liste, strlen(liste->value) - 2) == '\t' ||
        caraList(liste, strlen(liste->value) - 2) == '\n' || caraList(liste, strlen(liste->value) - 2) == '\r' ||
        caraList(liste, strlen(liste->value) - 2) == '.') && ((caraList(liste, strlen(liste->value) - 1)) >= 65 && caraList(liste, strlen(liste->value) - 1) <= 90) ||
       (caraList(liste, strlen(liste->value) - 1) >= 97 && caraList(liste, strlen(liste->value) - 1)) >= 122){
        result = addElement(result, liste->value);
    }
}

LinkedList a0ton(char a, char x, LinkedList* liste){
    LinkedList* result = malloc(sizeof(LinkedList));
    if((caraList(liste, strlen(liste->value) - 2) == ' ' || caraList(liste, strlen(liste->value) - 2) == '\t' ||
        caraList(liste, strlen(liste->value) - 2) == '\n' || caraList(liste, strlen(liste->value) - 2) == '\r' ||
        caraList(liste, strlen(liste->value) - 2) == '.') && ((caraList(liste, strlen(liste->value) - 1)) >= 65 && caraList(liste, strlen(liste->value) - 1) <= 90) ||
       (caraList(liste, strlen(liste->value) - 1) >= 97 && caraList(liste, strlen(liste->value) - 1)) >= 122){
        result = addElement(result, liste->value);
    }
}

void search(){
    //LinkedList* liste = dfdfs
}
