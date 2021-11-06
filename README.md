# Minitalk

![42-Badge](https://img.shields.io/badge/%C3%89cole-42SP-blue)![C-Badge](https://img.shields.io/badge/Language-C-lightgrey)[![42Unlicense](https://img.shields.io/badge/License-42Unlicense-yellowgreen)](https://github.com/gcamerli/42unlicense)

<img src="https://github.com/dpiza/resources/blob/master/imgs/Miniknock.gif?raw=true"/>


## Description

Minitalk is a communication program using UNIX signals.

## Goals

To code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later on in the 42cursus.


## Mandatory

• You must create a communication program in the form of a client and server.

• Communication between your programs should ONLY be done using UNIX signals.

• You can only use the two signals SIGUSR1 and SIGUSR2.


## Bonus

• The server confirms every signal received by sending a signal to the client.

• Support Unicode characters!


## Usage

To compile the program, run:

```
$ make
```

First, run the server and get its PID:
```
$ ./server
```
Then, run the client, providing the server PID and the string:
```
$ ./client 12345 "G'day mr server 🙃"
```

## License

This work is published under the terms of [42 Unlicense](https://github.com/gcamerli/42unlicense)