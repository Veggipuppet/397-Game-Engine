#include "Matrix.h"

Matrix::Matrix(){
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			matrix[i][j] = 0.0f;
		}
	}
}

Matrix::Matrix(const Matrix &new_matrix){
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			this->matrix[i][j] = new_matrix.matrix[i][j];
		}
	}
}

Matrix Matrix::operator +(const Matrix &var2){
	Matrix ret;
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			ret.matrix[i][j] = this->matrix[i][j] + var2.matrix[i][j];
		}
	}
	return ret;
}

Matrix Matrix::operator *(const Matrix &var2){
	Matrix ret;
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			for (int k = 0; k < SIZE; k++){
				ret.matrix[i][j] += this->matrix[i][k] * var2.matrix[k][j];
			}
		}
	}
	return ret;
}

Matrix CreateRotationX(float rad){
	Matrix ret;
	return ret;
}

Matrix CreateRotationY(float rad){
	Matrix ret;
	return ret;
}

Matrix CreateRotationZ(float rad){
	Matrix ret;
	return ret;
}