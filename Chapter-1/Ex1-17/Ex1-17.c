/*
Author: el-mamado
Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

#define MAXLENGTH 1000

int getLineLength(char line[]);
void printLine(char line[]);

int main() {
	int min_length = 80;
	int current_length;
	char line[MAXLENGTH];

	while ((current_length = getLineLength(line)) > 0) {
		if (current_length > min_length) {
			printLine(line);
		}
	}
}

/* getLineLength: read a line into s, return length */
int getLineLength(char line[]) {
	int c, i;

	for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
		i++;
	}

	line[i] = '\0';  // add string terminating character.
	return i; // the length of the read line.
}

void printLine(char line[]) {

	for (int i = 0; line[i] != '\0'; i++) {
		printf("%c", line[i]);
	}
}