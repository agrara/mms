#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdint.h>

#define COUNT 5

typedef struct Book
{
	char title[150];
	char author[100];
	int numPages;
	double price;
} Book;

// Generators
char *stringGenerator(const int minLength, const int maxLength)
{
	int numChars;

	numChars = (rand() % (maxLength + 1 - minLength)) + minLength;
	char *str = malloc(sizeof(char) * numChars + 1);
	str[0] = (rand() % 26) + 65;
	str[numChars] = 0;

	for (int i = 1; i < numChars + 1; i++)
	{
		str[i] = (rand() % 26) + 97;
	}

	return str;
}

Book *bookGenerator()
{
	Book *newBook = (Book *)malloc(sizeof(Book));
	char *tmpTitle = stringGenerator(10, 20);
	char *tmpAuthor = stringGenerator(10, 20);

	strcpy(newBook->title, tmpTitle);
	strcpy(newBook->author, tmpAuthor);
	free(tmpTitle);
	free(tmpAuthor);

	newBook->numPages = (rand() % 1996) + 5;
	newBook->price = (rand() % 100001) / 100.0 + 1.0;

	return newBook;
}

Book *bookCollectionGenerator()
{
	Book *bookCollection = (Book *)malloc(sizeof(Book) * COUNT);
	for (int i = 0; i < COUNT; ++i)
	{
		Book *tmpBook = bookGenerator();
		memcpy(&bookCollection[i], tmpBook, sizeof(Book));
		free(tmpBook);
	}
	return bookCollection;
}

// Comparators
int compareByTitle(const void *firstBookPtr, const void *secondBookPtr)
{
	return strcmp(((Book *)firstBookPtr)->title, ((Book *)secondBookPtr)->title);
}

int compareByAuthorReversed(const void *firstBookPtr, const void *secondBookPtr)
{
	return (-1) * (strcmp(((Book *)firstBookPtr)->author, ((Book *)secondBookPtr)->author));
}

int compareByPages(const void *firstBookPtr, const void *secondBookPtr)
{
	return ((Book *)firstBookPtr)->numPages - ((Book *)secondBookPtr)->numPages;
}

int compareByPrice(const void *firstBookPtr, const void *secondBookPtr)
{
	double epsilon = 0.001;
	if (fabs(((Book *)firstBookPtr)->price - ((Book *)secondBookPtr)->price) > epsilon && ((Book *)firstBookPtr)->price - ((Book *)secondBookPtr)->price > 0)
	{
		return 1;
	}
	else if (fabs(((Book *)firstBookPtr)->price - ((Book *)secondBookPtr)->price) > epsilon && ((Book *)firstBookPtr)->price - ((Book *)secondBookPtr)->price < 0)
	{
		return -1;
	}
	else
		return 0;
}

int comparePrice(const void *key, const void *book)
{
	double epsilon = 0.001;
	return !(fabs(*((double *)key) - ((Book *)book)->price) < epsilon);
}

// Sorting and searching

void swapuni(void *ptr1, void *ptr2, size_t size)
{
	uint8_t temp[size];
	memmove(temp, ptr2, size);
	memmove(ptr2, ptr1, size);
	memmove(ptr1, temp, size);
}

void bubbleSort(void *arr, size_t n, size_t size, int (*cmp)(const void *, const void *))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - i - 1) * size; j += size)
		{
			if (cmp(arr + j, arr + j + size) > 0)
			{
				swapuni(arr + j, arr + j + size, size);
			}
		}
	}
}

int *lsearch(void *key, void *arr, size_t n, size_t size, int (*cmp)(const void *, const void *))
{
	for (int i = 0; i < n * size; i += size)
	{
		if (cmp(key, arr + i) == 0)
		{
			return arr + i;
		}
	}
	return NULL;
}

// Printing results
void showInfo(Book *books, int numBooks)
{
	for (int i = 0; i < numBooks; i++)
	{
		printf("Book %d | Title: %s | Author: %s | Pages: %d | Price: %.2lf\n", i, books[i].title, books[i].author, books[i].numPages, books[i].price);
	}
	putchar('\n');
}

void showSorted(void *arr, size_t n, size_t size)
{
	printf("Books sorted by title\n");
	bubbleSort(arr, n, size, compareByTitle);
	showInfo((Book *)arr, n);

	printf("Books sorted by author reversed\n");
	bubbleSort(arr, n, size, compareByAuthorReversed);
	showInfo((Book *)arr, n);

	printf("Books sorted by pages number\n");
	bubbleSort(arr, n, size, compareByPages);
	showInfo((Book *)arr, n);

	printf("Books sorted by price\n");
	bubbleSort(arr, n, size, compareByPrice);
	showInfo((Book *)arr, n);
}

int main()
{
	double key = 20.50;

	srand(time(0));
	Book *collection = bookCollectionGenerator();

	// Uncomment the next line for testing the case when a book with a price of 20.50 exists.
	// (collection + 1)->price = 20.50;

	showSorted((void *)collection, COUNT, sizeof(Book));

	Book *bookPtr = (Book *)lsearch((void *)(&key), (void *)collection, COUNT, sizeof(Book), comparePrice);
	if (bookPtr == NULL)
	{
		printf("No book with a price of %.2lf found.\n", key);
	}
	else
	{
		printf("The book with the title %s is the first one with a price of %.2lf.\n", bookPtr->title, key);
	}

	free(collection);
}