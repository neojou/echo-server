echo-server: echo-server.c
#	gcc echo-server.c -o echo-server
	kotlinc EchoServer.kt -include-runtime -d EchoServer.jar

clean:
#	rm -f echo-server
	rm -f EchoServer.jar

