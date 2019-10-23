#include "structures.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

STATE *CreateSampleState()
{
	//creates and returns a malloc'd sample state, each individual state in the program will need its own function to define and create it in this file
	STATE *samplestate = (STATE *)malloc(sizeof(STATE));
	if (samplestate == NULL)
	{
		perror("Error in allocating Memory Space!\n");
		return NULL;
	}
	samplestate->dummyactuation = 0;
	samplestate->dummyactuation = 1;

	return samplestate;
} /*end of CreateSampleState*/

void DeleteState(STATE *state)
{
	//deallocates and deletes a move
	//important to use at the end of the program to prevent memory leaks
	assert(state);
	//as a note for later, if the state ever has a pointer in it that should be handled and set to null or otherwise freed but elementary 
	//data like ints can be ignored and freed with any value.
	free(state);
} /*end of deletestate*/

/*EOF*/
