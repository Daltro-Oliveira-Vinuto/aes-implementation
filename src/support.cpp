#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "support.h"


bool read_input_file(const std::string& file_input,
					std::vector<unsigned char>& input_data) {
	bool success = false;

	FILE* fp = fopen(file_input.c_str(), "rb");

	if (fp != NULL) {

		unsigned char byte_value;

		fseek(fp, 0, SEEK_SET);

		while(fread(&byte_value, 1, 1, fp) != 0) {
			input_data.push_back(byte_value);
		}

		fclose(fp);

		success = true;
	}

	return success;
}

bool write_output_file(const std::string& file_output,
					const std::vector<unsigned char>& input_data) {
	bool success = false;



	return success;
}



bool read_arguments(int argc, char **argv, 
				  std::string& input_file,
				  std::string& output_file) {

	bool success = false;

	if (argc < 3) {
		success = false;
		printf("Error! Number of arguments is invalid!\n");
	} else  {
		input_file = argv[1];
		output_file = argv[2];
		success = true;
	}



	return success;
}


void print_vector(const std::vector<unsigned char>& data) {
	for(unsigned i = 0; i < data.size(); i++) {
		printf("%x ", data[i]);
		
	}

	std::cout << std::endl;
	/*
	std::cout << std::endl;
	for(unsigned i = 0; i < data.size(); i++) {
		printf("%c", data[i]);
		std::cout << " , ";
	}
	*/

	std::cout << std::endl;
}