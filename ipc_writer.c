// ERROR : Code will not run in vs code because sys/ipc and sys/shm arent recognised
// Code works

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void main() {
    int id;
    void *sm;
    char buf[100];
    
    id = shmget((key_t)1222, 1024, 0666|IPC_CREAT);
    printf("Key of shared memory is %d\n", id);

    sm = shmat(id, NULL, 0);

    printf("Process attached at %p\n", sm);

    printf("Enter the data to be written : \n");
    read(0, buf, 100);
    strcpy(sm, buf);
    printf("Writter Data is : \n%s\n", (char *)sm);
}