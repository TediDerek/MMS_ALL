#include <stdio.h>
#include <stdint.h>

/*Да се напише програма на С, която реализира
следните функции за работа с побитви операции:
1. SetBit() - 'ПОВДИГА' /сетва в стойност 1 - true/ конкретен бит в дадено 16-битово цяло число без знак;
2. CheckBit() - ПРОВЕРЯВА конкретен бит в дадено 16-битово цяло число без знак;
3. ClearBit() - ИЗТРИВА конкретен бит в дадено 16-битово цяло число без знак;
4. PrintBits() - РАЗПЕЧАТВА битовете на това число;*/

uint16_t setBit(uint16_t byte, int bitIdx);
uint16_t clearBit(uint16_t byte, int bitIdx);
uint16_t checkBit(uint16_t byte, int bitIdx);
void printBits(uint16_t mask);

int main(void)
{
    printBits(123);
    return 0;
}

uint16_t setBit(uint16_t byte, int bitIdx)
{
    // bitIdx = 5;
    // 0101_1011 | 0010_0000 = 0111_1011;
    return byte | (1 << bitIdx);
}

uint16_t clearBit(uint16_t byte, int bitIdx)
{
    // bitIdx = 5; -> 1 << 5 -> 0010_0000
    // ~(1 << 5) -> ~0010_0000 -> 1101_1111
    // 0111_1011 & ~(1 << 5) = 0111_1011 & 1101_1111 = 0101_1011;
    return byte & ~(1 << bitIdx);
}

uint16_t checkBit(uint16_t byte, int bitIdx)
{
    // bitIdx = 5; -> 1 << 5 -> 0010_0000
    // (1 << 5) -> 0010_0000
    // 0111_1011 & (1 << 5) -> 0111_1011 & 0010_0000 -> returns 1 (true)
    // -----------------or another example-------------------
    // 0101_1011 & (1 << 5) -> 0101_1011 & 0010_0000 -> returns 0 (false)
    return byte & (1 << bitIdx) ? 1 : 0;
}

void printBits(uint16_t mask)
{
    for (int i = sizeof(uint16_t) * 8 - 1; i >= 0; i--)
        printf("%i", checkBit(mask, i));
    printf("\n");
}
