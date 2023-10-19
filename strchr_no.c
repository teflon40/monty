#include "monty.h"

/**
 * strchr_no - locates the first occurrence in the string s
 * of any bytes in the string accept
 * @s: a string
 * @c: a character
 * Return: the index of the byte in s that matches c
 */
size_t strchr_no(const char *s, int c)
{
	size_t pos;

	for (pos = 0; s[pos] != '\0' && s[pos] != c; pos++)
		;
	return (pos);
}
