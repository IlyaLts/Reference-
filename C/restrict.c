#include <stdio.h>
 
 /*
 When we use restrict with a pointer ptr, it tells the compiler that ptr is the only way to access the object pointed by it,
 in other words, there’s no other pointer pointing to the same object i.e. restrict keyword specifies that
 a particular pointer argument does not alias any other and the compiler doesn’t need to add any additional checks.
 */
 
// Note that the purpose of restrict is to
// show only syntax. It doesn't change anything
// in output (or logic). It is just a way for
// programmer to tell compiler about an
// optimization
void use(int* a, int* b, int* restrict c)
{
    *a += *c;
 
    // Since c is restrict, compiler will
    // not reload value at address c in
    // its assembly code. Therefore generated
    // assembly code is optimized
    *b += *c; 
}
 
int main(void)
{
    int a = 50, b = 60, c = 70;
    use(&a, &b, &c);
    printf("%d %d %d", a, b, c);
    return 0;
}