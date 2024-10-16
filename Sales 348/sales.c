#include <stdio.h>
// Including the math library.
#include <math.h>

#define NUM_MONTHS 12

const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Declaring an array of doubles called sales.
double sales[NUM_MONTHS];
// Declaring an array of doubles called sixMonthAverages.
double sixMonthAverages[7];

// Sorting the sales data from highest to lowest and prints the sorted data.
int main(void) {
    char filename[100];
    printf("Enter your file: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    // Checking if the file is empty.
    if (file == NULL) {
        printf("Unable to open sales file\n");
        // Returning the value 1 (FALSE) to the operating system.
        return 1;
    }

    // Read sales data from file
    int i;
    // For loop that is used to iterate through the array of sales.
    for (i = 0; i < NUM_MONTHS; i++) {
        // Reading the sales data from the file and storing it in the array of sales.
        fscanf(file, "%lf", &sales[i]);
    }
    fclose(file);

    // Generate sales report
    printf("\nMonthly Sales Report\n");
    printf("-----------------------------------\n");
    printf("Month\t\tSales\n");
    printf("-----------------------------------\n");
    // For loop that is used to iterate through the array of sales.
    for (i = 0; i < NUM_MONTHS; i++) {
        // Printing the months and sales data to the console.
        printf("%s\t\t$%.2lf\n", months[i], sales[i]);
    }
    printf("-----------------------------------\n\n\n");

    // Calculate sales summary
    double total = 0;
    double min = sales[0]; 
    double max = sales[0];
    int minIndex = 0;
    int maxIndex = 0;
    // For loop that is used to iterate through the array of sales.
    for (i = 0; i < NUM_MONTHS; i++) {
        total += sales[i];
        // Checking if the sales data is less than the minimum.
        if (sales[i] < min) {
            min = sales[i];
            minIndex = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxIndex = i;
        }
    }
    // Calculating the average of the sales data.
    double average = total / NUM_MONTHS;
    printf("Sales Summary\n");
    printf("-----------------------------------\n");
    printf("Month with lowest sales: %s ($%.2lf)\n", months[minIndex], min);
    printf("Month with highest sales: %s ($%.2lf)\n", months[maxIndex], max);
    printf("Average sales: $%.2lf\n", average);
    printf("-----------------------------------\n\n\n");

    // Calculating each of the six-month averages
    sixMonthAverages[0] = (sales[0] + sales[1] + sales[2] + sales[3] + sales[4] + sales[5]) / 6;
    sixMonthAverages[1] = (sales[1] + sales[2] + sales[3] + sales[4] + sales[5] + sales[6]) / 6;
    sixMonthAverages[2] = (sales[2] + sales[3] + sales[4] + sales[5] + sales[6] + sales[7]) / 6;
    sixMonthAverages[3] = (sales[3] + sales[4] + sales[5] + sales[6] + sales[7] + sales[8]) / 6;
    sixMonthAverages[4] = (sales[4] + sales[5] + sales[6] + sales[7] + sales[8] + sales[9]) / 6;
    sixMonthAverages[5] = (sales[5] + sales[6] + sales[7] + sales[8] + sales[9] + sales[10]) / 6;
    sixMonthAverages[6] = (sales[6] + sales[7] + sales[8] + sales[9] + sales[10] + sales[11]) / 6;
    // Printing the strings to the console.
    printf("Six-Month Averages\n");
    printf("-----------------------------------\n");
    printf("January - June\t\t$%.2lf\n", sixMonthAverages[0]);
    printf("February - July\t\t$%.2lf\n", sixMonthAverages[1]);
    printf("March - August\t\t$%.2lf\n", sixMonthAverages[2]);
    printf("April - September\t$%.2lf\n", sixMonthAverages[3]);
    printf("May - October\t\t$%.2lf\n", sixMonthAverages[4]);
    printf("June - November\t\t$%.2lf\n", sixMonthAverages[5]);
    printf("July - December\t\t$%.2lf\n", sixMonthAverages[6]);
    printf("-----------------------------------\n\n\n");

    // Print the months and sales from the highest to lowest
  printf("Months and Sales from the Highest to Lowest:\n");
  printf("-----------------------------------\n");
  printf("Month\t\tSales\n");
  printf("-----------------------------------\n");
    // Sorting the sales data from highest to lowest

  int k, j;
  // For loop that is used to iterate through the array of sales.
  for (k = 0; k < NUM_MONTHS - 1; k++) {
    for (j = k + 1; j < NUM_MONTHS; j++) {
      // Checking if the sales data is less than the sales data in the next index.
      if (sales[k] < sales[j]) {
        // Storing the value of sales[k] in a temporary variable called temp.
        double temp = sales[k];
        // Swapping the values of sales[k] and sales[j].
        sales[k] = sales[j];
        sales[j] = temp;

        // Storing the value of months[k] in a temporary variable called tempMonth.
        const char* tempMonth = months[k];
        // Swapping the values of months[k] and months[j].
        months[k] = months[j];
        months[j] = tempMonth;
      }
    }
  }

  // Printing the sorted data
  // For loop that is used to iterate through the array of sales.
  for (i = 0; i < NUM_MONTHS; i++) {
    // Printing the months and sales data to the console.
    printf("%s\t\t$%.2lf\n", months[i], sales[i]);
  }

  return 0;
}
