//DataList.c maintain list of data 

#include "DataList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


//Allocate new data entry
static DENTRY *NewDataEntry(DATA *d) {
    DENTRY *e;  //creates pointer e to DENTRY
    e = malloc(sizeof(DENTRY));
    if (! e) {
        perror("Out of memory! Aborting . . .");
        exit(10);
    }
    e->List = NULL;
    e->Next = NULL;
    e->Prev = NULL;
    e->Data = d; //point data field to new data
    return e;
}

//Delete data entry
static DATA *DeleteDataEntry(DENTRY *e) {
    DATA *d;        //creates pointer to Data type d
    assert(e);      
    d = e->Data;    //sets pointer to entry data field
    free(e);
    return d;
}

//Allocate new student list
DLIST *NewDataList(void) {
    DLIST *l;
    l = malloc(sizeof(DLIST));
    if (! l) {
        perror("Out of memory! Aborting . . .");
        exit(10);
    }
    l->Length = 0;
    l->First = NULL;
    l->Last = NULL;
    return l;
}

//Delete List and all entries
void DeleteDataList(DLIST *l) { //paramter is pointer to list
    DENTRY *e, *n;              //instantiate two data entries
    DATA *d;                    //instantiate data 
    assert(l);                  //check if list is there
    e = l->First;               //set first data entry to e
    while(e) {                  //while there are data entries
        n = e->Next;            //set n to next data entry
        d = DeleteDataEntry(e); //deletes curret data entry, returns data
        DeleteData(d);          //deletes data
        e = n;                  //set current to next entry
    }
    free(l);
}

//Create Data Entries
// void CreateHeaders(DLIST *l, char *Names[]) {
//     assert(l);
//     DATA *d = NULL;
//     for (int i = 0; i < 3; i++) {
//         d = NewData(Names[i], 0, 0);
//         AppendData(l,d);
//     }
// }

//Append data at end
void AppendData(DLIST *l, DATA *d, char *Name) {
    DENTRY *e = NULL;   //creating pionter for DENTRY
    assert(l);
    assert(d);
    e = NewDataEntry(d); //set pointer to new data
    if (l->First) {     
        e->List = l;       //point back to list
        e->Next = NULL;    
        e->Prev = l->Last; 
        l->Last->Next = e; //point old last to new
        l->Last = e;       //move last pointer to new 
        strncpy(e->Name, Name, DLEN); //add data name to struct
        e->Name[DLEN] = '\0';         //initial values
    }
    else {
        e->List = l;
        e->Next = NULL;
        e->Prev = NULL;
        l->First = e;
        l->Last = e;
        strncpy(e->Name, Name, DLEN); //add data name to struct
        e->Name[DLEN] = '\0';         //initial values
    }
    l->Length++;
}

DATA *DeleteNamedEntry(DLIST *l, char *Name) {
    DENTRY *e;      
    int ComFlag;
    assert(l);
    assert(Name);
    e = l->First;
    l-> Length--;
    while (e) {     //traverse list to find named entry
        ComFlag = strcmp(e->Name, Name);
        if (ComFlag == 0) {
            if (e == l-> First) {
                printf("Deleting First\n");
                l->First = e->Next;
                e->Next->Prev = NULL;
                remove(e->Name);
                //e->Name[0] = '\0'; //add data name to struct
                e->Prev = NULL;
                e->List = NULL;
                return DeleteDataEntry(e);
                
            }
            if (e == l-> Last) {
                printf("Deleting Last\n");
                l->Last = e->Prev;
                e->Prev->Next = NULL;
                e->Next = NULL;
                e->List = NULL;
                return DeleteDataEntry(e);
            }
            else {
                e->Prev->Next = e->Next;
                e->Next->Prev = e->Prev;
                e->List = NULL;
                return DeleteDataEntry(e);
            }

        // if (ComFlag > 0) {
        //     break;
        // }
        }
        e = e->Next;
    }
    return (NULL);
}

void InitCSV(DLIST *l, FILE  *fp) {
    assert(l);
    DENTRY *e;
    //FILE *fp;
    int i;
    //fp=fopen("Data.csv", "w+");
    e = l->First;

    for (i = 0; i<l->Length; i++) {
        fprintf(fp, "%s\t\t", e->Name);
        e = e->Next;
    }
    //e = l->First;
    //fclose(fp);
}

void UpdateCSV(DLIST *l, FILE *fp) {
    assert(l);
    DENTRY *e;
    //FILE *fp;
    int i;
    //fp=fopen("Data.csv", "w+");
    e = l->First;

    fprintf(fp, "\n");
    for (i = 0; i<l->Length; i++) {
        
        // switch (e->Name) {
        //     case 'Time':
        //     fprintf(fp, "%f", e->Data->Value);
        // }
        fprintf(fp, "%f\t\t", e->Data->Value);
        e = e->Next;
    }
    //fclose(fp);
}

//print student list
void PrintDataList(DLIST *l) {
    DENTRY *e;
    assert(l);
    e = l->First;
    while(e) {
        printf("%s->", e->Name);
        PrintData(e->Data);
        e =  e->Next;
    }
}

#ifdef MAIN 

int main(void) {
    //Alternative option to appending new entries, but 
    //need function to update data and know entries before hand
    DLIST *l;
    DATA *d;
    FILE *fp;
    //char Name[1];
    l = NewDataList();

    d = NewData(25.6);
    AppendData(l, d, "Temperature");

    d = NewData(30.8);
    AppendData(l, d, "Velocity");
   
    d = NewData(5);
    AppendData(l, d, "Acceleration");

    //CreateHeaders(l, Names);
    PrintDataList(l);
    printf("\n\n");
    //d = DeleteNamedEntry(l, "Velocity");
    //DeleteData(d);
    PrintDataList(l);
    //FILE *fp;
    fp=fopen("Data.csv", "w+");
    InitCSV(l, fp);
    UpdateCSV(l, fp);
    fclose(fp);
    //DeleteDataList(l);
    //l = NULL;


} 
#endif 


