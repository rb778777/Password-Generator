#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char generateRandomChar() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-=_+";
    int index = rand() % (sizeof(charset) - 1);
    return charset[index];
}


void generatePassword(int length, int useUppercase, int useNumbers, int useSymbols) {
    srand(time(NULL));
    int i;
    char password[length];

    for (i = 0; i < length; i++) {
        if (i == 0 && useUppercase) {
            
            password[i] = 'A' + rand() % 26;
        } else if (i == 1 && useNumbers) {
            
            password[i] = '0' + rand() % 10;
        } else if (i == 2 && useSymbols) {
            
            password[i] = generateRandomChar();
        } else {
            password[i] = generateRandomChar();
        }
    }

    
    for (i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    
    printf("Generated Password: %s\n", password);
}

int main() {
    int length, useUppercase, useNumbers, useSymbols;

    
    printf("Enter password length: ");
    scanf("%d", &length);

    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &useUppercase);

    printf("Include numbers? (1 for yes, 0 for no): ");
    scanf("%d", &useNumbers);

    printf("Include symbols? (1 for yes, 0 for no): ");
    scanf("%d", &useSymbols);

    generatePassword(length, useUppercase, useNumbers, useSymbols);

    return 0;
}
