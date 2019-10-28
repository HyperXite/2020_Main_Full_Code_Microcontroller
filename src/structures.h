#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct STATE STATE;

struct STATE {
	int dummyactuation;
	int dummyactuation2;
};

STATE *CreateState();
void DeleteState(STATE *state);

#endif
