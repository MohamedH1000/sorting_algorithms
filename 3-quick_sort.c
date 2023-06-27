#include "sort.h"
/**
 * swap - a function that 2 int value to be swapped
 * @array: sort this integer array
 * @size: the array size
 * @i: first value address
 * @j: second value address
 * Return: Nothing
 */
void swap(int *array, size_t size, int *i, int *j)
{
if (*i != *j)
{
*i = *i + *j;
*j = *i - *j;
*i = *i - *j;
print_array((const int *)array, size);
}
}

/**
* lomuto_partition - a function that array to get partitioned
* @array: sort the array integer
* @size: the array size
* @lw: the sort range low index
* @hg: the sort range high index
* Return: nothing to return
*/
size_t lomuto_partition(int *array, size_t size, ssize_t lw, ssize_t hg)
{
int a, b, pv = array[hg];

for (a = b = lw; b < hg; b++)
{
if (array[b] < pv)
swap(array, size, &array[b], &array[a++]);
}
swap(array, size, &array[a], &array[hg]);
return (a);
}

/**
 * quicksort - a function that wuicksort via lmoa partitionaning
 * schema
 * @array: sort the integer array
 * @size: the array size
 * @lw: sort range low index
 * @hg: sort range high index
 * Return: Nothing
 */
void quicksort(int *array, size_t size, ssize_t lw, ssize_t hg)
{
if (lw < hg)
{
size_t b = lomuto_partition(array, size, lw, hg);

quicksort(array, size, lw, b - 1);
quicksort(array, size, b + 1, hg);
}
}

/**
 * quick_sort - a function that calls the quicksort function
 * @array: sort the integer of array
 * @size: the array size
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
if (!array || !size)
{
return;
}
quicksort(array, size, 0, size - 1);
}
