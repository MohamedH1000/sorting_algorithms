#include "sort.h"
/**
*integer_count- integer appear in the array numbers
*@array: given the array
*@size: array size
*@ran: occurence of the number to check
*Return: number of occurences
*/
int integer_count(int *array, size_t size, int ran)
{
size_t a;
int sum = 0;

for (a = 0; a < size; a++)
{
if (array[a] == ran)
{
sum++;
}
}
return (sum);
}
/**
 *counting_sort - an algorithm that counting sort
 *@array: sort the array
 *@size: the array size
 */
void counting_sort(int *array, size_t size)
{
int z = 0, j = 0, r = 0;
size_t a, k;
int *arr2, *nArr;

if (!array || size < 2)
	return;
for (a = 0; a < size; a++)
{
if (array[a] > z)
	z = array[a];
}
arr2 = malloc(sizeof(int) * (z + 1));
if (!arr2)
	return;
for (k = 0; k < ((size_t)z + 1); k++)
{
if (k == 0)
	arr2[k] = integer_count(array, size, r);
else
{
j = arr2[k - 1] + integer_count(array, size, r);
arr2[k] = j;
}
r++;
}
print_array(arr2, (z + 1));
nArr = malloc(sizeof(int) * size);
if (!nArr)
	free(arr2);
	return;
for (a = 0; a < size; a++)
{
nArr[arr2[array[a]]-- - 1] = array[a];
}
for (a = 0; a < size; a++)
{
array[a] = nArr[a];
}
free(nArr);
free(arr2);
}
