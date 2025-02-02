![Alt text](nothing/success.png)

# Minitalk :
is a project often associated with coding curricula like 42 or similar programming challenges. Its goal is to develop a simple client-server communication program using Unix signals. Here's a brief description of the project:

## Overview
Minitalk involves two main programs:

### Server: A program that runs continuously and listens for messages from the client.
### Client: A program that sends messages (such as strings) to the server.
The communication between the client and server is handled using Unix signals:

SIGUSR1 (Signal User 1)
SIGUSR2 (Signal User 2)

## Goals
Create a server program that starts by printing its PID (Process ID).
The client program takes two arguments:
The server's PID.
The string to send to the server.
The client sends the string to the server bit by bit using Unix signals.
The server reconstructs the string and displays it on the standard output.

## Requirements
Use only system calls allowed by the project (e.g., write, malloc, free, kill, signal/sigaction, pause, usleep, getpid).
Handle errors and edge cases such as invalid PIDs or empty strings.
Support the transmission of Unicode characters.

## Key Learning Points
Signal handling in Unix/Linux.
Converting data to binary and transmitting it bit-by-bit.
Managing synchronization between two processes.
Error handling and robustness in inter-process communication.
Would you like help starting your minitalk project, such as crafting the server and client code? Or do you need more detailed explanations about specific parts?
