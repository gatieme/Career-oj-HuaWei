#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define DEBUG


#ifdef DEBUG

#define debug       cout
#define dprintf     printf

#else

#define debug       0 && cout
#define dprintf     0 && printf

#endif // DEBUG



#define SIZE 1025
int cmp(const void *left, const void * right);


/*
0       -=>     48
9       -=>     57

A       -=>     65
Z       -=>     90

a       -=>     97
z       -=>     122

 */

int main( )
{
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
        char str[SIZE];
        printf("%d %d\n", '0', '9');
        printf("%d %d\n", 'A', 'Z');
        printf("%d %d\n", 'a', 'z');

        while(gets(str) != NULL)
        {
                qsort(str, strlen(str), sizeof(str[0]), cmp);

                puts(str);
        }

    return 0;
}



int cmp(const void *left, const void * right)
{
        const char *_left = (const char *)left;
        const char *_right = (const char *)right;
        return ((int)*_left - (int)*_right);
}
