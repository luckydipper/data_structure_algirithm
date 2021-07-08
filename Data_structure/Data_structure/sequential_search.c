// worst case.
// The number which we find lied on last of array.
// T(n) = n
// raw array, target -> target index 
int sequentialSearch(int find_num, int range[], int arr_len);

int sequentialSearch(int find_num, int range[], int arr_len)
{
	for (int i = 0; i < arr_len; i++)
	{
		if (range[i] == find_num)
			return i;	// find num index
	}
	return -1;
}