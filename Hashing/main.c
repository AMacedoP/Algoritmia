/* 
 * File:   main.c
 * Author: Fernando Alva Manchego
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "SCHashST.h"

void demo_separate_chaining(){
    TSCHashST T;
    
    SCHashST_Init(&T, 13);

    SCHashST_Insert(&T, "A", 10);
    SCHashST_Insert(&T, "FOOL", 20);
    SCHashST_Insert(&T, "AND", 30);    
    SCHashST_Insert(&T, "HIS", 40);
    SCHashST_Insert(&T, "MONEY", 50);
    SCHashST_Insert(&T, "ARE", 60);
    SCHashST_Insert(&T, "SOON", 70);
    SCHashST_Insert(&T, "PARTED", 80);
    
    SCHashST_Print(&T);
}

int main(int argc, char** argv) {
    demo_separate_chaining();
    return (EXIT_SUCCESS);
}

