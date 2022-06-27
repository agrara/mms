#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <math.h>    // -lm
#include <pthread.h> // - ptread
#include <semaphore.h>
#include <stdint.h>

#define ITEMS_COUNT 10

typedef struct
{
    uint16_t number;
    char desc[251];
    double weigth;
    double price;
} Item;

typedef struct Node
{
    Item item;
    struct Node *next;
} Node;

void generateNumber(Node *HEAD, Node *newNode)
{
    uint16_t generatedNumber;
    Node *currentNode;
    int isPresent = 0;
    while (1)
    {
        generatedNumber = rand() % 65535 + 1;
        if (HEAD == newNode)
        {
            newNode->item.number = generatedNumber;
            break;
        }
        if (currentNode->next)
        {
            if (currentNode->item.number == generatedNumber)
            {
                isPresent = 1;
            }
            currentNode = currentNode->next;
        }
        else
        {
            if (currentNode->item.number == generatedNumber)
            {
                isPresent = 1;
            }
            if (isPresent == 0)
            {
                newNode->item.number = generatedNumber;
                break;
            }
        }
    }
}

char *firstWordGenerator()
{
    int wordLength = rand() % 10 + 1;
    char *newWord = malloc(wordLength * sizeof(char));
    newWord[0] = rand() % 26 + 65;
    for (int i = 1; i < wordLength; i++)
    {
        newWord[i] = rand() % 26 + 97;
    }
    return newWord;
}

char *otherWordsGenerator()
{
    int wordLength = rand() % 10 + 1;
    char *newWord = malloc(wordLength * sizeof(char));
    for (int i = 0; i < wordLength; i++)
    {
        newWord[i] = rand() % 26 + 97;
    }
    return newWord;
}

void generateDesc(Node *newNode)
{
    char *currentWord;
    char desc[101];
    int sym = 0;
    int numWords = rand() % 6 + 5;
    for (int i = 0; i < numWords; i++)
    {
        if (i == 0)
        {
            currentWord = firstWordGenerator();
        }
        else
        {
            currentWord = otherWordsGenerator();
        }
        for (int j = sym; j < sym + sizeof(currentWord); j++)
        {
            desc[j] = currentWord[sym + sizeof(currentWord)];
        }
        desc[sym + sizeof(currentWord) + 1] = 0;
        sym += sizeof(currentWord) + 2;
        free(currentWord);
    }
    strcpy(newNode->item.desc, desc);
}

void weigthGenerate(Node *newNode)
{
    newNode->item.weigth = (rand() % 10000) / 100;
}

void priceGenerate(Node *newNode)
{
    newNode->item.weigth = (rand() % 150000) / 100 + 1;
}

double totalItemsWeight(Node *HEAD)
{
    double weigth = 0;
    Node *currentNode = HEAD;
    while (currentNode)
    {
        weigth += currentNode->item.weigth;
        currentNode = currentNode->next;
    }
}

Node *minPriceItem(Node *HEAD)
{
    if (!HEAD)
    {
        return NULL;
    }
    int minPrice = HEAD->item.price;
    Node *minPriceNodeAddress;
    Node *currentNode = HEAD->next;
    while (currentNode)
    {
        if (currentNode->item.price < minPrice)
        {
            minPriceNodeAddress = currentNode;
            currentNode = currentNode->next;
        }
        currentNode = currentNode->next;
    }
    return minPriceNodeAddress;
}

int main()
{
    Node *HEAD = NULL;
    srand(time(NULL));
    for (int i = 0; i < ITEMS_COUNT; i++)
    {
        if (HEAD = NULL)
        {
            HEAD = malloc(sizeof(Node));
            HEAD->next = NULL;
            generateNumber(HEAD, HEAD);
            generateDesc(HEAD);
            priceGenerate(HEAD);
            weigthGenerate(HEAD);
        }
        else
        {
            Node *currentNode = HEAD;
            while (currentNode->next)
            {
                currentNode = currentNode->next;
            }
            Node *newNode = malloc(sizeof(Node));
            currentNode->next = newNode;
            newNode->next = NULL;
            generateNumber(HEAD, newNode);
            generateDesc(newNode);
            weigthGenerate(newNode);
            priceGenerate(newNode);
        }
    }

    Node *currentNode = HEAD;
    while (currentNode)
    {
        printf("%d %s %.2lf %.2lf\n", currentNode->item.number, currentNode->item.desc, currentNode->item.price, currentNode->item.weigth);
    }
}