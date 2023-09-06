// This program is a simplified winter electricity bill calculator using C. It calculates a numeric value of user's winter electricity bill for the month. 

#include <stdio.h>
#include <string.h>

// Function definitions
int winterElectricityBillCalculations();


// This function contains all the code for the monthly winter electricity bill calculations.
int winterElectricityBillCalculations() {

  // Establish all the variables that will be used in this program.
  int userTier;
  
  int winterUsageHours;

  float winterkwh;
  
  char residentialorNot[3];
  
  int winterTotalWattsUsed;

  float winterTier1Cost;
  float winterTier2Cost;

  do {
    // Keep asking the user this question until they input one of the appropriate inputs.
    printf("\nAre you of residential or non residential status (type as r for residential or n for non residentiual status): ");
    scanf("%s", residentialorNot);
  
  } while ((strcmp(residentialorNot, "r") != 0) && (strcmp(residentialorNot, "n") != 0));


  printf("\nHow many total Watts (from your appliances) have you used during Winter (November 1 - April 30): ");
  scanf("%d", &winterTotalWattsUsed);


  printf("\nWhat was your appliance usage hours for winter?: ");
  scanf("%d", &winterUsageHours);



  // This will calculate user's kw/h using their inputted information about their total watts used and appliance usage hours.
  winterkwh = (winterTotalWattsUsed * winterUsageHours) / 1000;

  // These prices are from the Ontario Tiered electricity rates.
  // Link is https://www.oeb.ca/consumer-information-and-protection/electricity-rates
  winterTier1Cost = winterkwh * 8.7;
  winterTier2Cost = winterkwh * 10.3;
  
 
  // For residential users, this establishes their specific price rates depending on how many kw/h they've used during the winter.
  if ((strcmp(residentialorNot, "r")) == 0) {
    
    if (winterkwh <= 1000) {
      printf("\nYour winter electricity bill for the month is $%.2f", winterTier1Cost);
    }
      
    if (winterkwh > 1000) {
      printf("\nYour winter electricity bill for the month is $%.2f", winterTier2Cost);
    }
      
  }


    // For non residential users, this establishes their specific price rates depending on how many kw/h they've used during the winter.
  if ((strcmp(residentialorNot, "n")) == 0) {
    if (winterkwh <= 750) {
      printf("\nYour winter electricity bill for the month is $%.2f", winterTier1Cost);
      
    }
    else if (winterkwh > 750) {
      printf("\nYour winter electricity bill for the month is $%.2f", winterTier2Cost);
    }
    else {
      printf("");
    }
  }

  return 0;
}


int main() {

  // Establish all the variables that will be used in this program.
  
  int userTier;
  
  int winterUsageHours;

  float winterkwh;
  
  char residentialorNot[3];
  
  int winterTotalWattsUsed;

  float winterTier1Cost;
  float winterTier2Cost;

  // Calling the function in main.
  winterElectricityBillCalculations();
  
  return 0;
}