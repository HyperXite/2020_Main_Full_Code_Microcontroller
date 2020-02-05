#ifndef PACKETBUILDER_H
#define PACKETBUILDER_H


char* BuildPacketD(char *command, double sampledata);
char* BuildPacketI(char *command, int sampledata);
char* BuildPacketS(char *command, char *sampledata);
void DToString(char * outStr, int length, double val);
void IToString(char * outStr, int length, int val);

#endif
