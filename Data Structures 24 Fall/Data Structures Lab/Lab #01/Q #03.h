#pragma once
#include<math.h>

template<class T>
class Calculator
{
	T num1, num2;
public:
	Calculator(T a,T b)
	{
		num1 = a;
		num2 = b;
	}
	T add()
	{
		return (num1 + num2);
	}
	T multiply()
	{
		return(num1 * num2);
	}
	T subtract()
	{
		return (num1 - num2);
	}
	T divide()
	{
		if (num2 != 0)
		{
			return (num1 / num2);
		}
		else
			return 0;
	}
	T power()
	{
		return(pow(num1, num2));
	}
	T square()
	{
		return(num1 * num1);
	}
};