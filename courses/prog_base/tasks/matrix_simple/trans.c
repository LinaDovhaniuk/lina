/*#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fillRand(int mat [4][4]);
void flipH(int mat [4][4]) ;
void rotateCW90(int mat [4][4]) ;
void transposMain( int mat[4][4]) ;
void printMatrix(int mat[4][4]);


int main ()
{
	int i,j;
	int mat [4][4];
	fillRand(mat);
	printMatrix(mat);
	rotateCW90(mat);
	printMatrix(mat);
	flipH(mat);
	printMatrix(mat);
	transposMain(mat);
	printMatrix(mat);

	system ("pause");
	return(0);
}
*/
void fillRand(int mat[4][4]){
srand (time(NULL));
int i, j, n = 4;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            mat[i][j] = ((int)rand() % 1999) - 999;
    }
    }
}

void printMatrix(int mat[4][4]) {
int i, j;
int n = 4;
    for (i = 0; i < n; i++) {
    printf("{");
        for (j = 0; j < n; j++) {
        printf("%5i, ", mat[i][j]);
        }
        printf("}");
    if ( i < n - 1)
    printf("\n ");
}
printf("\n\n");
}

void rotateCW90(int mat[4][4]){
    int i,j;
    int n=4;
    int matrix[4][4];
for (i=0; i<n; i++){
    for (j=0; j<n; j++){
        matrix[i][j]=mat[n-1-j][i];
        }
}for (i=0; i<n; i++){
    for (j=0; j<n; j++){
        mat[i][j]=matrix[i][j];
    }
}
}


void flipH(int mat [4][4]){
int i,j;
int matrix[4][4] ;

	for (i = 0; i < 4; i++)
	for (j = 0; j < 4; j++)
		matrix[i][j]=mat[i][j];
	for ( i = 0; i < 4; i++)
	for (j = 0; j < 4; j++)
		mat [i][j] = matrix[i][3-j];
}

void transposMain(int mat[4][4]){
int i,j;
int matrix[4][4];

    for (i = 0; i < 4; i++)
	for (j = 0; j < 4; j++)
        matrix[i][j]=mat[j][i];
    for ( i = 0; i < 4; i++)
	for (j = 0; j < 4; j++)
		mat [i][j] = matrix[i][j];

}





