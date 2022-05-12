/*
Andrew Schmidt   03122022   Init
---------------------------------------------
Convert bin to header file. diss.bin > diss.bin.h
Store binary info as an array in a header file

*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


int main()
{

	ifstream rf("dhry.bin", ios::binary);

	printf("uint32_t instr [] = {");
	if (rf)
	{
		// Get length
		rf.seekg(0, rf.end);
		int length = rf.tellg();
		rf.seekg(0, rf.beg);

		char* buffer = new char[length];


		uint32_t num = 0;

		for (int i = 0; i < (length / sizeof(uint32_t) * 4); i++)
		{
			rf.readsome(buffer, sizeof(uint32_t) / 4);
			rf.seekg(0, rf.cur);

			//printf("%p\n", (*buffer));
			uint8_t test = (uint8_t)(*buffer);
			if (i % 4 == 0)
			{
				num += test;
			}
			else if (i % 4 == 1)
			{
				num += test << 8;
			}
			else if (i % 4 == 2)
			{
				num += test << 16;
			}
			else if (i % 4 == 3)
			{
				num += test << 24;
				printf("0x%08x,", num);
				num = 0;
			}

		}

	}
	else
	{
		std::cout << "File Wasn't oppened" << endl;
	}

	rf.close();

	printf("};");

	return 0;
}