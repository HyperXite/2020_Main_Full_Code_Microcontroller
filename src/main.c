#include "structures.h"
#include <stdio.h>
#include <stdlib.h>


 
int main(int argc, char *argv[]) {
	
		//function to create new state and allocate memory
		struct STATE *CreateState(){

			//trying to allocate state structure
			struct STATE *retState = malloc(sizeof(struct STATE));
			if (retState == NULL){
				return NULL;
			}
			//return
			return retState;
		}

		//function to delete and free state
		void deleteState(struct STATE *delState){
			//assume state is NULL or fully built
			if (delState != NULL){
				free (delState);
			}
		}



		//this is an example of how the states will be created
		//"samplestate" and its function will be replaced with the specific states
		//all of the states are to be malloc'd at the beginning of the program here and then we just swap a "currentstate"
		//pointer to the new state
		//at the end all should be deallocated
        STATE *samplestate1 = CreateState();
        STATE *samplestate2 = CreateState();
        STATE **currentState = CreateState();
 
		printf("the value of sample dummy1 is %d\n", samplestate1->dummyactuation);
		printf("the value of sample dummy2 is %d\n", samplestate1->dummyactuation2);
		
		
		
		//we will have a separate file for the DAQ that collects the inputs from the sensors at each iteration of the loop
		//we will have a separate file for the CANopen communication which collects the info from the BMS and motor controller
			//in addition to sending requests to the motor controller for what it is supposed to be doing
		//we will have a separate file for the subnet communication both for sending a UDP message to the spaceX servers based on their
			//requirements and TCP communications with the computer we are using for the GUI
			
		//in this file we need to create a loop that runs until the computer tells the microcontroller to stop running
		//this file will have a function that takes the current state as a parameter and outputs the values to the correct pins on the microcontroller
		//inside of main we will have the loop and each step of the loop will call the functions from the other files in addition to switching the current state
			//either in a function or in a big case-switch statement whichever is more elegant. switching will be
			//based on whatever the requirements are to transition and what the current state is, or remain unchanged.
		int isStop = 0;
		int transReq = 0;
		while (isStop != 1){
			callOtherFunctions;
			callOtherFunctions;
			switch (transReq)
			{	
				//if transReq = 1
			    case 1: 
			    	currentState = &samestate1;
			        break;
			    //if transReq = 2
			    case 2: 
			    	currentState = &samestate2;
			        break;
			    default: 
			    	//stay on current state
			}
		}
		
		
		//example of how the states will be deleted at the end
		DeleteState(samplestate);
}

/*EOF*/
