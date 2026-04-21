/* EL2008 Praktikum Pemecahan Masalah dengan Pemrograman    
 * Modul        : Data Manipulation and External Files
 * Pembuat      : Saragih, Jan Roman Arthuro
 * NIM          : 13224012
 * Deskripsi    : Menghapus tanda kurung yang tidak memiliki pasangan pada sebuah string.
 */

#include <stdio.h>
#include <string.h>

int main() {
    char input[1001];
    
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 0;
    }
    
    // Hapus newline
    int len = strlen(input);
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
        len--;
    }
    
    if (len == 0) {
        return 0;
    }
    
    int hapus[1001] = {0};
    int stack[1001];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        if (input[i] == '(') {
            top++;
            stack[top] = i;
        } else if (input[i] == ')') {
            if (top >= 0) {
                top--;
            } else {
                hapus[i] = 1;
            }
        }
    }
    
    while (top >= 0) {
        hapus[stack[top]] = 1;
        top--;
    }
    
    char hasil[1001];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!hapus[i]) {
            hasil[j++] = input[i];
        }
    }
    hasil[j] = '\0';
    
    if (j > 0) {
        printf("%s\n", hasil);
    }
    
    return 0;
}