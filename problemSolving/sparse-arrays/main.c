#include <stdlib.h>
#include <stdio.h>

int findStringLength(char* string) {
	int count = 0;

	while (*(string + count) != '\0') count++;

	return count;
}

void recursiveTest(char* string, char* query, int* result) {
	char string_letter = *(string);
	char query_letter = *(query);

	if (string_letter != '\0') {
		if (query_letter != '\0') {
			if ((string_letter ^ query_letter) == 0)
				recursiveTest(string + 1, query + 1, result);
			else
				*result = 0;
		}
	}
}

// Complete the matchingStrings function below.
// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//
int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
	*result_count = queries_count;
	int* results = malloc(sizeof(int) * *result_count);

	for (int result = 0; result < *result_count; result++) // Initialize result array.
		*(results + result) = 0;

	for (int string = 0; string < strings_count; string++) { // Iterate through every string.
		for (int query = 0; query < queries_count; query++) { // for every string, test every query...
			int string_length = findStringLength(*(strings + string));
			int query_length = findStringLength(*(queries + query));

			// If query is longer than string ignore...
			if (string_length != query_length)
				continue;

			int result = 1; // Assume match.
			recursiveTest(*(strings + string), *(queries + query), &result);

			if (result == 1)
				*(results + query) += 1;
		}
	}

	return &results[0];
}

int main() {
	/**
	 * 4
	 * aba
	 * baba
	 * aba
	 * xzxb
	 * 3
	 * aba
	 * xzxb
	 * ab
	 */
	size_t strings_count = 4;
	size_t queries_count = 3;
	char** strings = malloc(sizeof(char) * 4);
	char** queries = malloc(sizeof(char) * 3);

	*(strings) = "aba";
	*(strings + 1) = "baba";
	*(strings + 2) = "aba";
	*(strings + 3) = "xzxb";
	*(queries) = "aba";
	*(queries + 1) = "xzxb";
	*(queries + 2) = "ab";

	int results_count = 0;
	int* results = matchingStrings(strings_count, strings, queries_count, queries, &results_count);

	for (int i = 0; i < results_count; i++) {
		printf("%d\n", *(results + i));
	}

	return 0;
}

