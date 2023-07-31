#include <stdio.h>

/*ДА СЕ НАПИШЕ ПРОГРАМА, КОЯТО ПРИЕМА ДВА ПАРАМЕТЪРА :
 - ВЪЗРАСТ (ЦЯЛО)
 - ТЕГЛО (С ПЛАВАЩА)

1. ДА СЕ ПРОВЕРИ ВЪЗРАСТТА НА ЛИЦЕТО И АКО ТЯ Е ПО 18 ГОДИНИ ДА ОТГОВАРЯ
"ЧЕ Е НЕПЪЛНОЛЕТЕН И НЕ МОЖЕ ДА ДАВА КРЪВ ИЛИ ДА ГЛАСУВА

2. АКО Е НАД 18 ГОД И ПОД 100 КГ - МОЖЕ ДА ДАВА КРЪВ

3. АКО Е НАД 18 ГОД БЕЗ ЗНАЧЕНИЕ ОТ КИЛОГРАМИТЕ - МОЖЕ ДА ГЛАСУВА
*/

void checkAgeAndWeight(int age, float weight);

int main(void)
{
    int age;
    printf("Enter age: \n");
    scanf("%i", &age);

    float weight;
    printf("Enter weight: \n");
    scanf("%f", &weight);

    checkAgeAndWeight(age, weight);
    return 0;
}

void checkAgeAndWeight(int age, float weight)
{
    if (age < 18)
        printf("ЛИЦЕТО Е НЕПЪЛНОЛЕТЕН И НЕ МОЖЕ ДА ДАВА КРЪВ ИЛИ ДА ГЛАСУВА\n");
    else
    {
        if (weight < 100)
            printf("ЛИЦЕТО МОЖЕ ДА ДАВА КРЪВ\n");
        else
            printf("ЛИЦЕТО МОЖЕ ДА ГЛАСУВА\n");
    }
}
