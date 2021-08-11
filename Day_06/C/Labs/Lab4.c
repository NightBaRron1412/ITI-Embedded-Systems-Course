//Headers including
#include <stdio.h>
#include "Std_Types.h"

/*Defining a new structure type before optimization
typedef struct
{
    u16 x;
    u32 y;
    u16 z;
    u32 k;
} mystruct;*/

//Defining a new structure type before optimization
typedef struct
{
    u32 x;
    u32 y;
    u16 z;
    u16 k;
} mystruct;

void main(){
    printf("The size of the structure is: %d Bytes", sizeof(mystruct));
}