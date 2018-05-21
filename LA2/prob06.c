#include <stdio.h>

struct Item
{
	char itemName[20];
	int itemCode;
	float price;
	int QtyInStock;
	int IsHighDemand;
	int SoldToday;
}Item;

int main(int argc, char const *argv[])
{
	struct Item i1 = {"pen",123,12.5,20,10,15};
	i1.price = 5.5;
	i1.QtyInStock = 50;
	printf("price: %f\n", i1.price);

	return 0;
}