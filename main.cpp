#include <stdio.h>
#include <fstream>

int main()
{
	//Variables
    int unit;
    int check;
    char cname[25];
    float amt, total_amt, tax;

root:	
	printf("\n\t1.Generate New Bill & View");
	printf("\n\t2.Export A Bill As A Text File\n ");
	
    printf("Enter Your Choise:");
    scanf("%d", &check);
	
user:
    //Get Input Data
    printf("Enter Customer Name: ");
    scanf("%s", cname);
    
    printf("Enter Total Units Consumed By Customer: ");
    scanf("%d", &unit); 
	
    //Unit Calculation
    if(unit <= 50)
    {
        amt = unit * 0.50;
    }
    else if(unit <= 150)
    {
        amt = 25 + ((unit-50) * 0.75);
    }
    else if(unit <= 250)
    {
        amt = 100 + ((unit-150) * 1.20);
    }
    else
    {
        amt = 220 + ((unit-250) * 1.50);
    }

    tax = amt * 0.05;
    total_amt  = amt + tax;   	
 switch(check) {
      case 1: 
    //Display Output
    printf("\n\t******************Electricity Bill In This Month******************\n");
    printf("\tCustomer Name:%s\n", cname);
    printf("\tNumber Of Units Consumed:%d\n", unit);
    printf("\tCharge For The Electricity Consumed(Without Tax) = Rs. %.2f\n", amt);
    printf("\tCharge For The Electricity Consumed(With Tax) = Rs. %.2f\n", total_amt);
    printf("\n\t******************************************************************\n");
    goto user;
      case 2: 
    printf("Customer Bill Exported As A Text File Into Your Defult Path!(Bill.txt)\n");
    freopen ("Bill.txt","w",stdout);  
    printf("\n\t******************Electricity Bill In This Month******************\n");
    printf("\tCustomer Name:%s\n", cname);
    printf("\tNumber Of Units Consumed:%d\n", unit);
    printf("\tCharge For The Electricity Consumed(Without Tax) = Rs. %.2f\n", amt);
    printf("\tCharge For The Electricity Consumed(With Tax) = Rs. %.2f\n", total_amt);
    printf("\n\t******************************************************************\n");
    fclose (stdout);   
      default: 
        printf("Please Enter Vaild Selection!");
   }  	 
    return 0;
}
