#include <stdio.h>
#include <stdint.h>

unsigned onesCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);
unsigned int checkBit(uint64_t mask, int64_t i);
void setBit(uint64_t *mask, int64_t i);
void clearBit(uint64_t *mask, int64_t i);
void flipOddBits(uint64_t *mask);
void printBits(uint64_t *mask);
void printBits16(uint16_t *mask);
void mirrorBits(uint16_t *mask);

int main(void)
{
    // 12569075127188697163
    uint64_t mask1 = 0b1010111001101110010100110011101111111111010001111011000001001011;
    // 984375675
    uint32_t mask2 = 0b00111010101011000110000101111011;
    // 16627
    uint16_t mask3 = 0b0100000011110011;
    // 232
    uint8_t mask4 = 0b11101000;

    uint64_t sum = onesCount(mask1, mask2, mask3, mask4);
    printf("The sum of %lu %u %d %d is: %ld \n", mask1, mask2, mask3, mask4, sum);

    uint64_t m = 0b0000000000000000000000000000000000000000000000000000000000000000;
    flipOddBits(&m);
    printBits(&m);

    uint16_t a = 0b1111111100000000;
    mirrorBits(&a);
    printBits16(&a);
    return 0;
}

unsigned onesCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4)
{
    int sum = 0;
    int result, i;
    for (i = 0; i < 64; i++)
    {
        result = checkBit(mask1, i);
        if (result == 1)
            sum += result;
    }
    for (i = 0; i < 32; i++)
    {
        result = checkBit(mask2, i);
        if (result == 1)
            sum += result;
    }
    for (i = 0; i < 16; i++)
    {
        result = checkBit(mask3, i);
        if (result == 1)
            sum += result;
    }
    for (i = 0; i < 8; i++)
    {
        result = checkBit(mask4, i);
        if (result == 1)
            sum += result;
    }
    return sum;
}

unsigned int checkBit(uint64_t mask, int64_t i)
{
    return (mask & (1ULL << i)) ? 1 : 0;
}

void setBit(uint64_t *mask, int64_t i)
{
    *mask |= (1ULL << i);
}

void clearBit(uint64_t *mask, int64_t i)
{
    *mask &= ~(1ULL << i);
}

void flipOddBits(uint64_t *mask)
{
    for (int i = 1; i < 64; i += 2)
    {
        if (checkBit(*mask, i) == 0)
        {
            // returns 0 -> set the bit
            setBit(mask, i);
        }
        else
        {
            // returns 1 -> clear the bit
            clearBit(mask, i);
        }
    }
}

void printBits(uint64_t *mask)
{
    printf("The bits in new uint64_t m after odd invertion are: ");
    for (uint64_t i = 0; i < 64; i++)
        printf("%d", checkBit(*mask, i));
    printf("\n");
}

void printBits16(uint16_t *mask)
{
    printf("The bits in new uint16_t m after invertion are: ");
    for (uint64_t i = 0; i < 16; i++)
        printf("%d", checkBit(*mask, i));
    printf("\n");
}

void mirrorBits(uint16_t *mask)
{
    *mask = ~(*mask);
}
