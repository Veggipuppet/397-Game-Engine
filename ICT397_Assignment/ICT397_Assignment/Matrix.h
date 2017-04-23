#include <math.h>

// stores a matrix with size 4x4 in float
class Matrix{
	public:
		float matrix[4][4];
		static const int SIZE = 4;

		Matrix();
		Matrix(const Matrix &new_matrix);

		Matrix operator +(const Matrix &var2);
		Matrix operator *(const Matrix &var2);
		
		Matrix CreateRotationX(float rad);
		Matrix CreateRotationY(float rad);
		Matrix CreateRotationZ(float rad);

	private:
};