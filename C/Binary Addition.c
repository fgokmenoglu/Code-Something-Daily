/*
 * Implement a function that adds two numbers together and returns their sum in binary. The conversion can be done before, or after the addition.
 * 
 * The binary number returned should be a string.
 * 
 * Examples:(Input1, Input2 --> Output (explanation)))
 * 
 * 1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
 * 5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary)
 */
typedef unsigned long long ull;

unsigned bitlen (ull n) {
	return (n == 0) ? 0 : (1 + bitlen(n >> 1));
}

char *binary_add (unsigned a, unsigned b, char *binary) {
	ull sum = (ull)a + (ull)b;
	unsigned length = (sum == 0) ? 1 : bitlen(sum);

	for (int i = length - 1; i >= 0; i--) {
		binary[i] = '0' + (sum & 1);
		sum >>= 1;
	}
	
	binary[length] = '\0';
	return binary;
}
