#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define COUNT 10

typedef struct Point
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
    Rectangle *rectangle;
    struct Node *next;
} Node;

Rectangle *generateRectangle();
void addToRectangleList(Node **);
double areaRects(Node *);
void filterRects(Node **list, double min, double max);
double calculateArea(Node *);

int main()
{
    Node *HEAD = NULL;
    for (int i = 0; i < COUNT; i++)
    {
        addToRectangleList(&HEAD);
    }

    filterRects(&HEAD, 10, 80);

    Node *node = HEAD;
    while (node)
    {
        printf("Area = %lf\n", calculateArea(node));
        node = node->next;
    }

    node = HEAD;
    while (node)
    {
        Node *tmp = node;
        node = node->next;
        free(tmp);
    }

    return 0;
}

Rectangle *generateRectangle()
{
    srand(time(NULL));
    Rectangle *newRectangle = malloc(sizeof(Rectangle));
    newRectangle->a.x = (rand() % 20 + 1) - 10;
    newRectangle->a.y = (rand() % 20 + 1) - 10;
    newRectangle->b.x = (rand() % 20 + 1) - 10;
    newRectangle->b.y = (rand() % 20 + 1) - 10;
    return newRectangle;
}

void addToRectangleList(Node **HEAD)
{

    if (*HEAD)
    {
        Node *nextNode = (*HEAD)->next;
        while (nextNode)
        {
            nextNode = nextNode->next;
        }

        nextNode->next = malloc(sizeof(Node));
        nextNode->next->next = NULL;
        nextNode->next->rectangle = generateRectangle();
    }
    else
    {
        *HEAD = (Node *)malloc(sizeof(Node));
        (*HEAD)->next = NULL;
        (*HEAD)->rectangle = generateRectangle();
    }
}

double calculateArea(Node *node)
{
    double side1 = fabs(node->rectangle->a.x - node->rectangle->b.x);
    double side2 = fabs(node->rectangle->a.y - node->rectangle->b.y);
    return side1 * side2;
}

double areaRects(Node *list)
{
    double area = 0;
    while (list)
    {
        area += calculateArea(list);
        list = list->next;
    }

    return area;
}

void filterRects(Node **list, double min, double max)
{
    Node *HEAD = list[0];
    size_t i = 0;
    while (list[i])
    {
        double area = calculateArea(list[i]);
        if (area < min || area > max)
        {
            if (i = 0)
            {
                HEAD = list[1];
                free(list[0]);
            }
            else
            {
                Node *prev = list[i - 1];
                prev->next = list[i]->next;
                free(list[i]);
            }
        }
        else
        {

            list[i] = list[i]->next;
        }
    }
}