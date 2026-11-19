Overview
This project implements a binary file reader and statistical analyzer in C++. The program reads a dataset containing hospital patient records from diabetic_data.bin, processes the binary data using a custom structure, and calculates summary statistics across the dataset.

The assignment focuses on low-level binary file I/O, structured data parsing, and statistical aggregation in C++.

Features
Binary File Reading: Opens and reads diabetic_data.bin using a binary input stream (ifstream).

Structured Data Parsing: Uses a custom DiabeticRecord structure to match the binary layout of each record.

Record Counting: Tracks the total number of records successfully processed.

Maximum Identifiers: Finds the maximum encounter ID and patient number.

Statistical Analysis: Calculates the average values of 11 numerical fields.

Formatted Output: Displays the dataset summary with averages rounded to two decimal places.

Dataset
The program uses the Diabetes 130-US Hospitals for Years 1999–2008 dataset.

Original dataset: https://archive.ics.uci.edu/dataset/296/diabetes+130-us+hospitals+for+years+1999-2008

The binary input file must be named:

diabetic_data.bin

Place the binary file in the same directory as the compiled executable.

Compilation and Execution
Requirements
C++ compiler (G++)

C++11 or later

diabetic_data.bin dataset file

Compile

"g++ -std=c++11 binreader.cpp -o binreader"

