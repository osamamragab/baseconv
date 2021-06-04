#include <stdio.h>
#include <string.h>
#include "utils.h"

int toupper(int c) {
  if (c < 'a' || c > 'z') {
    return c;
  }
  return c - 'a' + 'A';
}

char *skipprefix(char *input) {
	if (input[0] == '+' || input[0] == '-') {
		input++;
	}
	if (input[0] == '0') {
		input++;
	}
	char c = toupper(input[0]);
	if (c == 'B' || c == 'O' || c == 'X') {
		input++;
	}
	return input;
}

bool isbinary(const char *input) {
	for (size_t i = 0; i < strlen(input); i++) {
		if (input[i] != '0' && input[i] != '1') {
			return false;
		}
	}
	return true;
}

bool isoctal(const char *input) {
	for (size_t i = 0; i < strlen(input); i++) {
		if (input[i] < '0' || input[i] > '7') {
			return false;
		}
	}
	return true;
}

bool isdecimal(const char* input) {
	for (size_t i = 0; i < strlen(input); i++) {
		if (input[i] < '0' || input[i] > '9') {
			return false;
		}
	}
	return true;
}

bool ishex(const char *input) {
	for (size_t i = 0; i < strlen(input); i++) {
		if (input[i] < '0' || toupper(input[i]) > 'F') {
			return false;
		}
	}
	return true;
}

bool isnumber(const char *input) {
	for (size_t i = 0; i < strlen(input); i++) {
		if (input[i] < '0' || toupper(input[i]) > 'F') {
			return false;
		}
	}
	return true;
}

void printbin(long long num) {
	if (num == 0) {
		puts("0b0");
		return;
	}

	if (num < 0) {
		num = ~num + 1;
		if (num > 0) {
			putchar('-');
		}
	}

	int c = 63;
	char str[65] = {0};
	for (; num != 0 && c >= 0; c--) {
		str[c] = "01"[num&1];
		num >>= 1;
	}

	printf("0b%s\n", str+c+1);
}