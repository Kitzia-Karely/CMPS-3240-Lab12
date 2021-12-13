#include <stdio.h>
#include <stdlib.h>

#define BLOCKSIZE 32
void do_block ( int n, int si, int sj, int sk, double *A, double *B, double *C ) {
    for ( int i = si; i < si + BLOCKSIZE; ++i )
        for ( int j = sj; j < sj + BLOCKSIZE; ++j ) {
            double cij = C[i+j*n]; /* cij = C[i][j] */
            for ( int k = sk; k < sk+BLOCKSIZE; k++ )
                cij += A[i+k*n] * B[k+j*n]; /* cij += A[i][k]*B[k][j] */
            C[i+j*n] = cij; /*C[i][j] = cij */
        }
}


void dgemm ( int n, double* A, double* B, double* C ) {
    for ( int sj = 0; sj < n; sj += BLOCKSIZE )
        for ( int si = 0; si < n; si += BLOCKSIZE )
            for ( int sk = 0; sk < n; sk += BLOCKSIZE )
                do_block( n, si, sj, sk, A, B, C );
}

int main( void ) {
  const int N = 1024; // The benchmark runs on a fixed size of work
  printf( "Running DGEMM operation of size %d x 1\n", N );

  double *A = (double *) malloc( N * N * sizeof(double) ); // First vector
  double *B = (double *) malloc( N * N * sizeof(double) ); // Second vector
  double *C = (double *) malloc( N * N * sizeof(double) ); // Result vector

   // Carry out the operation
   dgemm( N, A, B, C );

   // Free up the memory
   free( A );
   free( B );
   free( C );

   return 0;
}



