#include "Vector2.h"

Vector2::Vector2()
	: x(0), y(0) {}

Vector2::Vector2(int x, int y)
	: x(x), y(y) {}

Vector2::Vector2(double x, double y)
	: x(x), y(y) {}

Vector2::Vector2(long double x, long double y)
	: x(x), y(y) {}

Vector2::Vector2(Vector2& vector)
	: x(vector.x), y(vector.y) {}

Vector2::~Vector2()
{}

// CONVERSIONS
Vector2& Vector2::operator=(const int& number)
{
	x = number;
	y = number;

	return *this;
}

Vector2& Vector2::operator=(const double& number)
{
	x = number;
	y = number;

	return *this;
}

Vector2& Vector2::operator=(const long double& number)
{
	x = number;
	y = number;

	return *this;
}

// OPERATIONS
Vector2& Vector2::add(const Vector2& vector)
{
	x += vector.x;
	y += vector.y;

	return *this;
}

Vector2& Vector2::subtract(const Vector2& vector)
{
	x -= vector.x;
	y -= vector.y;

	return *this;
}

// OPERATORS
Vector2& operator+(Vector2& v1, const Vector2& v2)
{
	return v1.add(v2);
}

Vector2& operator-(Vector2& v1, const Vector2& v2)
{
	return v1.subtract(v2);
}

Vector2& operator*(Vector2& vector, const int& number)
{
	vector.x *= number;
	vector.y *= number;

	return vector;
}

Vector2& operator+=(Vector2& v1, const Vector2& v2)
{
	return v1 + v2;
}

Vector2& operator+=(Vector2& vector, const int& number)
{
	vector.x += number;
	vector.y += number;

	return vector;
}

// OUTPUT
std::ostream& operator<<(std::ostream& out, const Vector2& vector)
{
	out << "(" << vector.x << ", " << vector.y << ")";

	return out;
}

// OTHER
void Vector2::isRangeOf(int& number) const
{
	if (this->x <= this->y)
	{
		if (number < this->x)
			number = this->x;
		else if (number > this->y)
			number = this->y;
	}
	else
	{
		if (number < this->y)
			number = this->y;
		else if (number > this->x)
			number = this->x;
	}
}

void Vector2::isRangeOf(double& number) const
{
	if (this->x <= this->y)
	{
		if (number < this->x)
			number = this->x;
		else if (number > this->y)
			number = this->y;
	}
	else
	{
		if (number < this->y)
			number = this->y;
		else if (number > this->x)
			number = this->x;
	}
}

void Vector2::isRangeOf(long double& number) const
{
	if (this->x <= this->y)
	{
		if (number < this->x)
			number = this->x;
		else if (number > this->y)
			number = this->y;
	}
	else
	{
		if (number < this->y)
			number = this->y;
		else if (number > this->x)
			number = this->x;
	}
}