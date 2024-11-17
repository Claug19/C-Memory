#ifndef C_MEMORY_BASEENCODING_H
#define C_MEMORY_BASEENCODING_H
#include<stdio.h>

static char base16[16];
static char base32[32];
static int currentBase = 0;
static int base32Encoding = 0;

void populateBase16Encoding()
{
    int index = 0;
    for(char digit='0'; digit <='9'; digit++)
        base16[index++] = digit;
    for(char letter='A'; letter <='F'; letter++)
        base16[index++] = letter;
}

void populateBase32()
{
    int index = 0;
    for(char letter='A'; letter <='Z'; letter++)
        base32[index++] = letter;
    for(char digit='2'; digit <='7'; digit++)
        base32[index++] = digit;
}

void populateBase32ExtendedHex()
{
    int index = 0;
    for(char digit='0'; digit <='9'; digit++)
        base32[index++] = digit;
    for(char letter='A'; letter <='V'; letter++)
        base32[index++] = letter;
}

void printEncodingList(char* List)
{
    printf("Alphabet of base %d: ", currentBase);
    for (int i=0; i<=currentBase; i++)
        printf("%c", List[i]);
    printf("\n");
}

void printEncoding(const int base)
{
    switch(base) {
        case 16:
            currentBase=16;
            printEncodingList(base16);
            return;
        case 32:
            currentBase=32;
            printEncodingList(base32);
            return;
        default:
            return;
    }
}

void initializeBases()
{   populateBase16Encoding();


    printf("Select base 32 encoding:\n RFC4648 - 0\n RFC4648 extended hex - 1\n");
    scanf("%d", &base32Encoding);
    if(base32Encoding==0)
        populateBase32();
    else
        populateBase32ExtendedHex();
    printEncoding(16);
    printEncoding(32);
}

#endif //C_MEMORY_BASEENCODING_H

