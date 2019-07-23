/*
Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
*/

#include <stdio.h>

#define MAXLENGTH 1000

int getline(char s[], int max);

int main() {
	int min_length = 80;
	int current_length;
	char line[MAXLENGTH];

	while ((current_length = getline(line, MAXLENGTH)) > 0) {
		if (current_length > min_length) {
			printf("%s", line);
		}
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