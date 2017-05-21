# mBlock Arduino Rover Extension (version 0.8)
I am a father of eight years old boy, he always ask me to build him a Robot, but why not to build it himself. He has an accepted knowlage with block programing, but mBlock is missing alot of important blocks for Arduino boards with make this task.

Rover extension aims to enable building simple Rover Robot with Arduino and mBlock, following are block types that Rover extension will implement:
* Infra-Red (IR) blocks, which will enable receive and decode IR remote signal. these blocks depend on [Arduino-IRremote] (https://github.com/z3t0/Arduino-IRremote) version 0.1, which come with Arduino IDE.

## Install
To install **Rover Extension**, open **mBlock IDE**,
* From **Extensions** menu item
* Open **Manage Extensions** (short-cut *Ctrl+shift+T*)
* Click **Available** button and search for "*Rover*"

## Build
On linux,
* > cd mblock_ext
* > build

## Infra-Red (IR) blocks
**Infra-Red (IR) blocks** provide the following blocks, 

Block | Description
----- | ------------
**Set Remote Receiver Pin ( *pin_id* )** | Configure the library to run on pin *pin_id*, should be called after **Arduion Program** block and before **forever** block
**Is Remote ( *Key_id* ) Key Pressed** | check the key with *key_id* is pressed, return boolean value (true/false), should be used within **if ... then** block in **forever** block scope
**Is Remote ( *Key_id* ) Key Released** | check the key with *key_id* press released, return boolean value (true/false), should be used within **if ... then** block in **forever** block scope

### Infra-Red (IR) Conflict
**Infra-Red (IR) blocks** functionaly depend on Arduion **Timer2**, which will conflict with the following block,
* **play tone pin ( *pin_id* ) on note ( *note* ) beat ( *beat* )**, you should not use it with **Infra-Red (IR) blocks**
* **set pwm pin ( *pin_id* ) output as ( *level* )**, don't call pwm on pin 3 or 11
