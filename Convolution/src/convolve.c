#include<stdio.h>
#include<stdlib.h>

void input_array(int *arr, int size){

    for(int i = 0; i < size; i++){

        scanf("%d", &arr[i]);

    }

    return;

}

void print_array(int *arr, int size,const char* str)  {

    printf("%s : ", str);

    for(int i = 0; i < size; i++){

        printf("%d ", arr[i]);
    }

    printf("\n");

    return;

}

void convolve(int *filter, int *input, int *output, int M, int N){

    for(int n = 0; n < M+N-1; n++){
        for(int k = 0; k < M;k++){
            if( (n-k >= 0) && (n-k) < N){
                
                output[n] += filter[k]*input[n-k];
            }
        }
    }
    
    return;

}

void file_writer(FILE *file_pointer, int *array, int size){
    
    for(int i = 0; i < size; i++){
       fprintf(file_pointer,"%d ",array[i]);
    }

    fprintf(file_pointer,"\n");

    return;

}

void write_to_file(const char* filename, int *filter, int* input, int* output,int M,int N,int Y){

  FILE *file_pointer = fopen(filename, "w");

  if(file_pointer == NULL){

      printf("Error: could not open the file %s for writing",filename);
      return;

  }

  file_writer(file_pointer,input,N);
  file_writer(file_pointer,filter,M);
  file_writer(file_pointer,output,Y);

  fclose(file_pointer);

}

void draw_line(void){

    printf("=============================\n");

}

int main(){

    int M,N;

    printf("ENTER INPUT SIZE-> ");
    scanf("%d", &N);

    printf("ENTER FILTER SIZE-> ");
    scanf("%d", &M);
    
    draw_line();

    int Y = M+N-1;
    
    int *filter = (int *)malloc(M*sizeof(int));
    int *input = (int *)malloc(N*sizeof(int));
    int *output = (int *)calloc(Y, sizeof(int));

    if (filter == NULL || input == NULL || output == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("ENTER INPUT-> ");
    input_array(input, N);
    
    printf("ENTER FILTER-> ");
    input_array(filter,M);
   
    convolve(filter,input,output,M,N);

    draw_line();

    print_array(input,N, "INPUT ARRAY->");
    print_array(filter,M, "FILTER ARRAY->");

    draw_line();

    print_array(output,M+N-1, "CONVOLVED ARRAY->");

    draw_line();

    char decision;
    printf("Plot your output? [y/n]: ");

    scanf(" %c",&decision);

    if(decision == 'y' || decision == 'Y'){

        write_to_file("data.txt",filter,input,output,M,N,Y);
        free(filter);
        free(input);
        free(output);
        system("python3 ./src/plotter.py");
        return 0;

    }

    else{

        free(filter);
        free(input);
        free(output);
        return 0;

    }

    return 0;

}
    

