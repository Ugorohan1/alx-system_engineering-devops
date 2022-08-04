#include "dog.h"
#include <stdlib.h>

char *dup(char *s);
int _strlen(char *s);

/**
 * new_dog - Information of a new dog
 * @name: dog name
 * @age: dog's age
 * @owner: owner of dog.
 *
 * Return: success
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	char *dup_name, *dup_owner;

	if (name == NULL || owner == NULL)
		return (NULL);
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dup_name = dup(name);
	if (dup_name == NULL)
	{
		free(dog);
		return (NULL);
	}
	(*dog).name = dup_name;
	(*dog).age = age;
	
	dup_owner = dup(owner);
	if (dup_owner == NULL)
	{
		free((*dog).name);
		free(dog);
		return (NULL);
	}
	(*dog).owner = dup_owner;
	return (dog);
}

/**
 * dup - Duplicates s
 * @s: string to be duplicated
 *
 * Return: success
 */

char *dup(char *s)
{
	char *res;
	int i, len;

	if (s == NULL)
		return (NULL);
	len = _strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/**
 * _strlen - length of string.
 * @s: string.
 *
 * Return: length
 */

int _strlen(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
