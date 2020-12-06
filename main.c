#include <stdio.h>
#include "myBank.h"


int main(){
    char operation = ' ';
    int exit = 0;

    while (!exit) {
      printf("\nplease select the action you want to perform:\n");
      printf("O-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
      if(scanf(" %c", &operation)==1) {
        switch (operation) {
            case 'O':
                openAccount();
                break;

            case 'B':
                getBalance();
                break;

            case 'D':
                deposit();
                break;

            case 'W':
                withdrawal();
                break;

            case 'C':
                closeAccount();
                break;

            case 'I':
                setInterest();
                break;

            case 'P':
                printAll();
                break;

            case 'E':
                programExit();
                printf("All account are closed, good bye\n");
                exit=1;
                break;

            default: printf("invalid operation type\n");

          }
        }

    }
    return 0;
}
