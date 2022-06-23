# minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.

## Description
### Mendatory Part
This project is to create a communication program in the form of a client and a server.
- The server must be started first. After its launch, it has to print its PID.
-  The client takes two parameters:
	- The server PID.
	- The string to send.
- The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
- The server has to display the string pretty quickly. (1 second for displaying 100 characters is way too much!)
- The server should be able to receive strings from several clients in a row without needing to restart.
- The communication between the client and the server has to be done only using UNIX signals.
- UNIX signals are limited to these two signals: SIGUSR1 and SIGUSR2.
### Bonus Part
- The server acknowledges every message received by sending back a signal to the client.
- The program must handle unicode characters.
## Technologies
* C
* Makefile
* UNIX signals
