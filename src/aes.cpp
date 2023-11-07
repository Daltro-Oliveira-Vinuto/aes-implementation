#include "aes.h"
#include <stdio.h>
#include <iostream>


AES::AES(const std::string& key) {
	printf("class AES started!\n");

	for(unsigned i = 0; i < key.size(); i++) {
		this->key.push_back(key[i]);
	}

	expand_key(this->key);
}

void AES::encrypt(const std::vector<unsigned char>& input_data,
				 std::vector<unsigned char>& output_data) {

}

void AES::decrypt(const std::vector<unsigned char>& input_data,
				 std::vector<unsigned char>& output_data) {

}

void AES::byte_substitution(std::vector<unsigned char>& state,
				   const std::string& option) {
	/*
	for(unsigned i = 0; i < 16; i++) {
		for(unsigned j = 0; j < 16; j++) {
			printf("%x ", this->s_box[i][j]);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	*/

	std::vector<unsigned char> aux_state = {};

	for(unsigned i = 0; i < state.size(); i++) {
		unsigned char value = state[i];

		unsigned int row, column;

		row = value / 16;
		column = value % 16;

		unsigned char new_value;

		if (option == "encryption") {
			new_value = this->s_box[row][column];
		} else if (option == "decryption") {
			new_value = this->s_box_inverse[row][column];
		}

		aux_state.push_back(new_value);
	}

	state.assign(aux_state.begin(), aux_state.end());


}

void AES::shift_row(std::vector<unsigned char>& state,
	               const std::string& option) {

	unsigned char matrix_state_input[4][4];
	unsigned char matrix_state_output[4][4];

	line_to_matrix(state, matrix_state_input);

	for(unsigned int i = 0; i < 4; i++) {
		for(unsigned int j = 0; j < 4; j++) {
			unsigned int next_index;

			if (option == "encryption") {
				next_index = (j+i)%4;
			} else if (option == "decryption") {
				int aux_index = (j-i)%4;
				if (aux_index >= 0) {
					next_index = aux_index;
				} else {
					next_index = aux_index+4;
				}

			}
			matrix_state_output[i][j] = matrix_state_input[i][next_index];
		}
	}


	matrix_to_line(matrix_state_output, state);
}


void AES::mix_column(std::vector<unsigned char>& state,
					const std::string& option) {

	unsigned char matrix_state_input[4][4], matrix_state_output[4][4];

	line_to_matrix(state, matrix_state_input);


	for(unsigned int i = 0; i < 4; i++) {
		unsigned char array_aux[4] = {};

		for(unsigned int j = 0; j < 4; j++) {
			for(unsigned int k = 0; k < 4; k++) {
				array_aux[k] = matrix_encrypt[i][k]*matrix_state_input[k][j];
			}
			matrix_state_output[i][j] = 
			array_aux[0]^array_aux[1]^array_aux[2]^array_aux[3];
		}

	}


	matrix_to_line(matrix_state_output, state);

}

void AES::add_round_key(std::vector<unsigned char>& state, 
						unsigned round) {

	for(unsigned int i = 0; i < 16; i++) {
		state[i] = state[i]^(this->expanded_key[round*16 + i]);
	}

}

void AES::expand_key(const std::vector<unsigned char>& key) {

	for(unsigned int i = 0; i < key.size(); i++) {
		expanded_key.push_back(key[i]);
	}

}

void AES::line_to_matrix(const std::vector<unsigned char>& line,
					   unsigned char matrix_state[4][4]) {

	for(unsigned i = 0; i < 4; i++) {
		unsigned start = i;
		for(unsigned j = 0; j< 4; j++) {
			matrix_state[i][j] = line[start];
			start+= 4;
		}
	}

}

void AES::matrix_to_line(const unsigned char matrix_state[4][4],
						std::vector<unsigned char>& line) {

	for(unsigned i = 0; i < 4; i++) {
		unsigned start = i;
		for(unsigned j = 0; j < 4; j++) {
			line[start] = matrix_state[i][j];
			start+= 4;

		}
	}

}






















