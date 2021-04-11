#include <iostream>

double** matrix(int n)
{
	double** a = new double* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	return a;
}

double** input(int n) {
	double** a = new double* [n];
	std::cout << "Input:" << '\n';
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			std::cin >> a[i][j];
		}
	}
	return a;
}

void output(int n, double** a) {
     std::cout<< '\n' <<"Output:"<< '\n';
     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           std::cout << a[i][j] << " ";        
        }     
		std::cout << '\n';
    }     
}

double** multiply(double** A, double** B, int n) {
	double** C = matrix(n); 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {      
           for(int t=0; t<n; t++) {
              C[i][j] = C[i][j] + A[i][t]*B[t][j];        
           }  
        }        
     }
	return C;
}

double** add(double** A, double** B, int n) {
    double** C = matrix(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

double** sub(double** A, double** B, int n) {
    double** C = matrix(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

double** strassen(double** A, double** B, int n) {
	if (n < 64) {
		double** C = matrix(n);
		C = multiply(A,B,n);
		return C;
	}
	double** C = matrix(n);
	int k = n/2;
    double** A11 = matrix(k);
	double** A12 = matrix(k);
	double** A21 = matrix(k);
	double** A22 = matrix(k);
	double** B11 = matrix(k);
	double** B12 = matrix(k);
	double** B21 = matrix(k);
	double** B22 = matrix(k);
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
    double** P1 = strassen(A11, sub(B12, B22, k), k);
	double** P2 = strassen(add(A11, A12, k), B22, k);
	double** P3 = strassen(add(A21, A22, k), B11, k);
	double** P4 = strassen(A22, sub(B21, B11, k), k);
	double** P5 = strassen(add(A11, A22, k), add(B11, B22, k), k);
	double** P6 = strassen(sub(A12, A22, k), add(B21, B22, k), k);
	double** P7 = strassen(sub(A11, A21, k), add(B11, B12, k), k);

	double** C11 = sub(add(add(P5, P4, k), P6, k), P2, k);
	double** C12 = add(P1, P2, k);
	double** C21 = add(P3, P4, k);
	double** C22 = sub(sub(add(P5, P1, k), P3, k), P7, k);
    for(int i=0; i<k; i++){
		for(int j=0; j<k; j++) {
			C[i][j] = C11[i][j];
			C[i][j+k] = C12[i][j];
			C[k+i][j] = C21[i][j];
			C[k+i][k+j] = C22[i][j];
		}
	}
	return C;
}


int main() {
	std::cout << "Razmer kvadratnoy matrix: ";
	int N;
	std::cin >> N;
	double** a = input(N);
	double** b = input(N);
	double** c = strassen(a, b, N);
    output(N, c);
    return 0;
}

