#include <stdio.h>
#include "myBank.h"
#define min 901
#define count 50

double myBank[50][2] = {0};
int account_number;
double amount,interest_rate;
void openAccount() {
      printf("Please insert amount for deposit: ");
      if(scanf("%lf", &amount)==1) {
      if (amount<0) {
        printf("\nsorry, can't deposite a negative amount, please try again\n");
        return;
      }
      for (int i = 0; i < count;) {
        if (myBank[i][1]==0){
          myBank[i][0]=amount;
          myBank[i][1]=1;
          printf("\nAccount number %d has been successfully opened\n", min+i);
          break;
        }
        else i++;
      }
    }
}

void getBalance() {
    printf("Please insert account number: ");
    if(scanf("%d", &account_number)==1){
      if (myBank[account_number-min][1]==1) {
        printf("\nyour balance is %.2f\n", myBank[account_number-min][0]);
      }

      else {
        printf("\ninvalid account number.\n");
        return;
      }
    }
}

void deposit() {
    printf("Please insert account number: ");
    if(scanf("%d", &account_number)==1){
      if (myBank[account_number-min][1]==1) {
        printf("\nPlease insert amount for deposit: ");
        if(scanf("%lf", &amount)==1){
          myBank[account_number-min][0] += amount;
          printf("\nyour new balance is %.2f\n", myBank[account_number-min][0]);
        }
      }
      else {
        printf("\ninvalid account number.\n");
        return;
      }
    }
}

void withdrawal() {
    printf("Please insert account number: ");
    if(scanf("%d", &account_number)==1){
      if (myBank[account_number-min][1]==1) {
        printf("Please insert amount for deposit: ");
        if(scanf("%lf", &amount)==1){
          if (myBank[account_number-min][0]>amount) {
            myBank[account_number-min][0] -= amount;
            printf("\nyour new balance is %.2f\n", myBank[account_number-min][0]);
          }

          else {
            printf("\nyou don't have enough money, please insert a lower amount\n");
          }
        }
      }

      else {
        printf("\nyour account is closed\n");
      }
    }
}

void closeAccount() {
    printf("Please insert account number: ");
    if(scanf("%d", &account_number)==1){
      if (myBank[account_number-min][1]==1) {
        myBank[account_number-min][1]=0;
        printf("\nyour account has been successfully closed \n");
      }
      else {
        printf("\nthis account is already closed\n");
      }
    }
}

void setInterest() {
    printf("Please insert interest value: ");
    if(scanf("%lf", &interest_rate)==1){
      if(interest_rate<=100){
        double ir=(interest_rate/100) +1;
        for (int i = 0; i < 50; i++) {
          if (myBank[i][1]==1) {
            double amount = myBank[i][0];
            myBank[i][0] = amount*ir;
          }
        }
      }
      else{printf("interest_rate is not in the range\n");}
    }
}

void printAll() {
    for (int i = 0; i < 50; i++) {
      if (myBank[i][1]==1) {
        printf("account_number: %d your balance: %.2f\n", min+i, myBank[i][0]);
      }
    }
}

void programExit() {
    for (int i = 0; i < 50; i++) {
      myBank[i][1]=0;
    }
}
