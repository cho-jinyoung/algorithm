//RSA (Rivest–Shamir–Adleman)

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



int gcd(a, b){
	int temp = 0;

	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int get_public_key(tot) {
	int e = 2;
	while (e < tot && (gcd(e, tot) != 1)) {
		e += 1;
	}
	return e; 
}
int get_private_key(e, tot) {
	int k = 1;
	while ((e*k) % tot != 1 || k == e) {
		k += 1;
	}
	return k;
}
void decrypt(int d, int n, unsigned char *entext) {
	int num = strlen(entext);
	int i, j;
	unsigned int plain[256];

	printf("\nDecrypted Message:");

	for (i = 0; i < num; i++) {
		plain[i] = 1;
		for (j = 0; j < d; j++)
			plain[i] = (plain[i] * entext[i]) % n;
		printf("%c", plain[i]);
	}
}
void encrypt(int e, int n, unsigned char *plaintext, unsigned char *entext) {
	//Convert each letter in the plaintext to numbers based on the character using a^b mod m
	int num = strlen(plaintext);
	int i, j;
	unsigned int plain[256];

	printf("\nEncrypted Message:");

	for (i = 0; i < num; i++) {
		//cipher[i] = powl(plaintext[i], e) % n;
		plain[i] = 1;
		for (j = 0; j < e; j++)
			plain[i] = (plain[i] * plaintext[i]) %n;
		entext[i]=plain[i]%n;
		printf("%d", entext[i]);
	}
	int num1 = strlen(entext);
	printf("%d", num1);

}

int main() {
	unsigned char input[256];
	unsigned int en_msg[256] = { 0, };

	int p = 13, q = 23, n, totient, e, d;
	printf("Enter the text to be encrypted: ");
	gets(input);
	printf("Two prime numbers(p and q) are: %d, %d", p, q);

	n = p * q;
	printf("\nn=(p*q)=%d*%d=%d", p, q, n);

	totient = (p - 1)*(q - 1);
	printf("\n(p-1)*(q-1)=%d", totient);

	// Step 4. Find public key e
	e = get_public_key(totient);
	printf("\nPublic key(n, e):(%d, %d)", n, e);

	// Step 5. Find private key d
	d = get_private_key(e, totient);
	printf("\nPrivate key(n, d):(%d, %d)",n, d);

	// Step 6.Encrypt message	
	encrypt(e, n, input, en_msg);	

	// Step 7.Decrypt message
	decrypt(d, n, en_msg);

	getch();
}
