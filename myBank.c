#include <stdio.h>
#include "myBank.h"
#define min 901
#define max 950
int i=-1;
double myBank[50][2] = {0};
int account_number;
double amount,interest_rate;
void openAccount() {
    if (i>50) {
      printf("sorry, the bank is full, can't open anymore accounts.\n");
    }

    else {

      printf("Please insert amount for deposit: ");
      scanf("%lf", &amount);
      if (amount<0) {
        printf("sorry, can't deposite a negative amount, please try again\n");
        return;
      }
      else{
        if (i<50) {
          i++;
        }
        myBank[i][0]=amount;
        myBank[i][1]=1;
        printf("Account number %d has been successfully opened \n", min+i);
      }
    }
}

void getBalance() {
    printf("Please insert account number: ");
    scanf("%d", &account_number);
    if (myBank[account_number-min][1]==1) {
      printf("your balance is %.2f ", myBank[account_number-min][0]);
    }

    else {
      printf("invalid account number, please try again.\n");
      return;
    }
}

void deposit() {
    printf("Please insert account number: ");
    scanf("%d", &account_number);
    if (myBank[account_number-min][1]==1) {
      printf("Please insert amount for deposit: ");
      scanf("%lf", &amount);
      myBank[account_number-min][0] += amount;
      printf("your new balance is %.2f\n", myBank[account_number-min][0]);
    }
}

void withdrawal() {
    printf("Please insert account number: ");
    scanf("%d", &account_number);
    if (myBank[account_number-min][1]==1) {
      printf("Please insert amount for deposit: ");
      scanf("%lf", &amount);
      if (myBank[account_number-min][0]>amount) {
        myBank[account_number-min][0] -= amount;
        printf("your new balance is %.2f\n", myBank[account_number-min][0]);
      }

      else {
        printf("you don't have enough money, please insert a lower amount\n");
      }
    }

    else {
      printf("your account is closed\n");
    }
}

void closeAccount() {
    printf("Please insert account number: ");
    scanf("%d", &account_number);
    if (myBank[account_number-min][1]==1) {
      myBank[account_number-min][1]=0;
      printf("your account has been successfully closed \n");
    }
    else {
      printf("this account is already closed\n");
    }
}

void setInterest() {
    printf("Please insert interest value: \n");
    scanf("%.2f", &interest_rate);
    double ir= 1 + (interest_rate/100);
    for (int i = 0; i < 50; i++) {
      if (myBank[i][1]==1) {
        double amount = myBank[i][0];
        myBank[i][0] = amount*ir;
      }
    }
}

void printAll() {
    for (int i = 0; i < 50; i++) {
      if (myBank[i][1]==1) {
        printf("account_number: %d your balance: %.2f \n", min+i, myBank[i][0]);
      }
    }
}

void programExit() {
    for (int i = 0; i < 50; i++) {
      myBank[i][1]=0;
    }
}
