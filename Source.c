
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int alphavit(int x) {
	return (('a' <= x) && (x <= 'z')) || (('A' <= x) && (x <= 'Z'));
}

int ponizhenie(int x) {
	if (('A' <= x) && x <= 'Z')
		return (x + 32);
	else
		return x;
}

int slovo(char str[], char* begin[], char* end[]) {
	while (*str && !alphavit(*str)) {
		++str;
	}
	*begin = str;
	while (alphavit(*str)) {
		++str;
	}
	*end = str;
	return *end - *begin;
}

int proverka(char* begin, char* end) {
	while (begin < end && ponizhenie(*begin) == ponizhenie(*end)) {
		++begin;
		--end;
	}
	return (*begin == *end);
}

int main() {
	char string[100], * str;
	printf("Input string:\n");
	fgets(string, 100, stdin);
	if (string[0] == '\n' || string[0] == ' ') {
		printf("Empty string");
	}
	else {
		str = string;
		char* begin, * end;
		int len;
		len = slovo(str, &begin, &end);
		printf("Result:\n");
		while ((len = slovo(str, &begin, &end)) > 0) {
			if (proverka(begin, end - 1)) {
				printf("%.*s ", len, begin);
			}
			str = end;
		}
	}
	return 0;
}