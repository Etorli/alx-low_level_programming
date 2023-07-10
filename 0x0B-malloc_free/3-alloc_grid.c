#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make the grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **mee;
	int i, a;

	if (width <= 0 || height <= 0)
		return (NULL);

	mee = malloc(sizeof(int *) * height);

	if (mee == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		mee[i] = malloc(sizeof(int) * width);

		if (mee[i] == NULL)
		{
			for (; i >= 0; i--)
				free(mee[i]);

			free(mee);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
	{
		for (a = 0; a < width; a++)
			mee[i][a] = 0;
	}

	return (mee);
}

