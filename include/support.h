
#include <string>

#ifndef SUPPORT_H
#define SUPPORT_H

bool read_input_file(const std::string& file_input,
					std::vector<unsigned char>& input_data);

bool write_output_file(const std::string& file_output,
					const std::vector<unsigned char>& input_data);

bool read_arguments(int argc, char **argv, 
				  std::string& input_file,
				  std::string& output_file);

void print_vector(const std::vector<unsigned char>& data);

#endif
