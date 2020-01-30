//Data.c maintaining data values

#include "Data.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


//Allocate new data record
DATA *NewData(float Value) {
    DATA *d; //create struct pointer
    d = malloc(sizeof(DATA)); //allocate memory
    if (! d) {
        perror("Out of memory! Aborting . . .");
        exit(10);
    }

    d->Value = Value;

    return d;
}

//Delete data record
void DeleteData(DATA *d) {
    assert(d);
    free(d);
}

//Print data record
void PrintData(DATA *d) {
    assert(d);
    printf("Data Value: %f\n", d->Value);
}

#ifdef MAIN

int main(void) {

    DATA *d1 = NULL, *d2 = NULL;
    printf("Creating 2 data records . . .\n");
    d1 = NewData(1.2);
    d2 = NewData(2.2);

    printf("Print the data records . . .\n");
    PrintData(d1);
    PrintData(d2);

    printf("Deleting data records\n");
    DeleteData(d1);
    d1 = NULL;
    DeleteData(d2);
    d2 = NULL;

    printf("Done\n");
    return 0;
    
}

#endif