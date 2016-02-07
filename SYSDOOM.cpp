/*
 * SYSDOOM
 * 
 * github.com/jdmoran/SYSDOOM
 *
 * Inspired by Ryan North's Unbeatable Squirrel Girl #4
 * Please don't sue me, Mr. North and/or Marvel Comics.
 *
 * See README.md for language reference.
 *
 * License: GPL v2
 */

#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// Global variables
vector<uint8_t> program;
vector<uint8_t> memory;
vector<uint8_t>::iterator prog_counter;
vector<uint8_t>::iterator mem_pos; 
 
uint8_t prog_register;
bool register_valid;
 
 
// Execute the current instruction
void Execute_Instruction(uint8_t instr)
{
	//printf("Executing instruction %d\n", instr);
	
	switch (instr)
	{
		case  0: // doom
		{
			if(prog_counter == program.begin())
			{
                exit(EXIT_FAILURE);
			}

            prog_counter--;	// skip previous command.
			
            int level = 1;
            while(level > 0)
            {
                if(prog_counter == program.begin())
				{
                    break;
				}

                prog_counter--;
            
                if((*prog_counter) == 0)
				{
                    level++;
				}
                else if((*prog_counter) == 7)
				{
                    level--;
				}
            }

            if(level != 0)
			{
                exit(EXIT_FAILURE);
			}

            Execute_Instruction(*prog_counter);
			break;
		}
		case  1: // dooM
		{
			if(register_valid == false)
			{
				prog_register = *mem_pos;
				register_valid = true;
			}
			else
			{
				*mem_pos = prog_register;
				register_valid = false;
			}
			
			break;
		}
		case  2: // doOm
		{
			mem_pos++;
			if(mem_pos == memory.end())
			{
				memory.push_back(0);
				mem_pos = memory.end();
				mem_pos--;
			}
			break;
		}	
		case  3: // doOM
		{
			int val = *mem_pos;
			cout << val;
			break;
		}	
		case  4: // dOom
		{
			if(mem_pos == memory.begin())
			{
				exit(EXIT_FAILURE);
			}
			else
			{
				mem_pos--;
			}
			break;
		}
		case  5: // dOoM
		{	
			int val;
			cin >> val;
			
			*mem_pos = val;
			
			break;
		}
		case  6: // dOOm
		{
			*mem_pos = 0;
			break;
		}
		case  7: // dOOM
		{
			if(*mem_pos == 7)
			{
				exit(EXIT_FAILURE);
			}
			
			Execute_Instruction(*mem_pos);
			
			break;
		}	
		case  8: // Doom
		{
			char val;
			if(*mem_pos == 0)
			{
				cin >> val;
				*mem_pos = val;
			}
			else
			{
				val = *mem_pos;
				cout << val;
			}
			
			break;
		}
		case  9: // DooM
			; // DO NOTHING
			break;
			
		case 10: // DoOm
			(*mem_pos)++;
			break;
			
		case 11: // DoOM
			; // DO NOTHING
			break;
			
		case 12: // DOom
			(*mem_pos)--;
			break;
			
		case 13: // DOoM
			; // DO NOTHING
			break;
			
		case 14: // DOOm
			; // DO NOTHING
			break;
			
		case 15: // DOOM
		{
			if((*mem_pos) == 0)
			{
				int level = 1;
				int prev = 0;
				prog_counter++;	  // have to skip past next command when looking for next doom.
				if(prog_counter == program.end())
				{
					break;
				}
				while(level > 0)
				{
					prev = *prog_counter;
					prog_counter++;
					
					if(prog_counter == program.end())
					{
						break;
					}
					
					if((*prog_counter) == 7)
					{
						level++;
					}
					else if((*prog_counter) == 0)
					{
						level--;
						if(prev == 7)
						{
							level--;
						}
					}
				}
				if(level != 0)
				{
					exit(EXIT_FAILURE);
				}
			}
			break;
		}
		default:
			exit(EXIT_FAILURE);
			break;
	}
	
	prog_counter++;
 }
 
 
int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "Usage: " << argv[0] << " program.doom" << endl;
		exit(EXIT_FAILURE);
	}

	ifstream source_file(argv[1]);
	
	if(source_file.is_open() == false)
	{
		cout << "Cannot open source file " << argv[1] << endl;
        
		exit(EXIT_FAILURE);
	}
	
	string line;
	vector<string>tokens;
	
	while(getline(source_file, line))
	{
		istringstream iss(line);
		
		copy(istream_iterator<string>(iss),
			 istream_iterator<string>(),
			 back_inserter(tokens));
		
		for(vector<string>::iterator t = tokens.begin(); t != tokens.end(); t++)
		{
			if(*t == "doom")
			{
				program.push_back(0);
			}
			else if(*t == "dooM")
			{
				program.push_back(1);
			}
			else if(*t == "doOm")
			{
				program.push_back(2);
			}
			else if(*t == "doOM")
			{
				program.push_back(3);
			}
			else if(*t == "dOom")
			{
				program.push_back(4);
			}
			else if(*t == "dOoM")
			{
				program.push_back(5);
			}
			else if(*t == "dOOm")
			{
				program.push_back(6);
			}
			else if(*t == "dOOM")
			{
				program.push_back(7);
			}
			else if(*t == "Doom")
			{
				program.push_back(8);
			}
			else if(*t == "DooM")
			{
				program.push_back(9);
			}
			else if(*t == "DoOm")
			{
				program.push_back(10);
			}
			else if(*t == "DoOM")
			{
				program.push_back(11);
			}
			else if(*t == "DOom")
			{
				program.push_back(12);
			}
			else if(*t == "DOoM")
			{
				program.push_back(13);
			}
			else if(*t == "DOOm")
			{
				program.push_back(14);
			}
			else if(*t == "DOOM")
			{
				program.push_back(15);
			}
		}
		
		tokens.clear();
	}
	
	source_file.close();
	
	prog_register  = 0;
	register_valid = false;

	memory.push_back(0);
	mem_pos = memory.begin();
	
	prog_counter = program.begin();
	
	while(prog_counter != program.end())
	{
		Execute_Instruction(*prog_counter);
	}
 
	return 0;
}
