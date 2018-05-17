#include <stdio.h>

#include "mythreads.h"

int balance = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* worker(void* arg) {
    //Pthread_mutex_lock(&lock);
    balance++; // unprotected access 
    //Pthread_mutex_unlock(&lock);
    return NULL;
}


int main(int argc, char *argv[]) {
    pthread_t p[20];
    //Pthread_create(p, NULL, worker, NULL);
    for (int i=0;i<20;i++){
          Pthread_create(&p[i], NULL, worker, NULL);

    }
    //Pthread_mutex_lock(&lock);
    //balance++; // unprotected access
    //Pthread_mutex_unlock(&lock);
     for (int i=0;i<20;i++){
    Pthread_join(p[i], NULL);
      }

      printf("Balance: %d \n", balance);
    return 0;
}
