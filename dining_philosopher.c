#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define N 5
#define LEFT (i+4)%5
#define RIGHT (i)%5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];

pthread_t t[N];

sem_t = s[N];
sem_t mutex;

void think(int n) {
    printf("The Philosopher %d is thinking \n", n);
    sleep(1);
}

void eat(int n){
    printf("The philosopher %d is eating \n", n);
    sleep(1);
    printf("The philosopher %d finished eating \n", n);
}

void take_fork(int i){
    sem_wait(&mutex);
    state[i] = HUNGRY;

    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        sem_wait(&s[LEFT]);
        sem_wait(&s[RIGHT]);
    }
    sem_post(&mutex);
}

void putforks(int i){
    state[i] = THINKING;
    sem_post(&s[LEFT]);
    sem_post(&s[RIGHT]);
}

void *philo(int n){
    while (1) {
        think(n);
        take_fork(n);
        if (state(n) == EATING){
            eat(n);
            putforks(n);
        }
    }
}


void main() {
    int i;
    for (i = 0; i < N; i++){
        sem_init(&s[i], 0, 1);
    }
    for (i = 0; i < N; i++){
        sem_init(&mutex, 0, 1);
    }
    for (i = 0; i < N; i++){
        pthread_create(&t[i], 0, (void *)philo, (void *)i);
    }while(1);
}