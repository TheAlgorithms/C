#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

 pthread_mutex_t mutex_fork[5];
 pthread_t philosopher[5];
 int id[5];
 
 void pickup_fork(int *filo){
 	pthread_mutex_lock(&(mutex_fork[*filo]));
 	if(*filo < 4){
 		pthread_mutex_lock(&(mutex_fork[*filo + 1]));
	}else{
		pthread_mutex_lock(&(mutex_fork[0]));
	}
 }
 
 void largar_garfos(int *filo){
 	pthread_mutex_unlock(&mutex_fork[*filo]);
 	if(*filo < 4){
 		pthread_mutex_unlock(&mutex_fork[*filo+1]);
	 }else{
	 	pthread_mutex_unlock(&(mutex_fork[0]));
	 }
	 printf("philosopher %d finished eating \n",*filo);
 }
 void *life_philosopher(void * var){
 	int *filo = (int*)(var);
 	while(1){
 		int think = (rand()% 10 + 2);
 		printf("philosopher %d thinking %d seconds:\n\n",*filo,think);
 		pickup_fork(filo); 
 		int eat = rand()%5 + 1;
 		printf("philosopher %d eating\n",*filo);
 		sleep(eat);
 		largar_garfos(filo);
    }
    pthread_exit(NULL);
}

int main(){
	int i,j;
	system("cls");
	for(i = 0 ; i <= 4; i++){
		pthread_mutex_init(&(mutex_fork[i]),NULL); 
	}
	for(j = 0;j <= 4; j++){
		id[j] =  j;
		pthread_create(&ninja[j],NULL,&life_philosopher,(void*)&id[j]);
	}
	while(1){
    	
	}
	return 0;
}