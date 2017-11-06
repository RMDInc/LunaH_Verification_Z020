/*
Notes:
	- for the SD card functions, the idea is to go through the set of functions and use the ffs_res (fat file system result)
		variable to check the return value of the function in question.
	- error checking code is left to the user
	- if variables are needed to be declared, they will be put above the  functions being tested.

*/

1.) Mounting correctly
FATFS fatfs;					//initialize a FAT file system
int ffs_res = 0;				//return variable for the SD card functions

ffs_res = f_mount(0, NULL);		//unmounts anything that is currently mounted
ffs_res = f_mount(0, &fatfs);	//mount a card at physical drive “0” or “0:”

------------------------

2.) Unmounting correctly
FATFS fatfs;					
int ffs_res = 0;				

ffs_res = f_mount(0, NULL);		//unmounts anything that is currently mounted
ffs_res = f_mount(0, &fatfs);	//mount a card at physical drive “0” or “0:”
ffs_res = f_mount(0, NULL);		//un-mount the SD card

------------------------

3.) Successfully opening a .txt file (pre-made)
FATFS fatfs;
FIL file1;
int ffs_res = 0;
char cEventFileName[] = “file1.txt”;	//name of the file being accessed

…mount…							//go through the mounting done previously

//open "file1.txt" with read/write access, open the file if it exists, otherwise create a new file
Ffs_res = f_open(&file1, cEventFileName, FA_OPEN_ALWAYS | FA_WRITE);	

------------------------

4.) Successfully close a .txt file (pre-made)
FATFS fatfs;
FIL file1;
int ffs_res = 0;
char cEventFileName[] = “file1.txt”;

…mount…	

Ffs_res = f_open(&file1, cEventFileName, FA_OPEN_ALWAYS | FA_WRITE);	//open "file1.txt" 
Ffs_res = f_close(&file1);		//close "file1.txt" 

------------------------

5.) Successfully read from a (pre-made) .txt file
FATFS fatfs;
FIL file1;
int ffs_res = 0;
char cEventFileName[] = “file1.txt”;
char cReadBuffer[100] = "";		//a large buffer to read to

…mount…	

Ffs_res = f_open(&file1, cEventFileName, FA_OPEN_ALWAYS | FA_WRITE);	//open "file1.txt"
//give f_read the address of the read buffer and the size of that buffer 
ffs_res = f_read(&file1, &(cReadBuffer[0]), 100, &numBytesWritten);		//read from the file


------------------------

6.) Successfully write to a (pre-made) .txt file
FATFS fatfs;
FIL file1;
int ffs_res = 0;
char cEventFileName[] = “file1.txt”;
char cMessage[] = "message123";

…mount…	

Ffs_res = f_open(&file1, cEventFileName, FA_OPEN_ALWAYS | FA_WRITE);	//open "file1.txt" 
ffs_res = f_write(&file1, cMessage, sizeof(cMessage), &numBytesWritten);	//write a small char array to the file

------------------------

7.) Successfully create a new .txt file (same as open, but using a new file name)
FATFS fatfs;
FIL file1;
int ffs_res = 0;
char cEventFileName[] = “new_file.txt”;	//name of the file being accessed

…mount…							//go through the mounting done previously

//open "file1.txt" with read/write access, open the file if it exists, otherwise create a new file
Ffs_res = f_open(&file1, cEventFileName, FA_OPEN_ALWAYS | FA_WRITE);	

------------------------

8.) Successfully open a (pre-made) binary file
FATFS fatfs;
FIL file1;
int ffs_res = 0;
char cEventFileName[] = “file1.bin”;	//name of the file being accessed

…mount…							//go through the mounting done previously

//open "file1.txt" with read/write access, open the file if it exists, otherwise create a new file
Ffs_res = f_open(&file1, cEventFileName, FA_OPEN_ALWAYS | FA_WRITE);

------------------------

9.) Successfully close a .bin file (pre-made)
FATFS fatfs;
FIL file1;
int ffs_res = 0;
char cEventFileName[] = “file1.bin”;

…mount…	

Ffs_res = f_open(&file1, cEventFileName, FA_OPEN_ALWAYS | FA_WRITE);	//open "file1.bin" 
Ffs_res = f_close(&file1);		//close "file1.bin" 