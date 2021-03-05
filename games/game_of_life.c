/*
Conway's Game of Life
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_X 60
#define MAX_Y 20

void draw(char *world){
    #ifdef _WIN32
    system("cls");
    #endif
    #ifdef linux
    system("clear");
    #endif
    for(int y=0; y<MAX_Y; y++){
        for(int x=0; x<MAX_X; x++){
            printf("%c", (*(world + 20*x + y) == 1) ? '@' : ' ' ); 
        }
        printf("\n");
    } 
}
char* em(char *world){
    char *newWorld = malloc(1200);
    int live = 0;
    if(newWorld == NULL){
        printf("[ERROR] Memory\n\a");
        exit(0);
    }
    for(int y=0; y<MAX_Y; y++){
        for(int x=0; x<MAX_X; x++){
            // select cell
            live = 0;
            for(int j=-1; j<2; j++){
                for(int i=-1; i<2; i++){
                    if( *(world + MAX_Y*(y+j) +(x+i)) == 1 ) live++;
                }
            }
            if(*(world + 20*y +x) == 1){
                if(live == 3 || live == 4){
                    *(newWorld + MAX_Y*y +x) = 1;   
                }else{
                    *(newWorld + MAX_Y*y +x) = 0;
                }
            }else{
                if(live == 3){
                    *(newWorld + MAX_Y*y +x) = 1;
                }else{
                    *(newWorld + MAX_Y*y +x) = 0;
                }
            }
        }
    }
    return newWorld;
}
int main(){
    char *world = malloc(1200);
    srand(time(0));
    if(world == NULL){
        printf("[ERROR] Memory\n\a");
        exit(0);
    } 
    for(int y=0; y<MAX_Y; y++){
        for(int x=0; x<MAX_X; x++){
            *(world + 20*y + x) = ( (rand() <= (RAND_MAX / 10)) ? 1 : 0);
        }
    } 
    
    while(1){
        draw(world);
        world = em(world);
        _sleep(300);
    }
    return 0;
}
