#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *codeStr(size_t n, char *s);

int main(void)
{
    char s[500];
    printf("Enter a number: ");
    scanf("%s", s);
    size_t n = strlen(s);
    char *str = codeStr(n, s);
    printf("%s\n", str);
    free(str);
    return 0;
}

char *codeStr(size_t n, char *s)
{
    char *str = malloc((n + 1) * sizeof(*str));
    for (size_t i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            // even pos
            str[i] = s[i] + ('A' - '0');
        }
        else
        {
            // odd pos
            switch (s[i])
            {
            case '0':
                str[i] = '!';
                break;
            case '1':
                str[i] = '#';
                break;
            case '2':
                str[i] = '/';
                break;
            case '3':
                str[i] = '~';
                break;
            case '4':
                str[i] = '=';
                break;
            case '5':
                str[i] = '\'';
                break;
            case '6':
                str[i] = '\\';
                break;
            case '7':
                str[i] = '>';
                break;
            case '8':
                str[i] = '.';
                break;
            case '9':
                str[i] = ',';
                break;

            default:
                str[i] = ' ';
                break;
            }
        }
    }
    str[n] = '\0';
    return str;
}
