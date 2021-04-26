#include <iostream>
#include <time.h> 
#include <cstdlib>

long long** matrix(int n)
{
	long long** a = new long long* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new long long[n];
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	return a;
}

long long** input(int n, int f) {
	long long** a = new long long* [f];
	for (int i = 0; i < f; i++)
	{
		a[i] = new long long[f];
		for (int j = 0; j < f; j++)
		{
			if(i<n)
				a[i][j] = rand()%10;
			else
				a[i][j] = 0;
		}
	}
	return a;
}

void output(int n, long long** a) {
     std::cout<< '\n' <<"Output:"<< '\n';
     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           std::cout << a[i][j] << " ";        
        }     
		std::cout << '\n';
    }     
}

long long** multiply(long long** A, long long** B, int n) {
	long long** C = matrix(n); 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {      
           for(int t=0; t<n; t++) {
              C[i][j] = C[i][j] + A[i][t]*B[t][j];        
           }  
        }        
     }
	return C;
}

long long** add(long long** A, long long** B, int n) {
    long long** C = matrix(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

long long** sub(long long** A, long long** B, int n) {
    long long** C = matrix(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

long long** strassen(long long** A, long long** B, int n) {
	if (n == 1) {
    long long** C = matrix(1);
    C[0][0] = A[0][0] * B[0][0];
    return C;
	}	
	
	if (n < 64) {
		long long** C = matrix(n);
		C = multiply(A,B,n);
		return C;
	}
	
	long long** C = matrix(n);
	int k = n/2;
    long long** A11 = matrix(k);
	long long** A12 = matrix(k);
	long long** A21 = matrix(k);
	long long** A22 = matrix(k);
	long long** B11 = matrix(k);
	long long** B12 = matrix(k);
	long long** B21 = matrix(k);
	long long** B22 = matrix(k);
	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][k+j];
			A21[i][j] = A[k+i][j];
			A22[i][j] = A[k+i][k+j];
			B11[i][j] = B[i][j];
			B12[i][j] = B[i][k+j];
			B21[i][j] = B[k+i][j];
			B22[i][j] = B[k+i][k+j];
		}
	} 
    long long** P1 = strassen(add(A11, A22, k), add(B11, B22, k), k);
	long long** P2 = strassen(add(A21, A22, k), B11, k);
	long long** P3 = strassen(A11, sub(B12, B22, k), k);
	long long** P4 = strassen(A22, sub(B21, B11, k), k);
	long long** P5 = strassen(add(A11, A12, k), B22, k);
	long long** P6 = strassen(sub(A21, A11, k), add(B11, B12, k), k);
	long long** P7 = strassen(sub(A12, A22, k), add(B21, B22, k), k);

	long long** C11 = add(sub(add(P1, P4, k), P5, k), P7, k);
	long long** C12 = add(P3, P5, k);
	long long** C21 = add(P2, P4, k);
	long long** C22 = add(sub(add(P3, P1, k), P2, k), P6, k);
    for(int i=0; i<k; i++){
		for(int j=0; j<k; j++) {
			C[i][j] = C11[i][j];
			C[i][j+k] = C12[i][j];
			C[k+i][j] = C21[i][j];
			C[k+i][k+j] = C22[i][j];
		}
	}
	for(int i=0; i<k; i++) {
		delete[] A11[i];
		delete[] A12[i];
		delete[] A21[i];
		delete[] A22[i];
		delete[] B11[i];
		delete[] B12[i];
		delete[] B21[i];
		delete[] B22[i];
		delete[] P1[i];
		delete[] P2[i];
		delete[] P3[i];
		delete[] P4[i];
		delete[] P5[i];
		delete[] P6[i];
		delete[] P7[i];
		delete[] C11[i];
		delete[] C12[i];
		delete[] C21[i];
		delete[] C22[i];
    }
        
    delete[] A11;
    delete[] A12;
    delete[] A21;
    delete[] A22;
    delete[] B11;
    delete[] B12;
    delete[] B21;
    delete[] B22;
    delete[] P1;
    delete[] P2;
    delete[] P3;
    delete[] P4;
    delete[] P5;
    delete[] P6;
    delete[] P7;
    delete[] C11;
    delete[] C12;
    delete[] C21;
    delete[] C22;
	return C;
}


int main() {
	std::cout << "Razmer kvadratnoy matrix: ";
	int N,f;
	std::cin >> N;

	f = 1;
	while(f<N)
		f*=2;

	long long** a = input(N, f);
	long long** b = input(N, f);

	clock_t start1 = clock();
	long long** c1 = strassen(a, b, f);
	clock_t end1 = clock();
	double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
		
	clock_t start2 = clock();
	long long** c2 = multiply(a, b, N);
	clock_t end2 = clock();
	double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

	//output(N, a);
	//output(N, b);

	//output(N, c1);
	//output(N, c2);
	
	std::cout << seconds1 << " " << seconds2 <<std::endl;
	std::cout << std::endl;

    return 0;
}

