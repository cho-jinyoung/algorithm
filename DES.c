//DES(Data encryption standard) > 대칭키 블록 암호

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 상수 정의
typedef unsigned char BYTE;
#define XOR(a, b) (a || b) && !(a && b)

 // 전치 순열이 들어가 있는 코드
BYTE ip[64] = { 58, 50, 42, 34, 26 ,18 ,10, 2,
	 60, 52, 44, 36, 28, 20, 12, 4,
	 62, 54, 46, 38, 30, 22, 14, 6,
	 64, 56, 48, 40, 32, 24, 16, 8,
	 57, 49, 41, 33, 25, 17, 9, 1,
	 59, 51, 43, 35, 27, 19, 11, 3,
	 61, 53, 45, 37, 29, 21, 13, 5,
	 63, 55, 47, 39, 31, 23, 15, 7 };

BYTE inv_ip[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
	  39, 7, 47, 15, 55, 23, 63, 31,
	  38, 6, 46, 14, 54, 22, 62, 30,
	  37, 5, 45, 13, 53, 21, 61, 29,
	  36, 4, 44, 12, 52, 20, 60, 28,
	  35, 3, 43, 11, 51, 19, 59, 27,
	  34, 2, 42, 10, 50, 18, 58, 26,
	  33, 1, 41, 9, 49, 17, 57, 25 };

// F함수 내 확장 전치 순열이 들어가 있는 코드
BYTE E[48] = { 32, 1, 2, 3, 4, 5,
	  4, 5, 6, 7, 8, 9,
	  8, 9, 10, 11, 12, 13,
	  12, 13, 14, 15, 16, 17,
	  16, 17, 18, 19, 20, 21,
	  20, 21, 22, 23, 24, 25,
	  24, 25, 26, 27, 28, 29,
	  28, 29, 30, 31, 32, 1 };

// 8개의 s_box가 들어 있는 코드 [S-box 종류][행][열]
BYTE s_box[8][4][16] = { {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
			 {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
			 {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
			 {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 2, 14, 10, 0, 6, 13}},

			{{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
			 {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
			 {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
			 {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},

			{{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
			 {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
			 {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
			 {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},

			{{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
			 {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
			 {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
			 {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},

			{{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
			 {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
			 {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
			 {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},

			{{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
			 {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
			 {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
			 {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},

			{{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
			 {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
			 {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
			 {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},

			{{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
			 {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
			 {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
			 {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}} };

//키 자리바꿈
int PC_1[56] = { 57, 49, 41, 33, 25, 17, 9,
	  1, 58, 50, 42, 34, 26, 18,
	  10, 2, 59, 51, 43, 35, 27,
	  19, 11, 3, 60, 52, 44, 36,
	  63, 55, 47, 39, 31, 23, 15,
	  7, 62, 54, 46, 38, 30, 22,
	  14, 6, 61, 53, 45, 37, 29,
	  21, 13, 5, 28, 20, 12, 4 };

//압축 자리바꿈
int PC_2[48] = { 14, 17, 11, 24, 1, 5, 3, 28,
	  15, 6, 21, 10, 23, 19, 12, 4,
	  26, 8, 16, 7, 27, 20, 13, 2,
	  41, 52, 31, 37, 47, 55, 30, 40,
	  51, 45, 33, 48, 44, 49, 39, 56,
	  34, 53, 46, 42, 50, 36, 29, 32 };

//P_box
int P_Box[32] = { 16, 7, 20, 21, 29, 12, 28, 17,
	   1, 15, 23, 26, 5, 18, 31, 10,
	   2, 8, 24, 14, 32, 27, 3, 9,
	   19, 13, 30, 6, 22, 11, 4, 25 };


// 함수 정의
void DES_Decryption(BYTE* p_text, BYTE* result, BYTE* key);
void IP(BYTE* in, BYTE* out);
void inv_IP(BYTE* in, BYTE* out);
BYTE f(BYTE *r, BYTE(*rkey)[48], int round);
void key_expansion(BYTE * key, BYTE(*round_key)[48]);
BYTE cir_shift(BYTE* n, int r);

// main 함수: 역할 적기
int main() {
	BYTE result[64] = { 0, };
	BYTE key[64] = { 0 };
	BYTE input[64] = { 0 };

	printf("암호문 입력: ");
	scanf("%s", input);
	printf("키 입력: ");
	scanf("%s", key);

	for (int i = 0; i < 64; i++) {
		input[i]=input[i] - 48;
		key[i] = key[i]-48;
	}

	DES_Decryption(input, result, key);		//Des_Encryption 함수

	getch();
	return 0;

}

// 복호화 코드
void DES_Decryption(BYTE* input, BYTE* result, BYTE* key) {
	int i, j, k, round = 0, r_count = 0;
	BYTE data[64] = { 0, };
	BYTE round_key[16][48];
	BYTE left[32] = { 0, }, right[32] = { 0, }, or_right[32] = { 0, };

	IP(input, data);                  // 초기 전치
	printf("\nIP= ");
	for (i = 0; i < 64; i++) {
		printf("%d", data[i]);
		if (i%4 == 3)	printf(" ");
	}
	key_expansion(key, round_key, round);         // 키 확장

	for (j = 0; j < 32; j++) {   // 하나의 64bit를 둘의 left, right data 로 나눈다
		left[j] = data[j];
		right[j] = data[j + 32];
	}

	for (i = 15; i >= 0; i--) {
		r_count++;
		for (j = 0; j < 32; j++)
			or_right[j] = right[j];	//원래 right값 저장

		f(right, round_key, i);		//f함수

		for (k = 0; k < 32; k++) {
			right[k] = XOR(left[k], right[k]);
		}
		for (k = 0; k < 32; k++)
			left[k] = or_right[k];

		printf("\ndecode[%d]: ", r_count);//라운드별 복호화문 출력
		for (j = 0; j < 32; j++)
			printf("%d", left[j]);	//left 32bit
		printf("  ");
		for (j = 0; j < 32; j++)
			printf("%d", right[j]);	//right 32bit
		printf("\n");
	}
	for (i = 0; i < 64; i++) {
		if (i < 32)
			data[i] = right[i];
		else if (i >= 32 && i < 64)
			data[i] = left[i-32];
	}
	for (i = 0; i < 64; i++)
		printf("%d", data[i]);

	inv_IP(data, result);                    // 마지막 전치

	printf("\n\noutput =>");
	for (i = 0; i < 64; i++) {
		printf("%d", result[i]);
		if (i % 8 == 7)printf(" ");
	}
}

// 초기 전치코드
void IP(BYTE * in, BYTE * out) {
	int i;

	for (i = 0; i < 64; i++)
		out[i] = in[ip[i] - 1];
}

// 초기 전치코드 역함수  
void inv_IP(BYTE * in, BYTE * out){
	int i;

	for (i = 0; i < 64; i++)
		out[ip[i] - 1] = in[i];
}

// F함수 코드
BYTE f(BYTE *r, BYTE (*rkey)[48], int round)   //r=right32bit, rkey=전체 라운드 키, round=현재 라운드 수
{
	int i, j, s_result;
	BYTE s_out;
	BYTE data[48];
	BYTE out[32] = { 0, }; //out=S_box 결과 값
	BYTE printstay[6];
	BYTE row, row1, row2, col, col1, col2, col3, col4;
	BYTE sbox[8];

	for (i = 0; i < 48; i++)   //EP
		data[i] = r[E[i] - 1];

	printf("\ndata==");
	for (i = 0; i < 48; i++)
		printf("%d", data[i]);

	printf("\nKS==");
	for (i = 0; i < 48; i++)
		printf("%d", rkey[round][i]);
	
	printf("\nXOR==");
	for (i = 0; i < 48; i++) {                            // 라운드 키와 xor
		data[i] = (data[i] ^ rkey[round][i]) & 0x1;
		if (i % 6 == 0)
			printf(" %d", data[i]);
		else
			printf("%d", data[i]);
	}

	for (i = 0; i < 8; i++)	{

		for (j = 0; j < 6; j++)
			printstay[j] = data[6 * i + j];

		row1 = printstay[0];
		row2 = printstay[5];
		col1 = printstay[1];
		col2 = printstay[2];
		col3 = printstay[3];
		col4 = printstay[4];

		row = (row1 << 1) | row2;
		col = (col1 << 3) | (col2 << 2) | (col3 << 1) | col4;

		sbox[i] = s_box[i][row][col];
	}

	//16진수 -> 2진수
	for (i = 0; i < 8; i++)	{
		out[i * 4 + 0] = 0x01 & (sbox[i] >> 3);
		out[i * 4 + 1] = 0x01 & (sbox[i] >> 2);
		out[i * 4 + 2] = 0x01 & (sbox[i] >> 1);
		out[i * 4 + 3] = 0x01 & (sbox[i] >> 0);
	}

	printf("\ns_box==");
	for (j = 0; j < 32; j++) {
		printf("%d", out[j]);
		if (j % 4 == 3)	printf(" ");
	}

	//P_box 전치
	for (i = 0; i < 32; i++)
	{
		r[i] = out[P_Box[i] - 1];
	}

	printf("\np_box==");
	for (j = 0; j < 32; j++) {
		printf("%d", r[j]);
		if (j % 4 == 3)	printf(" ");
	}
}

//키 확장시 left와 right나누는 함수 
void makeBit28(BYTE * L, BYTE * R, BYTE * pc1) {
	int i;
	for (i = 0; i < 56; i++)
	{
		if (i < 28)
			L[i] = pc1[i];
		else if (i >= 28 && i < 56)
			R[i - 28] = pc1[i];
	}
}
// 키 확장 코드
void key_expansion(BYTE * key, BYTE(*round_key)[48])
{
	int j, k;
	BYTE add[56] = { 0, };
	BYTE L[28] = { 0, }, R[28] = { 0, };
	BYTE pc1[56] = { 0, };

	for (int i = 0; i < 56; i++)      // 64bit를 56bit로 줄임
		pc1[i] = key[PC_1[i] - 1];

	makeBit28(&L, &R, pc1);  // 28비트씩 쪼갬  

	for (int i = 0; i < 16; i++)
	{
		cir_shift(L, i);             // 순환왼쪽쉬프트
		cir_shift(R, i);
		for (k = 0; k < 56; k++) {
			if (k < 28)
				add[k] = L[k];
			else if (k >= 28 && k < 56)
				add[k] = R[k - 28];
		}
		for (j = 0; j < 48; j++)      // 56bit 를 48bit로 줄여서 저장 - 최종 key 
			round_key[i][j] = add[PC_2[j] - 1];

		printf("\nround key[%d]:", i);
		for (j = 0; j < 48; j++)
			printf("%d", round_key[i][j]);
	}
}

// 왼쪽 순환 쉬프트 코드
BYTE cir_shift(BYTE * n, int r)
{
	int n_shift[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };   //각 라운드별 순환 횟수
	int i, j;
	BYTE temp;

	for (i = 0; i < n_shift[r]; i++)
	{
		temp = n[0];
		for (j = 1; j < 28; j++)
			n[j - 1] = n[j];
		n[27] = temp;
	}
}
