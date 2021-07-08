#include <stdio.h>
#include <string.h>

// time complexity : How long does The algorithm end.
// space complexity : How large does the algorithm takes.
// we calculate the number of main calculation.
// the more data, the more num of calculation.
// We need tendency(∞Ê«‚º∫), BIG-O notion.

int sequentialSearch(int find_num, int range[], int arr_len);
int binarySearch(int const target, int range[], int const range_len);

int main() {
	int empty_array[]  = { 0 };
	int raw_array[]    = { 4, 3, 9, 1, 8, 3, 0, 6, 0 };
	int sorted_array[] = { 0, 0, 1, 3, 3, 4, 6, 8, 9 };

	// memset, memcopy, 
	// errno_t copy_complete = memcpy_s(empty_array, sizeof(empty_array), raw_array, sizeof(raw_array));

	int index = sequentialSearch( 1, raw_array, sizeof(raw_array)/sizeof(int) );
	printf("%d\n", index);

	int indexs = binarySearch(9, sorted_array, sizeof(sorted_array) / sizeof(int));
	printf("%d\n", indexs);
}