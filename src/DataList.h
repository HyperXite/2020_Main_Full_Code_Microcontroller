//DataList.h header file to list data

#ifndef DATALIST_H
#define DATALIST_H

#include "Data.h"
#include <stdio.h>

typedef struct DataList DLIST;
typedef struct DataEntry DENTRY;
typedef struct AllData ALLDATA;

struct DataList {
    int Length;
    DENTRY *First;
    DENTRY *Last;
};

struct DataEntry {
    DLIST *List;
    DENTRY *Next;
    DENTRY *Prev;
    char Name[DLEN + 1];
    DATA *Data;
};

struct AllData {
    float Temperature;
    float Air_Pressure;
    float Speed;
    
};


//Allocate new data list
DLIST *NewDataList(void);

//Delete data list and all entries
void DeleteDataList(DLIST *l);

//Create Data Entries
void CreateHeaders(DLIST *l, char *Names[]);

//Append data to end of list
void AppendData(DLIST *l, DATA *d, char *Name);

//Remove data from list
DATA *DeleteNamedEntry(DLIST *l, char *Name);

//Print data list
void PrintDataList(DLIST *l);

//update all data values
void UpdateData(DLIST *l, ALLDATA);

void UpdateCSV(DLIST *l, FILE *fp);

void InitCSV(DLIST *l, FILE *fp);

#endif


