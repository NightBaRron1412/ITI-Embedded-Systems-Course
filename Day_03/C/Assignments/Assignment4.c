//Libraries including
#include <stdio.h>

void main()
{
    //Variables decleration
    int c1[] = {53, 42, 93, 21, 47, 34, 93, 23, 50, 98};
    int c2[] = {30, 69, 100, 46, 98, 94, 62, 29, 63, 55};
    int c3[] = {22, 59, 18, 91, 1, 86, 57, 32, 51, 89};
    int pass_count, fail_count, highest = 0, lowest = 100, sum, avg;

    //Using linear search algorithm for first class
    for (int i = 0; i < 10; i++)
    {
        // Finding number of passed students
        if (c1[i] >= 50)
        {
            pass_count++;
        }

        // Finding number of failed students
        else
        {
            fail_count++;
        }

        // Finding highest grade
        if (c1[i] > highest)
        {
            highest = c1[i];
        }

        // Finding lowest grade
        if (c1[i] < lowest)
        {
            lowest = c1[i];
        }

        //calculating sum to get average
        sum += c1[i];
    }

    //Using linear search algorithm for second class
    for (int i = 0; i < 10; i++)
    {
        // Finding number of passed students
        if (c2[i] >= 50)
        {
            pass_count++;
        }

        // Finding number of failed students
        else
        {
            fail_count++;
        }

        // Finding highest grade
        if (c2[i] > highest)
        {
            highest = c2[i];
        }

        // Finding lowest grade
        if (c2[i] < lowest)
        {
            lowest = c2[i];
        }

        //calculating sum to get average
        sum += c2[i];
    }

    //Using linear search algorithm for third class
    for (int i = 0; i < 10; i++)
    {
        // Finding number of passed students
        if (c3[i] >= 50)
        {
            pass_count++;
        }

        // Finding number of failed students
        else
        {
            fail_count++;
        }

        // Finding highest grade
        if (c3[i] > highest)
        {
            highest = c3[i];
        }

        // Finding lowest grade
        if (c3[i] < lowest)
        {
            lowest = c3[i];
        }

        //calculating sum to get average
        sum += c3[i];
    }

    //calculating average
    avg = sum / 30;

    //Printing result
    printf("Number of passed students = %d\n", pass_count);
    printf("Number of failed students = %d\n", fail_count);
    printf("Highest grade = %d\n", highest);
    printf("Lowest grade = %d\n", lowest);
    printf("Average = %d\n", avg);
}
