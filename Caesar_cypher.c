#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>	// For getch function
#include <unistd.h> // For sleep function

void LargeTitleMenu()
{
	printf("=======================================================================================================\n");
	printf("|                                                                                                     |\n");
	printf("|  ____    _____    _____    _____     _____    ________      _____    ______    ____       _____     |\n");
	printf("| |  __|  |  ___|  |  ___|  |  _  \\   |  ___|  |___  ___|    |  ___|  |  __  |  |  __ \\    |  ___|    |\n");
	printf("| | |__   | |___   | |      | | | |   | |___      |  |       | |      | |  | |  | |  | |   | |___     |\n");
	printf("| |__  |  | ____|  | |      |  _  /   | ____|     |  |       | |      | |  | |  | |  | |   | ____|    |\n");
	printf("|  __| |  | |___   | |___   | \\ \\ \\   | |___      |  |       | |___   | |__| |  | |__| |   | |___     |\n");
	printf("| |____/  |_____|  |_____|  |_| |_|   |_____|     |__|       |_____|  |______|  |_____/    |_____|    |\n");
	printf("|                                                                                                     |\n");
	printf("========================================================================================================\n");
}

// RUMUS ENCRYPTION
// En(x)=(x+n)mod 26
void enkripsi () {
	// VARIABEL
	char text[500];
	int shift;
	int i;

	printf("Masukan huruf yang mau di enkripsi: ");
	fgets(text, sizeof(text), stdin);
	text[strcspn(text, "\n")] = '\0';
	printf("Masukan angka untuk di shift: ");
	scanf("%d", &shift);

	while (getchar() != '\n')
		; // CLEAR BUFFER

	shift %= 26;
	for (i = 0; text[i] != '\0'; i++)
	{
		if (isalpha(text[i]))
		{ // Check kalo itu text
			if (islower(text[i]))
			{ // Check kalo itu huruf kecil
				text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
			}
			else if (isupper(text[i]))
			{ // Check kalo itu huruf besar
				text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
			}
		}
	}

	printf("Pesan yang di Enrkipsi: %s\n", text);
}

void dekripsi() {
	// VARIABEL
	char text[500];
	int shift;
	int i;

	printf("Masukan huruf yang mau di dekripsi:");
	fgets(text, sizeof(text), stdin);
	text[strcspn(text, "\n")] = '\0';
	printf("Masukan angka untuk di shift:");
	scanf("%d", &shift);

	while (getchar() != '\n')
		; // CLEAR BUFFER

	shift %= 26;
	for (i = 0; text[i] != '\0'; i++)
	{
		if (isalpha(text[i]))
		{ // Check kalo itu text
			if (islower(text[i]))
			{ // Check kalo itu huruf kecil
				text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
			}
			else if (isupper(text[i]))
			{ // Check kalo itu huruf besar
				text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
			}
		}
	}

	printf("Pesan yang di dekripsi: %s\n", text);
}

void menu () {
	char choice;

	system("cls"); // Clear screen
	while (1)
	{
		LargeTitleMenu();
		printf("1. Enkripsi\n");
		printf("2. Dekripsi\n");
		printf("3. EXIT\n");
		printf("Masukan pilihan kamu: ");
		choice = getch();

		if (choice < '1' || choice > '3')
		{
			printf("Pilihan invalid. Pilih antara 1 dan 3.\n");
			sleep(3);
			system("cls"); // Clear screen
		}

		if (choice == '1')
		{
			enkripsi();
			printf("Silahkan tekan tombol apapun untuk melanjutkan.\n");
			getch(); // Wait for a key press
			system("cls"); // Clear screen
		}

		if (choice == '2')
		{
			dekripsi();
			printf("Silahkan tekan tombol apapun untuk melanjutkan.\n");
			getch(); // Wait for a key press
			system("cls"); // Clear screen
		}

		if (choice == '3')
		{
			return;
		}
	}
}

int main(void){
	menu();

	return 0;
}