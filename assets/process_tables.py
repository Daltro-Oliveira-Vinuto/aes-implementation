
input_name = input("Enter input name: ");

file = open(input_name,"r");

lines = file.readlines();
file.close();


new_lines = []

for line in lines:
	new_line = line.split(" "); 
	new_lines.append(new_line);

#print(new_lines);

final_lines = []
for line in new_lines:
	new_line = [];
	for value in line:
		new_value = "0x"+value
		new_line.append(new_value);
	final_lines.append(new_line);

print(final_lines);

output_file_path = "new_"+input_name;

new_file = open(output_file_path,"w");

for line in final_lines:
	new_file.write("{ ");
	for value in line:
		if (value != line[line.__len__()-1]):
			new_file.write(value);
			new_file.write(" , ");
		else:
			new_value = value.replace("\n", " },\n");
			new_file.write(new_value);



new_file.close();

import os 

os.system("subl "+ output_file_path);




































