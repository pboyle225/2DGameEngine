#include "vec3.h"

namespace engine {	namespace math {
	
	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(const float& x,const  float& y, const float & z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& vec3::add(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	vec3& vec3::subtract(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}
	vec3& vec3::multiply(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	vec3& vec3::divide(const vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	vec3& vec3::normalize()
	{
		float length = sqrt((x * x) + (y * y) + (0 * z));

		if (length != 0)
		{
			x = x / length;
			y = y / length;
			z = z / length;
		}

		return *this;
	}
	float vec3::distance(math::vec3 vec)
	{
		float diffx = this->x - vec.x;
		float diffy = this->y - vec.y;
		float diffZ = this->z - vec.z;

		return sqrt((diffx * diffx) + (diffy * diffy) + (diffZ * diffZ));
	}


	std::ostream& operator << (std::ostream& stream, const vec3& vector)
	{
		stream << "vec3: (" << vector.x << "," << vector.y << "," << vector.z <<")";
		return stream;
	}

	vec3& vec3::operator+=(const vec3& other)
	{
		return add(other);
	}

	vec3& vec3::operator-=(const vec3& other)
	{
		return subtract(other);
	}

	vec3& vec3::operator*=(const vec3& other)
	{
		return multiply(other);
	}

	vec3& vec3::operator/=(const vec3& other)
	{
		return divide(other);
	}

	bool vec3::operator==(const vec3& other)
	{
		if ((this->x == other.x) && (this->y == other.y) && (this->z == other.z))
			return true;
		else
			return false;		
	}

	bool vec3::operator!=(const vec3& other)
	{
		return !(*this == other);
	}

	vec3 operator+(vec3 left, const vec3& right)
	{
		return left.add(right);
	}

	vec3 operator-(vec3 left, const vec3& right)
	{
		return left.subtract(right);
	}
	vec3 operator*(vec3 left, const vec3& right)
	{
		return left.multiply(right);
	}
	vec3 operator/(vec3 left, const vec3& right)
	{
		return left.divide(right);
	}
} }