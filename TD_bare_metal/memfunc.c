#include <stddef.h>
#include <stdint.h>

void *memset(void *s, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

void *memset /*__attribute__((__section__(".memfunc_section")))*/ (void *s, int c, size_t n) {
    uint8_t* i = s;
    while ((int)i < n) {
        *i = c;
        i++;
    } return s;
}

void *memcpy /*__attribute__((__section__(".memfunc_section")))*/ (void *dest, const void *src, size_t n) {
    if (dest + n >= src) {
        return 0;
    }
    uint8_t i = 0;
    while (i < n * sizeof(uint8_t)) {
        *((uint8_t*)dest + i) = *((uint8_t*)src + i);
        i += sizeof(uint8_t);
    } return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
    if (dest < src) {
        int diff = src - dest;
        for (uint8_t i = 0; i < diff || i < n; i++) {
            *((uint8_t*)dest + i)= *((uint8_t*)src + i);
        }
    }
    else {
        int diff = dest - src;
        int min;
        if (diff > n) {
            int min = n;
        }
        else {
            int min = diff;
        }
        for (uint8_t i = min; i > 0; i--) {
            *((uint8_t*)dest + i)= *((uint8_t*)src + i);
        }
    }
}

int memcmp(const void *s1, const void *s2, size_t n) {
    for (uint8_t i = 0; i < n; i++) {
        uint8_t diff = *((uint8_t*)s2 + i) - *((uint8_t*)s1 + i);
        if (diff != 0) {
            return diff;
        }
    } return 0;
}