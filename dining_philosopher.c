#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forks[N];

void *philosopher(void *num)
{
    int id = *(int*)num;

    while(1)
    {
        printf("Philosopher %d Thinking\n",id);

        pthread_mutex_lock(&forks[id]);
        pthread_mutex_lock(&forks[(id+1)%N]);

        printf("Philosopher %d Eating\n",id);

        sleep(1);

        pthread_mutex_unlock(&forks[id]);
        pthread_mutex_unlock(&forks[(id+1)%N]);
    }
}

int main()
{
    pthread_t p[N];
    int id[N];

    for(int i=0;i<N;i++)
    {
        pthread_mutex_init(&forks[i],NULL);
        id[i]=i;
    }

    for(int i=0;i<N;i++)
        pthread_create(&p[i],NULL,philosopher,&id[i]);

    for(int i=0;i<N;i++)
        pthread_join(p[i],NULL);

    return 0;
}
