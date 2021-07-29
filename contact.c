#include <stdio.h>
#include <string.h>
#include <regex.h>

struct contact
{
    char email[30];
    char home_num[10];
    char mobile_num[10];
} std;

// check if the email is valid or not

int print_result(int value)
{

    if (value == 0)
    {
        return 0;
    }
    else if (value == REG_NOMATCH)
    {
        return 1;
    }
    else
    {
        return 1;
    }
}

int email_validation(char *email)
{
    int res;
    const char extention[] = "@alexu.edu.eg";

    char *valid;
    valid = strstr(std.email, extention);
    res = strcmp(valid, extention);

    // res = 1 => Not valid
    // res = 0 => Valid

    if (res == 0)
    {
        printf("Please enter a valid email.\n");
        scanf("%s", std.email);
        email_validation(std.email);
    }
    else
    {
        printf("Email is added.\n");

        return 0;
    }
}

int main()

{
    // get user email
    regex_t regex;
    char *temp;
    int value;

    do
    {
        printf("Plase enter a valid email\nStudent e-mail: \n");
        scanf("%s", std.email);
        temp = std.email;
        value = regcomp(&regex, "@alexu.edu.eg", 0);
        value = regexec(&regex, temp, 0, NULL, 0);

    } while (print_result(value));

    // home and mobile number

    printf("Student home number:\n");
    scanf("%s", std.home_num);
    printf("Studet mobile number:\n");
    scanf("%s", std.mobile_num);

    return 0;
}
