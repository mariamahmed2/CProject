#include <stdio.h>
#include <time.h>

struct student
{

    struct birth_date
    {
        int d;
        int m;
        int y;
    } birth;
} std1;

/* function to calculate age */

void age(int birth_day, int birth_month, int birth_year, int sys_day, int sys_month, int sys_year)
{
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (birth_day > sys_day)
    {
        sys_day = sys_day + month[birth_month - 1];
        sys_month = sys_month - 1;
    }
    if (birth_month > sys_month)
    {
        sys_year = sys_year - 1;
        sys_month = sys_month + 12;
    }
    int final_date = sys_day - birth_day;
    int final_month = sys_month - birth_month;
    int final_year = sys_year - birth_year;
    printf("Your present age %d Years\n", final_year);
}

int main()
{
    /* get date of birth of the user*/

    printf("Enter your date of birth: \n");
    scanf("%d\n%d\n%d", &std1.birth.d, &std1.birth.m, &std1.birth.y);
    printf("Your date of birth\n %d/%d/%d \n", std1.birth.d, std1.birth.m, std1.birth.y);

    /* get date of the system*/

    time_t d = time(NULL);
    struct tm sys_date = *localtime(&d);
    printf("Current Date: %d/%d/%d\n", sys_date.tm_mday, sys_date.tm_mon + 1, sys_date.tm_year + 1900);

    // print user age

    age(sys_date.tm_mday, sys_date.tm_mon + 1, sys_date.tm_year + 1900, std1.birth.d, std1.birth.m, std1.birth.y);
    return 0;
}