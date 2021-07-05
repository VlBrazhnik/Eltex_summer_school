#include <stdio.h>

int main() {

	int a = 0xCCDDAABB;
	int b = 0x00CCAABB;
	unsigned char one_bit;

	//Output each bite of a
	for (int i = 0; i < sizeof(typeof(a)); i++) {
	    one_bit = (a & 0xFF);
	    printf("%d bit of a = %X\n", i, one_bit);
	    a = a >> 8;
	}

	//change third byte of b
	printf("before b = 0x00%X\n", b);
	b^= 0x22 << 8;
	printf(" after b = 0x00%X\n", b);

	return 0;
}
