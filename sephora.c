#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int KEY = 230957;

int main(int argc, char * argv[]){

	if(!strcmp(argv[1], "-c")){
		int semd = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0600);

		if(semd == -1){
			printf("semaphore already exists\n");
		}
		else{
			union semun{
				int val;
				struct semi_ds * buf;
				unsigned short * array;
				struct seminfo * __buf;
			} arg;
			arg.val = atoi(argv[2]);
			semctl(semd, 0, SETVAL, arg);
		}
	}
	else if(!strcmp(argv[1], "-v")){
		int semd = semget(KEY, 1, 0);
		printf("Semaphore Value: %d\n", semctl(semd, 0, GETVAL));
	}
	else if(!strcmp(argv[1], "-r")){
		int semd = semget(KEY, 1, 0);
		semctl(semd, 0, IPC_RMID);
	}
}
