#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


char * KEY = "ASDLKGH";

void work_semaphore(char * arg){
	if(!strcmp(arg, "-c")){
		
	}
}

int main(int argc, char * argv[]){
	int i;
	for(i = 1; i < argc; i++){
		work_semaphore(argv[i]);
	}

	if(!strcmp(argv[1], "-c")){
		int semd = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0600);
		if(semd){
			printf("semaphore already exists :) \n");
		}
		else{
			union semun {
				int val = argv[2];   
				struct semid_ds *buf;   
				unsigned short  *array;
				struct seminfo  *__buf; 
			};

			semctl( semd, 0, SETVAL, semun);
		}
	}
	else if(!strcmp(argv[1], "-v")){
		printf("Semaphore Value: %d", semctl(semd, 0, GETVAL));
	}
	else if(!strcmp(argv[1], "-r")){
		do_semctl(semd, 0, IPC_RMID, 0);
	}
}
