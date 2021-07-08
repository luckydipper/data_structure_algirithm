// worst case.
// The number which we find lied on last of array.
// T(n) = log_2 (n) + 1. 1»ı·«. 
// n, n/2, n/4, n/8 .... 1 -> (1/2)^n
// Reculsive == Stack + Iteration

// raw array, target -> target index
int binarySearch(int const target, int range[], int const range_len);



int binarySearch(int const target, int range[], int const range_len)
{
	int first = 0;
	int last  = range_len - 1;

	while (1) {
		int mid = (first + last) / 2;

		// target is not exist in the array
		if (first > last)
			return -1;

		// mid is target
		if (target == range[mid])
			return mid;

		// target is bigger then median 
		if (target > range[mid])
			first = mid + 1;

		//target is smaller then median 
		if (target < range[mid])
			last = mid - 1;
	}
}
