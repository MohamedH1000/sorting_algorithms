#include "sort.h"
/**
 *selection_sort- select using sort algorithm by this function
 *@array: to be sorted by this array
 *@size: array size
 */
void selection_sort(int *array, size_t size)
{
    size_t a, b, c;
    int tem;

    if (!array || !size)
    {
        return;
    }
    for (a = 0; a < size - 1; a++)
    {
        for (b = size - 1, c = a + 1; b > a; b--)
        {
            if (array[b] < array[c])
            {
                c = b;
            }
        }
        if (array[a] > array[c])
        {
            tem = array[a];
            array[a] = array[c];
            array[c] = tem;
            print_array(array, size);
        }
    }
}
