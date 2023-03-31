#include <cstdio>
 
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
        (byte & 0x80 ? '1' : '0'), \
        (byte & 0x40 ? '1' : '0'), \
        (byte & 0x20 ? '1' : '0'), \
        (byte & 0x10 ? '1' : '0'), \
        (byte & 0x08 ? '1' : '0'), \
        (byte & 0x04 ? '1' : '0'), \
        (byte & 0x02 ? '1' : '0'), \
        (byte & 0x01 ? '1' : '0') 
 
#define WBYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
#define WBYTE_TO_BINARY(byte)  \
        (byte & 0x8000 ? '1' : '0'), \
        (byte & 0x4000 ? '1' : '0'), \
        (byte & 0x2000 ? '1' : '0'), \
        (byte & 0x1000 ? '1' : '0'), \
        (byte & 0x800 ? '1' : '0'), \
        (byte & 0x400 ? '1' : '0'), \
        (byte & 0x200 ? '1' : '0'), \
        (byte & 0x100 ? '1' : '0'), \
        (byte & 0x80 ? '1' : '0'), \
        (byte & 0x40 ? '1' : '0'), \
        (byte & 0x20 ? '1' : '0'), \
        (byte & 0x10 ? '1' : '0'), \
        (byte & 0x08 ? '1' : '0'), \
        (byte & 0x04 ? '1' : '0'), \
        (byte & 0x02 ? '1' : '0'), \
        (byte & 0x01 ? '1' : '0') 
 
int main()
{
    char c = 'X';
    wchar_t wc = L'X';
    
    printf(BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(c));
    printf(WBYTE_TO_BINARY_PATTERN"\n", WBYTE_TO_BINARY(wc));
    
    return 0;
}
 