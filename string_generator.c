#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 26

void init_char_array(char (*char_array)[26], unsigned short length, char start_byte) {
	unsigned short i;
	for (i = 0; i < length; i++) {
		(*char_array)[i] = start_byte++;
	}
}

void fill_remaining_array(char (*char_array)[26], unsigned short length) {
	for (length; length < MAX_CHARS; length++) {
		(*char_array)[length] = '\0';
	}
}

char * generate_random(char arrays[3][26], unsigned short lengths[3], unsigned short length) {
	char *rand_string = malloc(length);
	unsigned short i, j, rand_arr, rand_char;
	for (i = 0; i < length; i++) {
		rand_arr = rand() % 3;
		rand_char = rand() % lengths[rand_arr];
		rand_string[i] = arrays[rand_arr][rand_char];
	}
	return rand_string;
}

void main(int argc, char *argv[]) {
	/*	Local Variables	*/
	srand(time(NULL));
	char arrays[3][26];
	unsigned short i = 0, j = 0, arr_len;
	unsigned short str_len, num_str;
	unsigned short lengths[3] = {10, 26, 26};
	char start_bytes[3] = {0x30, 0x61, 0x41};

	if (argc == 2) {
		str_len = atoi(argv[1]);
		num_str = 1;
	} else if (argc == 3) {
		str_len = atoi(argv[1]);
		num_str = atoi(argv[2]);
	} else {
		str_len = 14;
		num_str = 1;
	}


	for (i = 0; i < 3; i++) {
		arr_len = lengths[i];
		init_char_array(&arrays[i], arr_len, start_bytes[i]);
		if (arr_len < MAX_CHARS) {
			fill_remaining_array(&arrays[i], arr_len);
		}
	}

	char *rand_str;
	for (i = 0; i < num_str; i++) {
		rand_str = generate_random(arrays, lengths, str_len);
		printf("%s\n\n", rand_str);
		free(rand_str);
	}
}