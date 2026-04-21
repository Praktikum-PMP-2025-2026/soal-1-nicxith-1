/* EL2008 Praktikum Pemecahan Masalah dengan Pemrograman    
 * Modul        : Data Manipulation and External Files
 * Pembuat      : Saragih, Jan Roman Arthuro
 * NIM          : 13224012
 * Deskripsi    : Menghapus tanda kurung yang tidak memiliki pasangan pada sebuah string.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[1001];
    fgets(input, sizeof(input), stdin);
    
    int len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = '\0';
        len--;
    }
    
    // Array karakter dihapus 
    int hapus[1001] = {0};
    
     // Stack save '('
    int stack[1001];
    int top = -1;

    // Cari ')' yang tidak ada pasangan '('
    for (int i = 0; i < len; i++) {
        if (input[i] == '(') {
            // Save '(' (indexnya)  ke stack 
            top++;
            stack[top] = i;
        } else if (input[i] == ')') {
            if (top >= 0) {
                // Ada pasangan '(' pop dri stack
                top--;
            } else {
                // Tidak ada pasangan ')' ditanda 
                hapus[i] = 1;
            }
        }
    }

    // Sisa '(' dihapus
    while (top >= 0) {
        hapus[stack[top]] = 1;
        top--;
    }
    
    // Mengumpulkan hasil ke new string
    char hasil[1001];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!hapus[i]) {
            hasil[j++] = input[i];
        }
    }
    hasil[j] = '\0';
    
    // cetak dgn newline kalo ada isi
    if (j > 0) {
        printf("%s\n", hasil);
    }
    
    printf("\n");
    
    return 0;
}