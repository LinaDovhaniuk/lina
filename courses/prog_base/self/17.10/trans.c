#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(){
     int matrix[4][4];
     int i,j;

void printMatrix(int matrix[4][4]){
srand(time(NULL));
printf("Matrix\n\n");
          int i,j;
for ( i = 0; i < 4; i++ ) {
    for ( j = 0; j < 4; j++ )
    {
        matrix[i][j] = rand()%1999-999;
        printf( "%5i ",  matrix[i][j] );
    }
    printf( "\n" );
  }
}

void rotateCW90(int matrix [4][4]){
printf("RotateCW90\n\n");
         int i,j;
for ( i = 0; i < 4; i++ ) {
for ( j = 3; j >= 0; j-- )
{
printf( "%5i ", matrix[j][i] );
}
printf( "\n" );
}
}

void flipH(int matrix [4][4]){
printf("FlipH\n\n");
         int i,j;
for ( i = 0; i < 4; i++ ) {
    for ( j = 3; j >=0; --j )
    {
        printf( "%5i ",  matrix[i][j] );
    }
    printf( "\n" );
  }
}

void transposMain( int matrix[4][4]){
printf("TransposMain\n\n");
       int i,j;
for ( j = 0; j < 4; j++ ) {
    for ( i = 0; i < 4; i++ )
    {
              printf( "%5i ",  matrix[i][j] );
    }
    printf( "\n" );
  }
}
}





