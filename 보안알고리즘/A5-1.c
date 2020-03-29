//보안 알고리즘 2019.03.22 3주차 과제 -대칭키 암호A5/1
#include <stdio.h>

int main() {
	int x[19] = { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 };
	int y[22] = { 1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1 };
	int z[23] = { 1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0};

	int i, j, t, maj, m, key;

	for (j = 0; j < 32; j++){
		maj = x[8] + y[10] + z[10];

		if (maj == 1 || maj == 0)
			m = 0;
		else if (maj == 2 || maj == 3)
			m = 1;

		if (x[8] == m) {
			t = x[13] ^ x[16] ^ x[17] ^ x[18];
			for (i = 18; i > 0; i--)
				x[i] = x[i - 1];
			x[0] = t;
		}
		if (y[10] == m) {
			t = y[20] ^ y[21];
			for (i = 21; i > 0; i--)
				y[i] = y[i - 1];
			y[0] = t;
		}
		if (z[10] == m) {
			t = z[7] ^ z[20] ^ z[21] ^ z[22];
			for (i = 22; i > 0; i--)
				z[i] = z[i - 1];
			z[0] = t;
		}
		key = x[18] ^ y[21] ^ z[22];
		printf("keystream :%d\n", key);
	}
	printf("\nx=>");
	for (i = 0; i < 19; i++)
		printf("%d", x[i]);
	printf("\ny=>");
	for (i = 0; i < 22; i++)
		printf("%d", y[i]);	
	printf("\nz=>");
	for (i = 0; i < 23; i++)
		printf("%d", z[i]);

	getch();
}
