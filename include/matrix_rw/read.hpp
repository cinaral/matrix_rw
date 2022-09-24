#ifndef READ_HPP_CINARAL_220924_0017
#define READ_HPP_CINARAL_220924_0017

#include "types.hpp"
#include <fstream>
#include <iostream>
#include <string>

namespace matrix_rw
{
template <uint_t N_ROW, uint_t M_COL>
void
read(const std::string file_name, real_t (&matrix)[N_ROW * M_COL])
{
	std::ifstream file;
	file.open(file_name);

	if (file.is_open()) {
		std::string line;
		std::string entry;
		size_t str_pos = 0;

		for (uint_t i = 0; i < N_ROW; i++) {
			if (std::getline(file, line)) {
				entry = line.substr(0, line.find(delimiter));

				//* parse the line by splitting at the delimiters
				for (uint_t j = 0; j < M_COL; j++) {
					if ((str_pos = line.find(delimiter)) != std::string::npos) {
						entry = line.substr(0, str_pos);
						line.erase(0, str_pos + delimiter.length());
#ifdef __USE_SINGLE_PRECISION__
						matrix[i * M_COL + j] = std::stof(entry);
#else
						matrix[i * M_COL + j] = std::stod(entry);
#endif
					} else {
#ifdef __USE_SINGLE_PRECISION__
						matrix[i * M_COL + j] = std::stof(line);
#else
						matrix[i * M_COL + j] = std::stod(line);
#endif
					}
				}
			} else {
				break;
			}
		}
	} else {
		std::cerr << "Could not open file " << file_name << std::endl;
	}
	file.close();
}

} // namespace matrix_rw

#endif