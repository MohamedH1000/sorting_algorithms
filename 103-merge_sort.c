#include "sort.h"
/**
 * merge_compare - a function that merges to be compared
 * @array: sort the integer array
 * @begin: index beginning
 * @end: index end
 * @new: array that is output
 * Return: nothing.
 */
void merge_compare(int *array, size_t begin, size_t end, int *new)
{
size_t a = begin, b, c, middle;

b = middle = (begin + end) / 2;
printf("Merging...\n");
printf("[left]: ");
print_array(array + begin, middle - begin);
printf("[right]: ");
print_array(array + middle, end - middle);
for (c = begin; c < end; c++)
{
if (a < middle && (b >= end || array[a] <= array[b]))
{

new[c] = array[a++];
}
else
{
new[c] = array[b++];
}
}
printf("[Done]: ");
print_array(new + begin, end - begin);
}
/**
 * merge_sort_in_up_down - recursivley up and down to be sorted
 * @array: sort the integer array
 * @begin: index begin
 * @end: index end
 * @new: the array output
 * Return: nothing
 */
void merge_sort_in_up_down(int *array, size_t begin, size_t end, int *new)
{
size_t inbetween;

inbetween = (begin + end) / 2;
if (end - begin < 2)
{
return;
}
merge_sort_in_up_down(new, begin, inbetween, array);
merge_sort_in_up_down(new, inbetween, end, array);
merge_compare(new, begin, end, array);
}
/**
 * merge_sort - merge sort algorithm to sort
 * @array: sort the integer array
 * @size: the array size
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
int *new;
size_t a;

if (!array || size < 2)
{
return;
}
new = malloc(sizeof(int) * size);
if (!new)
{
return;
}
for (a = 0; a < size; a++)
{
new[a] = array[a];
}
merge_sort_in_up_down(array, 0, size, new);
free(new);
}
