/**
 * @file main.c
 * @author Guillaume LEMONNIER
 * @date 2021-06-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>

void printshort(short arg)
{
    for( ; ; )
    {

    }
}
void printint(int arg)
{
    for( ; ; )
    {

    }
}
void printfloat(float arg)
{
    for( ; ; )
    {

    }
}
void printlong(long arg)
{
    for( ; ; )
    {

    }
}
void printlonglong(long long arg)
{
    for( ; ; )
    {

    }
}

void (*ptr[5])() =
{
    printshort,
    printint,
    printfloat,
    printlong,
    printlonglong
};
const char *list[] = 
{
    "s",
    "d",
    "f",
    "ld",
    "lld"
};

void print(const char *print, ...)
{
    printf("%ld\n", sizeof(list));
    for(int x = 0; x < sizeof(print) / 4; x ++)
    {
        if(print[x] == "%")
        {
            char indicator = "";
            while(print[x] != " ")
            {
                x ++;
                indicator += print[x];
            }
            for(int i = 0; i < sizeof(list) / 8; i ++)
            {
                if(indicator == list[i])
                {
                    ptr[i]();
                }
            }
        }
    }
}

int main(void)
{
    print("oui oui oui %d", 4);
    return 0;
}