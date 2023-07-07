#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct banking {
    char acc_name[10];
    char password[10];
    int balance;
    int contact;
};

void login() {
    struct banking b;
    FILE *fp;
    char accnm[30];
    char pass[10];
    fp=fopen("user.txt","r");
    printf("enter acc name:");
    scanf("%s",accnm);
    printf("enter password:");
    scanf("%s",pass);
    while (fscanf(fp, "%s %s %d %d", b.acc_name, b.password, &b.balance, &b.contact) == 4) {
    if(strcmp(b.acc_name,accnm)==0||strcmp(b.password,pass)==0){
        printf("login successful!\n");
        fclose(fp);
        return;
    }}
    
        printf("login unsuccessful!\n");
    fclose(fp);
}
void create() {
    struct banking b;
    FILE *fp;
    fp=fopen("user.txt","a");
    if (fp == NULL) {
    printf("Failed to open the file.\n");
    return;
}    printf("enter acc name:");
    scanf("%s",b.acc_name);
    printf("set new password:");
    scanf("%s",b.password);
    printf("enter contact number:");
    scanf("%d",&b.contact);
    printf("enter the balance or first deposit:");
    scanf("%d",&b.balance);
    fprintf(fp, "%s %s %d %d\n", b.acc_name, b.password, b.balance, b.contact);
    fclose(fp);
    printf("account created successfully!\n");
}
void deleteAccount() {
    struct banking b;
    FILE *fp;
    fp=fopen("user.txt","r");
    printf("enter contact number:\n");
    int num;
    scanf("%d",&num);
    FILE *fpw;
    fpw=fopen("dummy.txt","w");

  while(fscanf(fp,"%s %s %d %d",b.acc_name,b.password,&b.balance,&b.contact)==4){
      if(b.contact!=num){
          fprintf(fpw,"%s %s %d %d\n",b.acc_name,b.password,b.balance,b.contact);
      }
  }
  fclose(fp);
  fclose(fpw);
  remove("user.txt");
  rename("dummy.txt","user.txt");
  
}
void changes() {
   deleteAccount();
   create();
    
}
void deposit() {
    struct banking b;
    FILE *fp;
    fp=fopen("user.txt","r");
    int num,x;
    FILE *fpw;
    fpw=fopen("dummy.txt","w+");
    printf("enter contact no");
    scanf("%d",&num);
    while(fscanf(fp,"%s %s %d %d",b.acc_name,b.password,&b.balance,&b.contact)==4){
    if(num==b.contact){
        printf("enter deposit amount:\n");
        scanf("%d",&x);
        fprintf(fpw,"%s %s %d %d\n",b.acc_name,b.password,b.balance+x,b.contact);
    
     } else {
            fprintf(fpw, "%s %s %d %d\n", b.acc_name, b.password, b.balance, b.contact);}
    }
    fclose(fp);
    fclose(fpw);
    remove("user.txt");
    rename("dummy.txt","user.txt");
}
void withdraw() {
    struct banking b;
    FILE *fp;
    fp=fopen("user.txt","r");
    int num,x;
    FILE *fpw;
    fpw=fopen("dummy.txt","w+");
    printf("enter contact no");
    scanf("%d",&num);
    while(fscanf(fp,"%s %s %d %d",b.acc_name,b.password,&b.balance,&b.contact)==4){
    if(num==b.contact){
        printf("enter withdraw amount:\n");
        scanf("%d",&x);
        fprintf(fpw,"%s %s %d %d\n",b.acc_name,b.password,b.balance-x,b.contact);
    
     } else {
            fprintf(fpw, "%s %s %d %d\n", b.acc_name, b.password, b.balance, b.contact);}
    }
    fclose(fp);
    fclose(fpw);
    remove("user.txt");
    rename("dummy.txt","user.txt");
}

int main() {
    int ch;
    
    do {
        printf("1. Login\n");
        printf("2. Create account\n");
        printf("3. Delete account\n");
        printf("4. Make changes/ Edit info\n");
        printf("5. Deposit cash\n");
        printf("6. Withdraw cash\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 0:
                printf("Thank you, Exiting...\n");
                break;
            case 1:
                login();
                break;
            case 2:
                create();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                changes();
                break;
            case 5:
                deposit();
                break;
            case 6:
                withdraw();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (ch != 0);

    return 0;
}
