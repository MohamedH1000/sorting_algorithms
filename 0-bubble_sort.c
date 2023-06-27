#include "sort.h"
/**
 * bubble_sort - an array of ints to be sorted by
 * this function using the bubble sort algorithm
 *
 * @array: ints in an array
 * @size: array size
 *
 */
void bubble_sort(int *array, size_t size)
{
int tem;
size_t a, c;

if (!array || !size)
{
return;
}

a = 0;
while (a < size)
{
for (c = 0; c < size - 1; c++)
{
if (array[c] > array[c + 1])
{
tem = array[c];
array[c] = array[c + 1];
array[c + 1] = tem;
print_array(array, size);
}
}
a++;
}
}
