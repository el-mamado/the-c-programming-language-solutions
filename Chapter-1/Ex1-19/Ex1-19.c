/*
Exercise 1-19. Write a function reverse (s) that reverses the character string s.
Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAXLENGTH 1000

int getline(char s[], int max);
void reverse(char s[]);

int main() {
	char line[MAXLENGTH];

	// gets one line at a time and reverses it.
	while (getline(line, MAXLENGTH) > 0) {
		reverse(line);
		printf("%s", line);
	}

}

/* getline: read a line into s, return length */
int getline(char s[], int max) {
	int i, c;
	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[]) {
	int length;
	int temp;

	// gets the legnth of the string
	for (length = 0; s[length] != '\0'; length++)
		;
	
	for (int i = 0; i < (length / 2); i++) {
		temp = s[i];
		s[i] = s[length - 1 - i]; // length - 1 to avoid changing the null terminatin 
		s[length - 1 - i] = temp;
	}
	
}