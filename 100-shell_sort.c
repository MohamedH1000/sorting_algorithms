#include "sort.h"
/**
 * get_max_gap - a largest knuth gap size to be get
 * @size: the array size
 * Return: the size of the gap
 */
size_t get_max_gap(size_t size)
{
size_t value;

value = 1;
while (value < size)
{
value = value * 3 + 1;
}
return ((value - 1) / 3);
}

/**
* shell_sort - a function that sort the shell
* @array: the array of integers to be sorted
* @size: the array size
* Return: nothing
*/
void shell_sort(int *array, size_t size)
{
size_t vagwa, a, b;
int moakt;

if (!array || !size)
{
return;
}

for (vagwa = get_max_gap(size); vagwa; vagwa = (vagwa - 1) / 3)
{
for (a = vagwa; a < size; a++)
{
moakt = array[a];
for (b = a; b > vagwa - 1 && array[b - vagwa] > moakt; b -= vagwa)
{
array[b] = array[b - vagwa];
}
array[b] = moakt;
}
print_array(array, size);
}
}
