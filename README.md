**Project Documentation: Run-Length Encoding (RLE) Compression and Decompression**

**1. Introduction:**
This project implements a simple Run-Length Encoding (RLE) algorithm in C++ for compression and decompression of text files. RLE is a lossless data compression technique that works by reducing the size of repetitive sequences of data.

**2. Compression Algorithm:**
The compression algorithm (`RunLengthEnc`) iterates through the input string. For each character, it counts the number of consecutive occurrences of that character. It then writes the character and its count to the output file. For example, the string "AAAABBBCCDAA" would be compressed to "A4B3C2D1A2".

**3. Decompression Algorithm:**
The decompression algorithm (`RunLengthDecr`) reads pairs of characters from the input string, interpreting them as a character followed by its count. It then writes the character repeated according to its count to the output file. For example, the compressed string "A4B3C2D1A2" would be decompressed to "AAAABBBCCDAA".

**4. Major Functions:**
- `RunLengthEnc(const string& str, ofstream& outputFile)`: Performs RLE compression on the input string and writes the compressed data to the output file.
- `RunLengthDecr(const string& str, ofstream& outputFile)`: Performs RLE decompression on the input string and writes the decompressed data to the output file.
- `main()`: Entry point of the program. Handles file I/O, user input for compression or decompression, and calls the appropriate function based on the user's choice.

**5. Code Blocks:**
- File I/O: Opens input and output files, checks for successful opening.
- User Input: Prompts the user to choose compression or decompression.
- Compression/Decompression: Calls the respective function (`RunLengthEnc` or `RunLengthDecr`) to process each line of the input file.
- Error Handling: Checks for invalid user input and file opening failures.


**6. How to Compile and Run:**
- To compress data:

Prepare the data to be compressed and save it in a file named inputfile.txt.
Compile the program and execute it.
When prompted, choose the compression option by typing 1.
Follow the on-screen instructions to input the text you want to compress.
The compressed data will be saved in a file named outputfile.txt.
- To decompress data:

Place the compressed data in a file named inputfile.txt.
Compile and run the program.
Select the decompression option when prompted by typing 2.
Follow the instructions to input the compressed text.
The decompressed data will be stored in a file named outputfile.txt.
