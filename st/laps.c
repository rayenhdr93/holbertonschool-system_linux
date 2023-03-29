#include "laps.h"
/**
* race_state - race state
* @id: array of the cars in the lap
* @size: size of id
* Return: return if id is null
*/
void race_state(int *id, size_t size)
{
	size_t i, j;
	int x, y, temp, temp1;
	static int siz;
	static int arraycar[1000];
	static int arraylaps[1000];

	if (!id)
		return;
	for (i = 0; i < size; i++)
	{
		j = 0;
		while (id[i] != arraycar[j] && arraycar[j] != 0)
			j++;
		if (id[i] != arraycar[j])
		{
			printf("Car %d joined the race\n", id[i]);
			siz++;
			arraycar[j] = id[i];
		}
		else
			arraylaps[j] = arraylaps[j] + 1;
	}
	for (x = 0; x < siz; x++)
		for (y = x + 1; y < siz; y++)
			if (arraycar[x] > arraycar[y])
			{
				temp = arraycar[x];
				temp1 = arraylaps[x];
				arraycar[x] = arraycar[y];
				arraylaps[x] = arraylaps[y];
				arraycar[y] = temp;
				arraylaps[y] = temp1;
			}
	j = 0;
	printf("Race state:\n");
	while (arraycar[j] != 0)
	{
		printf("Car %d [%d laps]\n", arraycar[j], arraylaps[j]);
		j++;
	}
}
