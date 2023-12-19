#include "sort.h"
/**
 * check_tree - swiftdown check
 * @array: pointer to array
 * @size: size of the pointer
 * @size_init: original size of the array
 * @j: index as a root of the tree
 *
**/
void check_tree(int *array, size_t size_init, size_t size, size_t j)
{

	int m, branch1, branch2;
	size_t bran1, bran2;

	bran1 = j * 2 + 1;
	bran2 = bran1 + 1;
	branch1 = array[bran1];
	branch2 = array[bran2];
	if (((bran1 < size) && (bran2 < size) &&
		(branch1 >= branch2 && branch1 > array[j]))
		|| ((bran1 == size - 1) && branch1 > array[j]))
	{
		m = array[j];
		array[j] = branch1;
		array[bran1] = m;
		print_array(array, size_init);
	}
	else if ((bran1 < size) && (bran2 < size) &&
		(branch2 > branch1 && branch2 > array[j]))
	{
		m = array[j];
		array[j] = branch2;
		array[bran2] = m;
		print_array(array, size_init);
	}
	if (bran1 < size - 1)
		check_tree(array, size_init, size, bran1);
	if (bran2 < size - 1)
		check_tree(array, size_init, size, bran2);
}
/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap
 * sort algorithm
 * @array: pointer to array
 * @size: size of the pointer
 *
**/
void heap_sort(int *array, size_t size)
{
	size_t j, size_init = size;
	int m;

	if (!array)
		return;
	for (j = 0; j < size / 2 ; j++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - j);
	}
	for (j = 0; j < size_init - 1; j++)
	{
		m = array[0];
		array[0] = array[size - 1 - j];
		array[size - 1 - j] = m;
		print_array(array, size_init);
		check_tree(array, size_init, size - j - 1, 0);
	}

}
