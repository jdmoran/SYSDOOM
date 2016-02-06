# SYSDOOM
Dr. Doom's own programming language, inspired by Unbeatable Squirrel Girl issue #4

Reference:
http://imgur.com/58fquaD

Rather than mimic that directly I'm going to base this off Cow (http://esolangs.org/wiki/COW), which it itself a variant of Brainfuck (http://esolangs.org/wiki/Brainfuck).
I wrote a Brainfuck interpreter for shits'n'giggles back in college so I'm going to re-use that because I'm a lazy git.

Instructions:
doom (0)  - Connected to DOOM. This instruction searches the program backwards looking for a DOOM instruction and begins executing from there. Note that the instruction immediately prior to this is skipped in the search.

dooM (1)  - If no current value in register, copy current memory block value. If there is a value in the register, paste that value into the current memory block and clear ther register. 

doOm (2)  - Moves current memory position forward one block

doOM (3)  - Print value of current memory block to STDOUT as an integer. 

dOom (4)  - Moves current memory position back one block

dOoM (5)  - Read an integer from STDIN and put it into the current memory block

dOOm (6)  - Set current memory block to 0.

dOOM (7)  - Execute value in current memory block as if it were an instruction. The command executed is based on the code value (for example, 2 is executed as a doOm instruction). An invalid command exits the program. A value of 7 (dOOM) is invalid as it would cause an infinite loop.

Doom (8)  - If current memory block has a 0, read a single ASCII character from STDIN and store it in the current block. If the current memory block is not 0, then print the ASCII character that corresponds to that value to STDOUT.

DooM (9)  - CURRENTLY NOTHING - suggestions?

DoOm (10) - Increment value at current memory block

DoOM (11) - CURRENTLY NOTHING - suggestions?

DOom (12) - Decrement value at current memory block

DOoM (13) - CURRENTLY NOTHING - suggestions?

DOOm (14) - CURRENTLY NOTHING - suggestions?

DOOM (15) - Connected to doom. If the current memory block value is 0, skip next instruction and resume execution after the next doom instruction. If current memory block is not 0, continue with next instruction. 
