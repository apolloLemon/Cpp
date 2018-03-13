#include <iostream>
#include <array>

const int mtrxSize = 10;

using namespace std;
using line = array<int, mtrxSize>;
using matrix = array<line, mtrxSize>;

matrix matrix_product (matrix a, matrix b){
	matrix out;
	for(int i=0; i<mtrxSize; i++){
		for(int j=0; j<mtrxSize; j++){
			int outBox = 0;
			for(int k=0; k<mtrxSize; k++){
				outBox += a[i][k]*b[k][j];
			}
			out[i][j] = outBox;
		}
	}
	return out;
}

matrix matrix_square (matrix a) {
	return matrix_product(a,a);
}

void matrix_print (matrix a){
	for(int i=0; i<mtrxSize; i++){
		for(int j=0; j<mtrxSize; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void matrix_get (matrix &a){
	for(int i=0; i<mtrxSize; i++){
		for(int j=0; j<mtrxSize; j++){
			cin >> a[i][j];
		}
	}
}

int main (){
	matrix a;
	matrix_get(a);
	cout << endl;
	matrix_print(matrix_square(a));
	return 0;
}