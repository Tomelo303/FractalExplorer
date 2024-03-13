/* NOTE:
 * Make this class using template like std::vector
 * Vector2<int>(2, 2)
 * Vector2<double>(2.5, 0.9)
 * This would get rid of the need to have multiple constructors
 * and methods for each data type
*/

#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>


class Vector2 
{
  public:
	Vector2();
	Vector2(int x, int y);
	Vector2(double x, double y);
	Vector2(long double x, long double y);
	Vector2(Vector2& vector);
	~Vector2();

	// CONVERSIONS

	Vector2& operator=(const int& number);
	Vector2& operator=(const double& number);
	Vector2& operator=(const long double& number);

	// OPERATIONS

	Vector2& add(const Vector2& vector);
	Vector2& subtract(const Vector2& vector);
	
	// OPERATORS

	friend Vector2& operator+(Vector2& v1, const Vector2& v2);
	friend Vector2& operator-(Vector2& v1, const Vector2& v2);
	friend Vector2& operator*(Vector2& vector, const int& number);

	friend Vector2& operator+=(Vector2& v1, const Vector2& v2);
	friend Vector2& operator+=(Vector2& vector, const int& number);

	// OUTPUT

	friend std::ostream& operator<<(std::ostream& out, const Vector2& vector);

	// OTHER
	
	/* Keeps the number within the range defined by instance of Vector2. */
	void isRangeOf(int& number) const;

	/* Keeps the number within the range defined by instance of Vector2. */
	void isRangeOf(double& number) const;

	/* Keeps the number within the range defined by instance of Vector2. */
	void isRangeOf(long double& number) const;

	// ATTRIBUTES

	long double x;  // First value of Vector2
	long double y;  // Second value of Vector2
};

#endif