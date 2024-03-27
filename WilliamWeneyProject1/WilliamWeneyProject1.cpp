// WilliamWeneyProject1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void inputNumProductsOrdered(int& productsOrdered); // Asks the user for the amount of products ordered.
void inputNumProductsInStock(int& productsInStock); // Asks the user for the amount of products in stock.
void inputProductPrice(double& productPrice); // Asks the user for the product's price.
void inputSpecialServiceCharge(double& serviceCharge); // Asks the user for any special service charges, if any.
void getProductInfo(int& productsOrdered, int& productsInStock, double& ProductPrice, double& serviceCharge); // Prompts the user with the inputs, calls all above functions to do their jobs.
void showProduct(int productsOrdered, int productsInStock, double ProductPrice, double serviceCharge); // Promptly displays the users final output. Including total dues, service charges, backorder (if any) and amount ready to ship and order.
int main() // Main function
{
    char response;
    do {
        int productsOrdered, productsInStock;
        double ProductPrice, serviceChargeTotal;
        getProductInfo(productsOrdered, productsInStock, ProductPrice, serviceChargeTotal);
        showProduct(productsOrdered, productsInStock, ProductPrice, serviceChargeTotal);
        cout << "Go again?\n";
        cin >> response;
    } while (response == 'y' || response == 'Y');
    
}
void inputNumProductsOrdered(int& productsOrdered) {
    cout << "How many products were ordered? \n";
    cin >> productsOrdered;
    if (productsOrdered < 1) {
        cout << "Please enter a number greater than 1: \n";
        cin >> productsOrdered;
    }
    cout << productsOrdered << " were ordered.\n";
}
void inputNumProductsInStock(int& productsInStock) {
    cout << "How many products are in stock? \n";
    cin >> productsInStock;
    if (productsInStock < 0) {
        cout << "Enter a number greater than 0: \n";
        cin >> productsInStock;
    }
    cout << productsInStock << " are in stock.\n";
}
void inputProductPrice(double& productPrice) {
    cout << "What is the product's price? \n";
    cin >> productPrice;
    if (productPrice < 0) {
        cout << "Enter a price greater than 0: \n";
        cin >> productPrice;
    }
    cout << "$" << productPrice << " is the price\n";
}
void inputSpecialServiceCharge(double& serviceCharge) {
    double specialServiceCharge;
    char answer;
    cout << "Is there a special service charge? \n";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
        cout << "Enter the amount of any special  charges : \n";
        cin >> specialServiceCharge;
        if (specialServiceCharge < 0) {
            cout << "Enter a value greater than 0: \n";
            cin >> specialServiceCharge;
        }
    }
}
void getProductInfo(int& productsOrdered, int& productsInStock, double& ProductPrice, double& serviceCharge) {
    inputNumProductsOrdered(productsOrdered);
    inputNumProductsInStock(productsInStock);
    inputProductPrice(ProductPrice);
    inputSpecialServiceCharge(serviceCharge);
}
void showProduct(int productsOrdered, int productsInStock, double ProductPrice, double serviceCharge) {
    int readyToShip = productsInStock - productsOrdered;
    int backorder = 0;
    if (readyToShip <= 0) {
        backorder = readyToShip * -1;
        readyToShip = productsOrdered - backorder;
    }
    double subtotal = readyToShip * ProductPrice;
    double baseServiceCharge = 10.00;
    double serviceChargeTotal = baseServiceCharge * productsOrdered;
    double totalDues = subtotal + serviceChargeTotal;
    if (productsInStock == 0) {
        readyToShip = 0;
        serviceChargeTotal = 0;
        totalDues = 0;
    }
    cout << "Products ordered:\n" << productsOrdered << endl;
    cout << "Ready to ship: \n" << readyToShip << endl;
    if (backorder > 0) {
        cout << "Backorder: " << backorder << endl;
    }
    cout << "\n" << "Subtotal: $" << subtotal << endl;
    cout << "Service Charges: $" << serviceChargeTotal << endl;
    cout << "Total Due: $" << totalDues << endl;
}



/*TEST RUN:
    How many products were ordered?
6
6 were ordered.
How many products are in stock?
12
12 are in stock.
What is the product's price?
200
$200 is the price
Is there a special service charge?
n
Products ordered:
6
Ready to ship:
6

Subtotal: $1200
Service Charges: $60
Total Due: $1260
Go again?
y
How many products were ordered?
30
30 were ordered.
How many products are in stock?
20
20 are in stock.
What is the product's price?
50
$50 is the price
Is there a special service charge?
y
Enter the amount of any special  charges :
5
Products ordered:
30
Ready to ship:
20
Backorder: 10

Subtotal: $1000
Service Charges: $300
Total Due: $1300
Go again?
y
How many products were ordered?
-2
Please enter a number greater than 1:
2
2 were ordered.
How many products are in stock?
0
0 are in stock.
What is the product's price?
400
$400 is the price
Is there a special service charge?
y
Enter the amount of any special  charges :
-5
Enter a value greater than 0:
50
Products ordered:
2
Ready to ship:
0
Backorder: 2

Subtotal: $0
Service Charges: $0
Total Due: $0
Go again?
n
*/