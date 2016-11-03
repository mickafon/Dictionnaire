//
//  main.c
//  Dictionnaire
//
//  Created by Ludwig Roger on 02/11/2016.
//  Copyright © 2016 LudwigRgr. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "function.c"

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






