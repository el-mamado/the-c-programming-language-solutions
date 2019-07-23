/*
Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
*/

#include <stdio.h>

#define MAXLENGTH 1000

int getline(char s[], int max);

int main() {

	int i; // index
	char line[MAXLENGTH];

	while ((i = getline(line, MAXLENGTH)) > 0) {
		// since all lines will be terminated by '\0' then we decrementing the index by 1.
		i--;

		// decrementing the index whenever we fint a blank, a tab, or a newline.
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
			i--;
		}
		
		// here we have the index of the last character in our line.
		// add a new line and a string terminating character
		line[++i] = '\n';
		line[++i] = '\0';

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