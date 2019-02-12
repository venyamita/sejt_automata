#include <fstream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;


int main(int argc, char **argv)
{
string matrix_file;
unsigned int N = atoi(argv[2]); 
unsigned int M = atoi(argv[1]); 
matrix_file = argv[3];
int n;
cout<< "Add meg n erteket: ";
cin >> n;
ifstream Mat_file(matrix_file.c_str());
int **matrix = new int*[M];
for ( unsigned int i=0; i<M; i++)
{
matrix[i] = new int[N];
}
int **temp_matrix = new int*[M];
for ( unsigned int i=0; i<M; i++)
{
temp_matrix[i] = new int[N];
}
for ( unsigned int m=0; m<M ; m++)
{
for ( unsigned int n=0; n<N ; n++)
{
Mat_file >> matrix[m][n];
temp_matrix[m][n]=matrix[m][n];
}
}
Mat_file.close();
unsigned int suma; 
for ( unsigned int i=0; i<10 ; i++)
{
ostringstream file;
file << i << ".dat";
ofstream result(file.str().c_str());
for ( unsigned int k=0; k<M; k++)
{
for ( unsigned int j=0; j<N; j++)
{
//határfeltételek
if (k==0 && j==0)
{
suma=matrix[k+1][j]+matrix[k+1][j+1]+matrix[k][j+1]+5;
}
else if (k==(M-1) && j==(N-1))
{
suma=matrix[k-1][j]+matrix[k-1][j-1]+matrix[k][j-1]+5;
}
else if (k==0 && j==(N-1))
{
suma=matrix[k+1][j]+matrix[k+1][j-1]+matrix[k][j-1]+5;
}
else if (k==(M-1) && j==0)
{
suma=matrix[k-1][j]+matrix[k][j+1]+matrix[k-1][j+1]+5;
}
else if (k==0)
{
suma=matrix[k+1][j+1]+matrix[k+1][j-1]+matrix[k+1][j]+matrix[k][j-1]+matrix[k][j+1]+3;
}
else if (k==(M-1))
{
suma=matrix[k-1][j+1]+matrix[k-1][j-1]+matrix[k-1][j]+matrix[k][j-1]+matrix[k][j+1]+3;
}
else if (j==0)
{
suma=matrix[k-1][j]+matrix[k+1][j]+matrix[k-1][j+1]+matrix[k+1][j+1]+matrix[k-1][j]+3;
}
else if (j==(N-1))
{
suma=matrix[k-1][j]+matrix[k+1][j]+matrix[k+1][j-1]+matrix[k-1][j-1]+matrix[k][j-1]+3;
}
else
{
suma=matrix[k-1][j-1]+matrix[k-1][j]+matrix[k-1][j+1]+matrix[k][j-1]+matrix[k][j+1]+matrix[k+1][j-1]+matrix[k+1][j]+matrix[k+1][j+1];
}
//lépés
if(suma==(n+1))
temp_matrix[k][j]=1;
if(suma==n)
temp_matrix[k][j]=matrix[k][j];
if(suma>(n+1) || suma<n)
temp_matrix[k][j]=0;
}
}
for ( unsigned int m=0; m<M ; m++)
{
for ( unsigned int n=0; n<N ; n++)
{
result << temp_matrix[m][n] << "\t";
matrix[m][n]=temp_matrix[m][n];
}
result << endl;
}
}
for(int i=0; i<N; ++i)
{
delete[] matrix[i];
}
delete[] matrix;
for(int i=0; i<N; ++i)
{
delete[] temp_matrix[i];
}
delete[] temp_matrix;
return 0;
}