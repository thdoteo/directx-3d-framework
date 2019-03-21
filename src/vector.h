#pragma once

struct VEC3
{
	float x, y, z;

	inline VEC3() {}
	inline VEC3(const float x, const float y, const float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	inline VEC3 operator + (const VEC3& A) const
	{
		return VEC3(x + A.x, y + A.y, z + A.z);
	}

	inline VEC3 operator + (const float value) const
	{
		return VEC3(x + value, y + value, z + value);
	}

	inline float Dot(const VEC3& vector) const
	{
		return vector.x*x + vector.y*y + vector.z*z;
	}

	inline VEC3 Cross(const VEC3& vector) const
	{
		return VEC3(y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
	}
};

struct VEC2
{
	float x, y;

	inline VEC2() {}
	inline VEC2(const float x, const float y)
	{
		this->x = x;
		this->y = y;
	}

	inline VEC2 operator + (const VEC2& A) const
	{
		return VEC2(x + A.x, y + A.y);
	}

	inline VEC2 operator + (const float value) const
	{
		return VEC2(x + value, y + value);
	}

	inline float Dot(const VEC2& vector) const
	{
		return vector.x*x + vector.y*y;
	}
};