class Vector3{
	public:
		float x, y, z;

		Vector3(){ x = y = z = 0.0f; };
		Vector3(const Vector3 &new_vector3);
		~Vector3(){};
		Vector3(float var1, float var2, float var3);

		Vector3 operator +(const Vector3 &var2);
		Vector3 operator -(const Vector3 &var2);
		Vector3 operator *(const Vector3 &var2);
		Vector3 operator *(const float &scale);
		Vector3 operator /(const Vector3 &var2);
		bool operator ==(const Vector3 &var2);
		bool operator !=(const Vector3 &var2);
};