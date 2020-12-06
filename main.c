#include <stdio.h>
#include "myBank.h"
int main () {
    char operation;
    do {
        printf("please select the action you want to perform:\nO-Open new account\n""B-get the balance of your account\nD-Deposit to your account\nW-Withdrawal from your account\nC-Close your account\nI-set an Interestfor the bank\nP-Print all the bank accounts \nE-Exit \n");
        scanf("%c", &operation);

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
                  break;

              default:
                  printf("invalid operation type\n");
                  break;
          }
          printf("\n");
    }
    while (operation!='E');
}
