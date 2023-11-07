#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

#include "aes.h"
#include "support.h"


int main(int argc, char **argv) {
	bool success;
	std::string file_input_path, file_output_path;

	success = read_arguments(argc, argv, file_input_path, file_output_path);

	if (success) {
		std::cout << "input_file_path: " << file_input_path << std::endl;
		std::cout << "output_file_path: " << file_output_path << std::endl;

		std::vector<unsigned char> input_data;
		std::vector<unsigned char> output_data;

		bool success = read_input_file(file_input_path, input_data);

		std::string key = "1234567891234567";

		AES aes = AES(key);

		aes.encrypt(input_data, output_data);
		aes.decrypt(output_data, input_data);

		std::vector<unsigned char> state1 = {0x19,0x19,0x19,0x19,
											0x19,0x19,0x19,0x19,
										    0x19,0x19,0x19,0x19,
										    0x19,0x19,0x19,0x19};


	    std::vector<unsigned char> state2 = {0xd4,0xd4,0xd4,0xd4,
	    									 0xd4,0xd4,0xd4,0xd4,
	    									 0xd4,0xd4,0xd4,0xd4,
	    									 0xd4,0xd4,0xd4,0xd4};

		std::string encrypt = "encryption";
		std::string decrypt = "decryption";
		aes.byte_substitution(state1, encrypt);
		print_vector(state1);

		aes.byte_substitution(state2, decrypt);
		print_vector(state2);

		std::vector<unsigned char> state3 = {0x1,0x2,0x3,0x4,
											0x5,0x6,0x7,0x8,
											0x9,0x10,0x11,0x12,
										    0x13,0x14,0x15,0x16};


		aes.shift_row(state3, encrypt);
		print_vector(state3);
		aes.shift_row(state3, decrypt);
		print_vector(state3);

		aes.add_round_key(state3, 0);
		print_vector(state3);

		state3[0] = 0xd4; state3[1] = 0xbf; state3[2] = 0x5d, state3[3] = 0x30;
		aes.mix_column(state3, encrypt);
		print_vector(state3);

	} else {
		printf("Error! Enter input and output file!\n");
	}



	return 0;
}