// ERROR : Code will not run in vs code because sys/ipc and sys/shm arent recognised
// Code works

#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
	int id;
	void *sm;
	char buf[100];
	
    id = shmget((key_t)1222, 1024, 0666);
	
    printf("Key of shared memory is %d\n", id);
	
    sm = shmat(id, NULL, 0);
	
    printf("Process attached at %p\n", sm);
	printf("Data read from Memory : \n%s\n", (char *)sm);
	
    strcpy(buf, sm);
	int a = buf[0]-'0';
	int b = buf[2]-'0';
	
    printf("The Sum is %d\n", a+b);
}