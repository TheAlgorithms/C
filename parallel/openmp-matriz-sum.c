#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINES 8

int main(int argc, const char **argv){
	int MAT[LINES][2048];
	unsigned long long int SUM[8] = {0,0,0,0,0,0,0,0};
	srand(time(NULL));

#pragma omp parallel num_threads(4)
	{
/*		int id = omp_get_thread_num();
		int nt = omp_get_num_threads();
		int size = (int) 2048/nt;
		int i = id*size;
		int f = i + size;
*/
		// essa estrutura faz a distribuição da matriz pelas
		// threads executadas
#		pragma omp for
		for(int x=0; x<8; x++){
			for(int y=0; y<2048; y++){
				MAT[x][y] = 1;//rand()%3+1;
			}
			printf("[%d]\n",x);
		}
	}

#pragma omp parallel for num_threads(4)
	//{
//#pragma omp for
		for(int x=0; x<LINES; x++){
			for(int y=0; y<2048; y++){
				SUM[x] += MAT[x][y];
			}
		}
	//}

	for(int x=0; x<8; x++){
		printf("Thread %d: SUM[%d] = %lld\n",
				omp_get_thread_num(),
				x, SUM[x]);
	}
	
	return 0;
	
}
