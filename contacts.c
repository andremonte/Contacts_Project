/* -------------------------------------------
Name: Andre Machado do Monte
Student number: 152848164
Email: amachado-do-monte@myseneca.ca
Section: SXX
Date:
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"
#include <string.h>

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName (struct Name* name) {
	char resposta;
	printf("Please enter the contact's first name: ");
	scanf("%[^\n]", name->firstName);
	clearKeyboard();
		
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	resposta = yes();
		
	if (resposta == 1) {
		printf("Please enter the contact's middle initial(s): ");
		//fgets(name.middleInitial, 7, stdin);
		scanf("%s", name->middleInitial);		
		clearKeyboard();
	}
		
	printf("Please enter the contact's last name: ");
	scanf("%[^\n]", name->lastName);
	clearKeyboard();
}

// getAddress:
void getAddress (struct Address* address) {
	char resposta;
	printf("Please enter the contact's street number: ");
	resposta = getInt();
	address->streetNumber = resposta;
		
	printf("Please enter the contact's street name: ");
	scanf("%[^\n]", address->street);
	clearKeyboard();
		
	printf("Do you want to enter an apartment number? (y or n): ");
	resposta = yes();	
	if (resposta == 1) {

		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address->apartmentNumber);		
		clearKeyboard();}
		else {
			address->apartmentNumber = 0;
		}
		
	printf ("Please enter the contact's postal code: ");
	scanf("%[^\n]", address->postalCode);
	clearKeyboard();
		
	printf("Please enter the contact's city: ");
	scanf("%[^\n]", address->city);		
	clearKeyboard();	
}

// getNumbers:
void getNumbers (struct Numbers* numbers) {

	printf("Please enter the contact's cell phone number: ");
	
	getTenDigitPhone(numbers->cell);
	//char examplePhone[11];
	//printf("Enter example phone number: ");
	//getTenDigitPhone(examplePhone);
	//numbers->cell = getTenDigitPhone(char telNum[]);
		
	
	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	else
	{
		numbers->home[0] = '\0';
	}
		
	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes()) {
	printf("Please enter the contact's business phone number: ");
	getTenDigitPhone(numbers->business);
	}
	else {
		
		numbers->business[0] = '\0';
	}
	}

// getContact:
void getContact (struct Contact* contact) {
	getName (&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
