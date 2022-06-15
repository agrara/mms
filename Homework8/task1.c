#include <stdio.h>

unsigned int myStrlen(const char *);
unsigned int myNStrlen(const char *, size_t);

char *myStrcpy(char *, const char *);
char *myStrncpy(char *, const char *, size_t);

char *myStrcat(char *, const char *);
char *myStrncat(char *, const char *, size_t);

int myStrcmp(const char *, const char *);
int myStrncmp(const char *, const char *, size_t);

char *myStrstr(const char *, const char *);

int main()
{
    char str[] = {'a', 'b', 'c', 0};
    printf("%d\n", myNStrlen(str, 2));

    char newStr[20];
    myStrcpy(newStr, str);
    printf("%s\n", newStr);

    return 0;
}

unsigned int myStrlen(const char *str)
{
    int i = 0;
    while (str[i] != 0)
    {
        i++;
    }

    return i;
}

unsigned int myNStrlen(const char *str, size_t n)
{
    int i = 0;
    while (str[i] != 0 && i < n)
    {
        i++;
    }

    return i;
}

char *myStrcpy(char *dest, const char *src)
{
    size_t i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    i++;
    dest[i] = 0;
    return dest;
}

char *myStrncpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;
    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    i++;
    dest[i] = 0;
    return dest;
}

char *myStrcat(char *dest, const char *src)
{
    size_t i = 0;
    size_t iSrc = 0;
    while (dest[i])
    {
        i++;
    }

    while (src[iSrc])
    {
        dest[i + iSrc] = src[iSrc];
        iSrc++;
    }
    iSrc++;
    dest[i + iSrc] = 0;
    return dest;
}

char *myStrncat(char *dest, const char *src, size_t n)
{
    size_t i = 0;
    size_t iSrc = 0;
    while (dest[i])
    {
        i++;
    }

    while (src[iSrc] && iSrc < n)
    {
        dest[i + iSrc] = src[iSrc];
        iSrc++;
    }
    iSrc++;
    dest[i + iSrc] = 0;
    return dest;
}

int myStrcmp(const char *str1, const char *str2)
{
    size_t i = 0;
    while (str1[i] == str2[i])
    {
        if (!str1[i])
        {
            return 0;
        }
        i++;
    }
    if (str1[i] > str2[i])
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int myStrcmp(const char *str1, const char *str2, size_t n)
{
    size_t i = 0;
    while (str1[i] == str2[i])
    {
        if (i == n)
        {
            return 0;
        }
        if (!str1[i])
        {
            return 0;
        }
        i++;
    }

    if (str1[i] > str2[i])
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

char *myStrstr(const char *haystack, const char *needle)
{
    size_t i = 0;
    char *found = NULL;

    while (haystack[i])
    {
        if (haystack[i] == needle[0])
        {
            size_t j = 0;
            while (1)
            {
                if (needle[j] == haystack[i + j])
                {
                    j++;
                }
                else if (!needle[j])
                {
                    return haystack + i + j;
                }
                break;
            }
        }
        i++;
    }
    return NULL;
}