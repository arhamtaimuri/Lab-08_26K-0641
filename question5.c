
#include <stdio.h>

int main() {

    double costprice, sellingprice, qty;

    double *cstprice = &costprice;
    double *sellprice = &sellingprice;
    double *quantity = &qty;

    printf("Enter cost price: ");
    scanf("%lf", cstprice);

    printf("Enter selling price: ");
    scanf("%lf", sellprice);

    printf("Enter quantity: ");
    scanf("%lf", quantity);

    double totalcost, totalsales, profit = 0, loss = 0;
    double profitpercentage = 0;

    double *total_cost = &totalcost;
    double *total_sales = &totalsales;
    double *__profit = &profit;
    double *__loss = &loss;
    double *profit_percentage = &profitpercentage;


    *total_cost = (*cstprice)*(*quantity);
    *total_sales = (*sellprice)*(*quantity);

    printf("\nTotal Cost: %.2lf", *total_cost);
    printf("\nTotal Sales: %.2lf", *total_sales);

    // Profit or Loss
    if (*total_sales > *total_cost) {
        *__profit = *total_sales - *total_cost;
        printf("\nProfit: %.2lf", *__profit);
        printf("\nYou made a Profit!");

    }
    else if (*total_cost > *total_sales) {
        *__loss = *total_cost - *total_sales;
        printf("\nLoss: %.2lf", *__loss);
        printf("\nYou Earned a Loss");
    }
    else {
        printf("\nNo profit no loss");
    }

    if (*total_cost != 0) {
        *profit_percentage = (*__profit / *total_cost)*100;
        printf("\nProfit Percentage: %.2lf%%", *profit_percentage);
    }
    else {
        printf("\nProfit percentage cannot be calculated.");
    }

    double *larger;

    if (*cstprice >= *sellprice) {
        larger = cstprice;
    }
    else {
        larger = sellprice;
    }

    if (larger == cstprice) {
        printf("\nLarger variable: costprice");
    }
    else {
        printf("\nLarger variable: sellingprice");
    }

    printf("\nLarger value: %.2lf", *larger);

    printf("\nAddresses of Variables: ");

    printf("\nCost price: %p",&costprice);
    printf("\nSelling price: %p",&sellingprice);
    printf("\nQuantity: %p",&qty);
    printf("\nTotal cost: %p",&totalcost);
    printf("\nTotal sales: %p",&totalsales);
    printf("\nProfit: %p",&profit);
    printf("\nLoss: %p",&loss);
    printf("\nProfit percentage: %p",&profitpercentage);

    printf("\nAddresses of Pointers:  ");

    printf("\nCstprice pointer: %p",cstprice);
    printf("\nSellprice pointer: %p",&sellprice);
    printf("\nQuantity pointer: %p",&quantity);
    printf("\nTotal cost pointer: %p",&total_cost);
    printf("\nTotal sales pointer: %p",&total_sales);
    printf("\nProfit pointer: %p",&__profit);
    printf("\nLoss pointer: %p",&__loss);
    printf("\nPercentage pointer: %p",&profit_percentage);
    printf("\nLarger pointer: %p",&larger);

    return 0;
}
