// C program to demonstrate the use of C string.h
//header file
#include <stdio.h>
#include <string.h>

int main()
{
	// initializing some strings
	char str1[20] = "Geeksfor";
	char str2[20] = "Geeks";

	// using strlen(), strcat()
	printf("Str1: %s\n", str1);
	printf("Length of Str1 before concatenation: %d\n",
		strlen(str1));
	strcat(str1, str2); // concatenating str1 and str2
	printf("Str1: %s\n", str1);

	return 0;
}