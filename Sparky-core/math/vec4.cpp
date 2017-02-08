#include "vec4.h"

namespace engine {	namespace math {
	
	vec4::vec4(const float& x,const  float& y, const float& z, const float& w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4& vec4::add(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}

	vec4& vec4::subtract(const vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}
	vec4& vec4::multiply(const vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;

		return *this;
	}

	vec4& vec4::divide(const vec4& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;

		return *this;
	}

	std::ostream& operator << (std::ostream& stream, const vec4& vector)
	{
		stream << "vec4: (" << vector.x << "," << vector.y << "," << vector.z << "," << vector.w << ")";
		return stream;
	}

	vec4& vec4::operator+=(const vec4& other)
	{
		return add(other);
	}

	vec4& vec4::operator-=(const vec4& other)
	{
		return subtract(other);
	}

	vec4& vec4::operator*=(const vec4& other)
	{
		return multiply(other);
	}

	vec4& vec4::operator/=(const vec4& other)
	{
		return divide(other);
	}

	bool vec4::operator==(const vec4& other)
	{
		if ((this->x == other.x) && (this->y == other.y) && (this->z == other.z) && (this->w == other.w))
			return true;
		else
			return false;		
	}

	bool vec4::operator!=(const vec4& other)
	{
		return !(*this == other);
	}

	vec4 operator+(vec4 left, const vec4& right)
	{
		return left.add(right);
	}

	vec4 operator-(vec4 left, const vec4& right)
	{
		return left.subtract(right);
	}
	vec4 operator*(vec4 left, const vec4& right)
	{
		return left.multiply(right);
	}
	vec4 operator/(vec4 left, const vec4& right)
	{
		return left.divide(right);
	}
} }