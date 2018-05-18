Name: PassBank 2.0
Author: Érick Oliveira
Date: 17/05/18
Description: Password Manager/Keeper

This program has a user scheme, where each user can save your passwords and a description for each one of them.
The data of all users is handled in encrypted files.

For a still higher level of cryptography, tesseract can be used. This is a program that will encrypt files containing user data using xor logic.

There is a program called tesseract, which will do the encryption itself and another called tesseract_launcher which is an interface for the user to decide to encrypt, decrypt or delete the entire database.


WARNINGS: 

1 - If you have decided to use PassBank together with Tesseract, you will have to encrypt the database after each use of the program.
2 - Before using PassBank, you must make sure that the database is decrypted. If not, you will need to do this with tesseract_launcher.

INSTRUCTIONS:

If you use Windows 10 64 bits: Just run the PassBank and Tesseract_launcher in dist folder.


If you use another operating system, you will have to compile the program. In case of linux, you will have to remove the windows.h library and the commands that reference it, as well as swap the macro (#define cls ...) to system ("clear") and remove the other macros that use the system reference ("").
If you want, you can change the pause macro (#define pause ...) to a command that causes the terminal to wait 60 seconds or longer to continue executing the program.

To compile it:

1 - Compile files (main.cpp, base64.cpp, process.cpp, base64.h and cripto.h) as a project with any IDE/Cpp compiler. This is the PassBank 2.0.
2 - Compile tesseract.c -- This is the encrypter. It's not used by the user, so it will not run.
3 - Compile Tessercat_launcher.c -- This is the GUI for the encrypter. This is what the user has to use to encrypt, decrypt, and delete the database.


Suggestions for improvements are welcome!  Enjoy it!