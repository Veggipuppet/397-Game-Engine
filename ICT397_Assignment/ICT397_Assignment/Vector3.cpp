#include "Vector3.h"

Vector3::Vector3(float var1, float var2, float var3){
	x = var1;
	y = var2;
	z = var3;
}

Vector3::Vector3(const Vector3 &new_vector3){
	this->x = new_vector3.x;
	this->y = new_vector3.y;
	this->z = new_vector3.z;
}

Vector3 Vector3::operator +(const Vector3 &var2){
	Vector3 ret;
	ret.x = this->x + var2.x;
	ret.y = this->y + var2.y;
	ret.z = this->z + var2.z;
	return ret;
}

Vector3 Vector3::operator -(const Vector3 &var2){
	Vector3 ret;
	ret.x = this->x - var2.x;
	ret.y = this->y - var2.y;
	ret.z = this->z - var2.z;
	return ret;
}

Vector3 Vector3::operator *(const Vector3 &var2){
	Vector3 ret;
	ret.x = this->x * var2.x;
	ret.y = this->y * var2.y;
	ret.z = this->z * var2.z;
	return ret;
}

Vector3 Vector3::operator *(const float &scale){
	Vector3 ret;
	ret.x = this->x * scale;
	ret.y = this->y * scale;
	ret.z = this->z * scale;
	return ret;
}

Vector3 Vector3::operator /(const Vector3 &var2){
	Vector3 ret;
	ret.x = this->x / var2.x;
	ret.y = this->y / var2.y;
	ret.z = this->z / var2.z;
	return ret;
}

bool Vector3::operator ==(const Vector3 &var2){
	if ((this->x == var2.x) && (this->y == var2.y) && (this->z == var2.z)){
		return true;
	}
	else{
		return false;
	}
}

bool Vector3::operator !=(const Vector3 &var2){
	if ((this->x == var2.x) && (this->y == var2.y) && (this->z == var2.z)){
		return false;
	}
	else{
		return true;
	}
}