/* -------------------------------------------
Name: Andre Machado do Monte
Student number: 152848164
Email: amachado-do-monte@myseneca.ca
Section: SXX
Date:       
----------------------------------------------
Project_02 - Contacts
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (10):
#define MAXCONTACTS 10


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------


// clearKeyboard
void clearKeyboard(void) {
	char newLine = 0;
	while (newLine != '\n') {
		scanf ("%c", &newLine);
	}
}

// pause:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void) {
	int value;
	char newLine = 0;
	do {
		scanf("%d%c", &value, &newLine);
		if (newLine != '\n') {
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
	} while (newLine != '\n');
	return value;
}

// getIntInRange:
int getIntInRange(int min, int max) {
	int value;
	do {
		value = getInt();
		if (value < min || value > max) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	} while (value < min || value > max);
	return value;
}

// yes:
int yes(void) {
	char ch;
	char newLine = 0;
	do {
		scanf("%c%c", &ch, &newLine);
		if (!(ch == 'y' || ch == 'Y' || ch == 'N' || ch == 'n') || newLine != '\n') {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			if (newLine != '\n') clearKeyboard();
		}
	} while (!(ch == 'y' || ch == 'Y' || ch == 'N' || ch == 'n') || newLine != '\n');
	if (newLine != '\n') clearKeyboard();
	if (ch == 'y' || ch == 'Y') {
		return 1;
	}
	else {
	 	return 0;
	}
}

// menu:
int menu(void) {
	int selection;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf ("0. Exit\n");
	printf("\n");
	printf ("Select an option:> ");
	selection = getIntInRange(0, 6);
	printf("\n");
	return selection;	
}

// ContactManagerSystem:
	void ContactManagerSystem(void) {
	struct Contact contact [MAXCONTACTS] = {
	{{"Rick", {'\0'}, "Grimes"}, {11, "Trailer Park", 0, "A7A 2J2", "King City"}, {"4161112222", "4162223333", "4163334444"}},
	{ {"Maggie", "R.", "Greene"}, {55, "Hightop House", 0, "A9A 3K3", "Bolton"}, {"9051112222", "9052223333", "9053334444"} },
	{ {"Morgan", "A.", "Jones"}, {77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough"}, {"7051112222", "7052223333", "7053334444"} },
	{ {"Sasha", {'\0'}, "Williams"}, {55, "Hightop House", 0, "A9A 3K3", "Bolton"}, {"9052223333", "9052223333", "9054445555"} }
	};	

	int selection = 1;
	char answer;
	while (selection != 0) {
	selection = menu();
	switch (selection) {
		
	case 1:
		displayContacts(contact, MAXCONTACTS);
		pause();
		printf ("\n");
		break;
	
	case 2:
		addContact(contact, MAXCONTACTS);
		pause();
		printf ("\n");
		break;
	
	case 3:
		updateContact(contact, MAXCONTACTS);
		pause();
		printf ("\n");
		break;
	
	case 4:
		deleteContact(contact, MAXCONTACTS);
		pause();
		printf ("\n");
		break;
	
	case 5:
		searchContacts(contact, MAXCONTACTS);
		pause();
		printf ("\n");
		break;
	
	case 6:
		printf("\nSort contacts by cell phone number\n");;
		pause();
		printf ("\n");
		break;
	
	default:
		printf("Exit the program? (Y)es/(N)o: ");
		answer = 1;
		scanf("%c", &answer);
		printf ("\n");
		if (answer == 'y' || answer == 'Y') {
			printf("Contact Management System: terminated\n");
		}
		else if (answer == 'n' || answer == 'N') {
			ContactManagerSystem();
			break;	
			}
		}
	}
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[11]) {
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contact[], int contact_size, const char cellNum[]) {
	int i;
	int achou = -1;
	//printf("%d\n", contact_size);
	//printf("\n%s", cellNum);
	for (i = 0; i < contact_size; i++) {
		
		if (strcmp (contact[i].numbers.cell, cellNum) == 0) {
			
		   achou = i;

	    }
	}
	return achou;
}

// displayContactHeader
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int z) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", z);
}

// displayContact:
void displayContact(const struct Contact contact) {
	if (*contact.name.middleInitial == 0) {
		printf(" %s %s\n", contact.name.firstName, contact.name.lastName);
		} else {
		printf(" %s %s %s\n", contact.name.firstName, contact.name.middleInitial, contact.name.lastName);
		}
	
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact.numbers.cell, contact.numbers.home, contact.numbers.business);

	if (contact.address.apartmentNumber > 0) {
		printf("       %d %s, Apt# %d, %s, %s\n", contact.address.streetNumber, contact.address.street, contact.address.apartmentNumber, contact.address.city, contact.address.postalCode);
	}
	else {
		printf("       %d %s, %s, %s\n", contact.address.streetNumber, contact.address.street, contact.address.city, contact.address.postalCode);
	}
}

// displayContacts:
void displayContacts(const struct Contact contact[], int p) {
	displayContactHeader();
	int i;
	int z = 0;
	char teste [11] = {'\0'};
	for (i = 0; i < p; i++) {
		if (strcmp(contact[i].numbers.cell, teste) != 0) {
			displayContact(contact[i]);
			z++;
		}
	}
	displayContactFooter(z);
}

//searchContacts:
void searchContacts(const struct Contact contact[], int sizeOf) {
	int i;
	char fone[11];
	//sizeOf ta chegando com 5;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(fone);
	printf("\n");
    //fone funcionando.
    
	i = findContactIndex(contact, sizeOf, fone);
	
	//printf("%d\n\n", i);

	if (i > -1) {
		displayContact(contact[i]);
		printf("\n");
	}
	else {
	printf("*** Contact NOT FOUND ***\n");
	}

}

// addContact:
void addContact(struct Contact contact[], int sizeOf) {
	int i;
	for (i = 0; i < sizeOf; i++) {
		
		if (strlen (contact[i].numbers.cell) == 0) {
			getContact(&contact[i]);
			printf("--- New contact added! ---\n");
			break;
		}
	}
	if (sizeOf == i) {
		printf("*** ERROR: The contact list is full! ***\n");
	}
}
// updateContact:
void updateContact(struct Contact contact[], int sizeOf) {
	int index;
	char number [11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);
	index = findContactIndex(contact, sizeOf, number);
	if (index != -1) {
		printf("\nContact found:\n");
		displayContact(contact[index]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		if (yes() != 0 ) {
			getName(&contact[index].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes() != 0 ) {
			getAddress(&contact[index].address);
	}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() != 0 ) {
			getNumbers(&contact[index].numbers);
	printf("--- Contact Updated! ---\n");
		}
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
}
// deleteContact:
void deleteContact(struct Contact contact[], int sizeOf) {
	int index;
	char cellNumber[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNumber);
	index = findContactIndex(contact, sizeOf, cellNumber);
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf ("\nContact found:\n");
		displayContact(contact[index]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");
		if (yes() > 0) {
		contact[index].numbers.cell[0] = 0;
		printf("--- Contact deleted! ---\n");
		}
		
	}
}

// sortContacts:
//void sortContacts () {
//}