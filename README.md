# Echo Server

A simple TCP echo server written in Kotlin. This server listens on a specified port (default is 5001 if not provided) and echoes back any text sent by a client connected via tools like `telnet`. It includes a shell script to simplify running the server with an optional port parameter.

## Features
- Listens on a configurable TCP port (default: 5001)
- Echoes back any text received from clients
- Supports multiple sequential client connections
- Built with Kotlin and runs on the JVM
- Includes a shell script for easy execution on macOS/Linux

## Prerequisites
- [Java Runtime Environment (JRE)](https://www.oracle.com/java/technologies/javase-jre8-downloads.html) (version 8 or higher)
- [Kotlin Compiler](https://kotlinlang.org/docs/command-line.html) (for building from source)
- A Unix-like environment (macOS, Linux, etc.) for the shell script

## Installation

1. **Clone the Repository**
   ```bash
   git clone https://github.com/neojou/echo-server.git
   cd echo-server

2. **Compile the Kotlin Code**
   Ensure you have kotlinc installed. Then run:
   ```bash
   kotlinc EchoServer.kt -include-runtime -d EchoServer.jar

   or there is a Makefile, you can just type
   ```bash
   make

   This generates a standalone JAR file EchoServer.jar

3. **Make the Shell Script Executablei**
   ```bash
   chmod +x run-echo-server.sh

## Usage
**Running the server**
- With Default Port (5001):
```bash
./run-echo-server.sh

- With a Custom Port (e.g. 6000):
```bash
./run-echo-server.sh 6000

**Testing the Server**
1. Start the server in one terminal:
```bash
./run-echo-server.sh 6000

You'll see: Echo server is listening on port 6000...

2. Connect to the server using telnet in another terminal:
```bash
telnet localhost 6000

3. Type any text and press Enter. The server will echo it back.

4. To disconnet, press Ctrl+C in the telnet terminal. The server will continue running and wait for new connections.

**Stopping the Server**
Press Ctrl+C in the terminal running the server to stop it.

## Files
- EchoServer.kt : The main Kotlin source code for the echo server.
- run-echo-server.h : A shell script to run the server with an optional port parameter.
- EchoServer.jar : The compiled JAR file (generated after compilation)
- echo_server.c : The C file only for reference. It won't be compiled. 

## Notes
- The port must be a number between 1 and 65535. Invalid ports will fall back to 5001 (handled in the Kotlin code).
- The server handles one client at a time. For concurrent clients, additional threading would be needed.
- Ensure the port you choose is not already in use on your system.

## Buliding from Source
If you modify EchoServer.kt, recompile it.

## License
This project is licensed under the Apache license 2.0 - see the LICENSE file for details.

## Contributing
Feel free to submit issues or pull requests if you have suggestions or improvements!


