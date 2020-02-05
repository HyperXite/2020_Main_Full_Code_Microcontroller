#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <math.h>
#include "packetbuilder.h"

/*void main(){

}*/

void DToString(char * outStr, int length, double val)
{
	snprintf(outStr,length,"%f",val);
}

void IToString(char * outStr, int length, int val)
{
    snprintf(outStr,length,"%d",val);
}


char* BuildPacketD(char *command, double sampledata){
    //printf("Double2 is: %f\n", sampledata);
    char dtos[10];
    //printf("str1\n");
    DToString(dtos, 10, sampledata);
   // printf("str2 is: %s\n", dtos);

    char *str = malloc(15);
    //printf("str3\n");
    int casenum;
    //printf("commandbp is |%s|\n", command);
    if(strncmp("c", command,1)==0){
        casenum = 3;
    }else if(strncmp("d", command,1)==0){
        casenum = 4;
    }else if(strncmp("e", command,1)==0){
        casenum = 5;
    }else if(strncmp("f", command,1)==0){
        casenum = 6;
    }else if(strncmp("g", command,1)==0){
        casenum = 7;
    }else if(strncmp("h", command,1)==0){
        casenum = 8;
    }else if(strncmp("i", command,1)==0){
        casenum = 9;
    }else if(strncmp("k", command,1)==0){
        casenum = 11;
    }else if(strncmp("l", command,1)==0){
        casenum = 12;
    }
    //printf("casenum is %d\n", casenum);

    switch (casenum)
    {
        case 3: 
            //printf("case3.1\n");
            strncat(str,"c-",12);
            //printf("case3.2\n");
            strncat(str,dtos,12);
            //strncat(str,"\n",12);
            //printf("case3.3\n");
            break;
        case 4: 
            strncat(str,"d-",12);
            strncat(str,dtos,12);
            strncat(str,"\n",12);
            break;
        case 5: 
            strncat(str,"e-",12);
            strncat(str,dtos,12);
            strncat(str,"\n",12);
            break;
        case 6: 
            strncat(str,"f-",12);
            strncat(str,dtos,12);
            strncat(str,"\n",12);
            break;
        case 7: 
            strncat(str,"g-",12);
            strncat(str,dtos,12);
            strncat(str,"\n",12);
            break;
        case 8: 
            strncat(str,"h-",12);
            strncat(str,dtos,12);
            strncat(str,"\n",12);
            break;
        case 9: 
            strncat(str,"i-",12);
            strncat(str,dtos,12);
            strncat(str,"\n",12);
            break;
        case 11: 
            strncat(str,"k-",12);
            strncat(str,dtos,12);
            strncat(str,"\n",12);
            break;
        case 12: 
            strncat(str,"l-",12);
            strncat(str,dtos,12);
            strncat(str,"\n",12);
            break;
        default: 
        	strncat(str,"b-",12);
            strncat(str,"1",12);
            strncat(str,"\n",12);
    }
    return str;

}

char* BuildPacketI(char *command, int sampledata){
    char itos[10];
    //printf("str1\n");
    IToString(itos, 10, sampledata);
   // printf("str2 is: %s\n", dtos);

    char *str = malloc(15);
    //printf("str3\n");
    int casenum;
    //printf("commandbp is |%s|\n", command);
    if (strncmp("a", command,1)==0){
        casenum = 1;
    }else if(strncmp("b", command,1)==0){
        casenum = 2;
    }
    //printf("casenum is %d\n", casenum);

    switch (casenum)
    {
        case 1: 
            strncat(str,"a-",12);
            strncat(str,itos,12);
            strncat(str,"\n",12);
            break;
        case 2:
            strncat(str,"b-",12);
            strncat(str,itos,12);
            strncat(str,"\n",12);
            break;
        
        default: 
            strncat(str,"b-",12);
            strncat(str,itos,12);
            strncat(str,"\n",12);
    }
    return str;
}

char* BuildPacketS(char *command, char *sampledata){
    char *str = malloc(15);
    //printf("str3\n");
    int casenum;
    //printf("commandbp is |%s|\n", command);
    if (strncmp("j", command,1)==0){
        casenum = 10;
    }
    //printf("casenum is %d\n", casenum);

    switch (casenum)
    {
        case 10: 
            strncat(str,"j-",12);
            strncat(str,sampledata,12);
            strncat(str,"\n",12);
            break;
        default: 
            strncat(str,"b-",12);
            strncat(str,"\n",12);
    }
    return str;
}



    