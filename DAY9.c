#include <stdio.h>

int main() {
    char s[1000];
    int i = 0, j;
    char temp;

    // Read the string
    scanf("%s", s);

    // Find length manually
    while (s[i] != '\0') {
        i++;
    }

    j = i - 1;   // last index
    i = 0;       // first index

    // Reverse using two pointers
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    // Print reversed string
    printf("%s", s);

    return 0;
}
