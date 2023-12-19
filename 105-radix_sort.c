#include "sort.h"
/**
 * max_val - gets max value from array
 * @array: pointer to array
 * @size: size of the array
 * Return: max value from array
 */
int max_val(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * radix_sort - sorts an array of integers is ASC
 * order implementing Radix Sort algorithm
 * @array: pointer to array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *new_arr;
	int i, max, x = 1;
	int tmp = size;

	if (!array || size < 2)
		return;

	max = max_val(array, size);

	new_arr = malloc(sizeof(int) * size);
	while (max / x > 0)
	{
		int son[20] = {0};

		i = 0;

		while (i < tmp)
		{
			son[(array[i] / x) % 10]++;
			i++;
		}

		if (son != NULL)
		{
			for (i = 1; i < 10; i++)
				son[i] += son[i - 1];

			for (i = tmp - 1; i >= 0; i--)
			{
				new_arr[son[(array[i] / x) % 10] - 1] = array[i];
				son[(array[i] / x) % 10]--;
			}

			for (i = 0; i < tmp; i++)
				array[i] = new_arr[i];
		}
		x *= 10;
		print_array(array, size);
	}
	free(new_arr);
}
