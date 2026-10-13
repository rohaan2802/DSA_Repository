#pragma once


char fun(char ch1, char ch2)
{
	if (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'A' && ch2 <= 'Z')
	{
		return ch1;
	}


	if (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'a' && ch2 <= 'z')
	{
		return ch1 - 32;
	}
	
	if (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'a' && ch2 <= 'z')

	{
		return ch2 - 32;
	}
	
	if (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'A' && ch2 <= 'Z')

	{
		return ch1 - 32;
	}
}