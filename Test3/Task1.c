#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define COUNT 10

typedef struct
{
    double x;
    double y;
} Point;

typedef struct
{
    Point a;
    Point b;
} Rectangle;

typedef struct Node
{
    Rectangle rectangle;
    struct Node *next;
} Node;

void generateRectangle(Rectangle *);
void generateRectangleList(Node **);
double calculateNodeArea(Node *node);
double areaRects(Node *list);
void filterRects(Node **, double, double);

int main()
{
    Node *HEAD = NULL;
    generateRectangleList(&HEAD);

    Node *currentNode = HEAD;
    while (currentNode)
    {
        printf("%lf %lf %lf %lf\n", currentNode->rectangle.a.x, currentNode->rectangle.a.y, currentNode->rectangle.b.x, currentNode->rectangle.b.y);
        printf("Area: %lf\n", calculateNodeArea(currentNode));
        currentNode = currentNode->next;
    }

    printf("Total areas: %lf\n", areaRects(HEAD));
    printf("----------------------------------------------\n");
    filterRects(&HEAD, 10, 100);

    currentNode = HEAD;
    while (currentNode)
    {
        printf("%lf %lf %lf %lf\n", currentNode->rectangle.a.x, currentNode->rectangle.a.y, currentNode->rectangle.b.x, currentNode->rectangle.b.y);
        printf("Area: %lf\n", calculateNodeArea(currentNode));
        currentNode = currentNode->next;
    }

    printf("Total areas: %lf\n", areaRects(HEAD));

    currentNode = HEAD;
    while (currentNode)
    {
        Node *tmp;
        tmp = currentNode->next;
        free(currentNode);
        currentNode = tmp;
    }

    return 0;
}

void generateRectangle(Rectangle *rectangle)
{
    rectangle->a.x = ((rand() % 2000 + 1) - 1000) / 100.0;
    rectangle->a.y = ((rand() % 2000 + 1) - 1000) / 100.0;
    rectangle->b.x = ((rand() % 2000 + 1) - 1000) / 100.0;
    rectangle->b.y = ((rand() % 2000 + 1) - 1000) / 100.0;
}

void generateRectangleList(Node **HEAD)
{
    srand(time(NULL));
    int i = 0;
    if (!*HEAD)
    {
        *HEAD = malloc(sizeof(Node));
        (*HEAD)->next = NULL;
        generateRectangle(&((*HEAD)->rectangle));
        i++;
    }
    while (i < COUNT)
    {
        Node *currentNode = *HEAD;
        while (currentNode->next)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = malloc(sizeof(Node));
        currentNode->next->next = NULL;
        generateRectangle(&currentNode->next->rectangle);
        i++;
    }
}

double calculateNodeArea(Node *node)
{
    return fabs(node->rectangle.a.x - node->rectangle.b.x) * fabs(node->rectangle.a.y - node->rectangle.b.y);
}

double areaRects(Node *list)
{
    size_t i = 0;
    Node *currentNode = list;
    double areas;

    while (currentNode)
    {
        areas += calculateNodeArea(currentNode);
        currentNode = currentNode->next;
    }
}

void filterRects(Node **list, double min, double max)
{
    int i = COUNT;
    Node *currentNode = *list;
    Node *previousNode = *list;

    while (currentNode)
    {
        double area = calculateNodeArea(currentNode);
        if (min < area - 0.001 && area < max + 0.001)
        {
            if (currentNode == *list && i == 1)
            {
                *list = NULL;
                free(currentNode);
                return;
            }
            else if (currentNode == *list)
            {
                *list = currentNode->next;
                previousNode = *list;
                free(currentNode);
                currentNode = previousNode;
                i--;
            }
            else
            {
                Node *tmp;
                previousNode->next = currentNode->next;
                tmp = currentNode->next;
                free(currentNode);
                currentNode = tmp;
                i--;
            }
        }
        else
        {
            if (previousNode == *list && currentNode == *list)
            {
                currentNode = currentNode->next;
            }
            else
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
        }
    }
}