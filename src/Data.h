//Data.h header file for data values

#ifndef DATA_H
#define DATA_H

#define DLEN 20
 
 //Define structure of Data
struct Data {
    float Value;
};

typedef struct Data DATA;

//Allocate new data value
DATA *NewData(float Value);

//Delete data value
void DeleteData(DATA *d);

//Print Data
void PrintData(DATA *d);

#endif