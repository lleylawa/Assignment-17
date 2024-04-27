**Project Overview:**
This project implements Run-Length Encoding (RLE) for compression and decompression of text files. Run-Length Encoding is a simple form of data compression where consecutive repeated characters are replaced by a single character followed by the count of its repetitions.

**1) Compression Algorithm (Run-Length Encoding - RLE):**
Compression Function (RunLengthEnc):

Input: Takes a string str to be compressed and an output file stream outputFile.
Algorithm: Iterates through the input string. Counts consecutive occurrences of each character and writes the character followed by its count to the output file.

**2) Decompression Algorithm:**
Decompression Function (RunLengthDecr):

Input: Takes a string str to be decompressed and an output file stream outputFile.
Algorithm: Parses the input string, reading characters and their repetition counts. Writes each character the specified number of times to the output file.

**Major Functions:**
RunLengthEnc: Performs Run-Length Encoding on a given input string.
RunLengthDecr: Performs Run-Length Decoding on a given input string.
main: Controls the flow of the program, handles file I/O, user input, and calls the appropriate encoding or decoding function based on user choice.
**Code Blocks:**
File I/O Handling: Opens input and output files, checks for successful opening.
User Interface: Displays a menu for the user to choose between compression and decompression.
Encoding and Decoding: Calls the appropriate function based on the user's choice and processes each line of the input file accordingly.
Error Handling: Checks for invalid user input and displays an error message.

**Example usage:**
To compress data:

1. Prepare the data to be compressed and save it in a file named `inputfile.txt`.
2. Compile the program and execute it.
3. When prompted, choose the compression option by typing `1`.
4. The compressed data will be saved in a file named `outputfile.txt`.

To decompress data:

1. Place the compressed data in a file named `inputfile.txt`.
2. Compile and run the program.
3. Select the decompression option when prompted by typing `2`.
4. The decompressed data will be stored in a file named `outputfile.txt`.
