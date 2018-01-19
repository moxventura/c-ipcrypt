
IPCrypt (portable C implementation)
===================================

A portable C implementation of ipcrypt, a 32-bit block cipher that can
be used to "anonymize" IP addresses in log files.

The cipher was designed by Jean-Philippe Aumasson.

Reference implementation in Python: [ipcrypt](https://github.com/veorq/ipcrypt).

Commandline tools
=================

Usage: 

    encrypt [key]
Encrypts all ip adresses found in stdin with [key]. If no key is provided a random 16 character key is used.


    decrypt key
Decrypts all ip adresses found in stdin using key

