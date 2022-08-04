#include "dog.h"
#include <stdlib.h>


/**
 * free_dog - Function that frees dog.
 * @d: dog info
 *
 * Description: it frees dog
 * Return: nothing.
 */

void free_dog(dog_t *d)
{
	if (!d)
		return;
	free((*d).name);
	free((*d).owner);
	free(d);
}
