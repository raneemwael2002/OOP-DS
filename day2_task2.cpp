#include <iostream>
#include <string.h>
#include <cstdlib> 

using namespace std;
int time_table(int i) {

	int num = 5;

	int result = num * i;
	std::cout << num << "*" << i << "=" << result << "\n";
	if (i == 0) {
		return 0;
	}
	time_table(--i);


}

int factorial_noptr(int num) {

	if (num <= 1) {
		cout << "This function will calculate factorial without pointers\n";
		return 1;
	}
	int result = num * factorial_noptr(num - 1);

	return result;



}

void factorial_ptr(int* num, int* result) {

	if (*num == 0 || *num == 1) {
		*result = 1;
	}
	else {
		int temp = *num - 1;
		factorial_ptr(&temp, result);
		*result *= *num;
	}
}

int power_noptr(int base, int power) {

	if (power == 0) {
		return 1;
	}
	else {
		return base * power_noptr(base, power - 1);
	}
}

void power_ptr(int* base, int* power, int* result) {

	if (*power == 0) {
		*result = 1;
	}
	else {
		int temp = *power - 1;
		power_ptr(base, &temp, result);
		*result *= *base;
	}
}


struct Item {
	string name;
	string type;
	int value;
};


struct Inventory {
	Item items[10];
	int itemCount;


	Inventory() {
		items[0] = { "Sword", "Weapon", 100 };
		items[1] = { "Shield", "Armor", 150 };
		items[2] = { "Potion", "Health", 50 };
		items[3] = { "Bow", "Weapon", 120 };
		items[4] = { "Helmet", "Armor", 75 };


		itemCount = 5;
	}


	void add_item() {
		if (itemCount < 10) {
			string itemName, itemType;
			int itemValue;


			cout << "Enter the name of the item: ";
			cin >> itemName;
			cout << "Enter the type of the item (e.g., Weapon, Armor, Potion): ";
			cin >> itemType;
			cout << "Enter the value of the item: ";
			cin >> itemValue;


			items[itemCount].name = itemName;
			items[itemCount].type = itemType;
			items[itemCount].value = itemValue;

			itemCount++;
			cout << "Added: " << itemName << " (" << itemType << ") to inventory.\n";
		}
		else {
			cout << "Inventory is full! Cannot add more items.\n";
		}
	}


	string get_item_name(int index) {
		if (index >= 0 && index < itemCount) {
			return items[index].name;
		}
		else {
			return "Invalid index!";
		}
	}
};


int main() {
	while (true) {

		int choice;
		std::cout << "\nWelcome to our program, please select a number: " << endl;
		std::cout << "1- Time table with recursion " << endl;
		std::cout << "2-Calculate factorial and power of number with and without pointers " << endl;
		std::cout << "3-Inventory struct" << endl << "4-Exit\n";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			time_table(10);
			cout << endl << "Thanks for using our program! Have a nice day:)";
			break;
		}
		case 2: {
			int number;
			cout << "\n Enter the desired number:  ";
			cin >> number;
			int res1 = factorial_noptr(number);
			cout << res1 << endl;
			int res2;
			cout << "Now, This is the function that calculate factorial  using ptrs" << endl;
			factorial_ptr(&number, &res2);
			cout << res2 << endl;
			int base, pow;
			cout << "Please enter the base then the power" << endl;
			cin >> base >> pow;
			cout << "Now, This is the function that calculate power with no ptrs" << endl <<
				power_noptr(base, pow);
			int res3;
			cout << "\nNow, This is the function that calculate power using ptrs\n";
			power_ptr(&base, &pow, &res3);
			cout << res3 << endl << "Thanks for using our program! Have a nice day:)";

			break;
		}
		case 3: {

			Inventory playerInventory;

			int choice, index;
			while (true) {
				cout << "\n1. Add item to inventory\n2. Get item by index\n 3.Exit\n Choose an option: ";
				cin >> choice;

				if (choice == 1) {

					playerInventory.add_item();
				}

				if (choice == 2) {

					cout << "Enter the index of the item you want to check , default is (0-4): ";
					cin >> index;
					cout << "Item at index " << index << " is: "
						<< playerInventory.get_item_name(index) << endl;


				}

				if (choice == 3) {
					cout << endl << "Thanks for using our program! Have a nice day:)\n";

					return 0;
				}
				//else {
					//cout << endl << "Please enter valid option\n";

				//}
			}

			break;
		}


		case 4:{
			cout << endl << "Thanks for using our program! Have a nice day:)\n";

			return 0;
			                     
		}
		default: {
			cout << "PLEASE ENTER VALID OPTION";
			break;
		}



		}
	}
}
