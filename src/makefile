web_server:main.o HTTPServer.o HTTPRequest.o HTTPGetRequest.o HTTPResponse.o IoWriter.o
	g++ -o web_server main.o HTTPServer.o HTTPRequest.o HTTPGetRequest.o HTTPResponse.o IoWriter.o 
 main.o:main.cpp server.h
	g++ -c -g   main.cpp
HTTPServer.o:HTTPRequest.cpp server.h
	g++ -c -g    HTTPServer.cpp
HTTPRequest.o:HTTPRequest.cpp HTTPRequest.h
	g++ -c -g    HTTPRequest.cpp
IoWriter.o:IoWriter.h
	g++ -c -g   IoWriter.cpp
HTTPGetRequest.o:HTTPGetRequest.cpp HTTPGetRequest.h
	g++ -c -g   HTTPGetRequest.cpp
HTTPResponse.o:HTTPResponse.h ERRORHEAD.h
	g++ -c -g  HTTPResponse.cpp
clean:
	rm -rf *.o
