#include <stdio.h>
#include <string.h>
#include <regex.h>

struct contact
{
    char email[30];
    char home_num[10];
    char mobile_num[10];
} std;

// check if the email is valid or not.

int valid(int value)
{
    // The email is valid.
    if (value == 0)
    {
        return 0;
    }
    // The email in not valid.
    else
    {
        printf("Plrease enter a valid email\nIt must ends with '@alexu.edu.eg'\n");
        return 1;
    }
}

int main()

{
    ////// get user email//////
    // regex is the memory location where the pattern to be matched is stored.
    regex_t regex;

    char *temp;
    int value;

    do
    {
        printf("Student e-mail: \n");
        scanf("%s", std.email);
        temp = std.email;

        // regcomp() is used to compile a regular expression
        // It returns a 0 upon successful compilation,​ and an error code otherwise.
        value = regcomp(&regex, "alexu.edu.eg", 0);

        // regexec() function is used to match a string against a pattern.
        // It returns a 0 if there is a match, and a REG_NOMATCH error otherwise.
        value = regexec(&regex, temp, 0, NULL, 0);

    } while (valid(value));

    ///// get home and mobile number /////

    printf("Student home number:\n");
    scanf("%s", std.home_num);
    printf("Studet mobile number:\n");
    scanf("%s", std.mobile_num);

    return 0;
}
