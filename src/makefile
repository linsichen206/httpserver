web_server:main.o HTTPServer.o HTTPRequest.o HTTPGetRequest.o HTTPResponse.o IoWriter.o
	g++ -o web_server main.o HTTPServer.o HTTPRequest.o HTTPGetRequest.o HTTPResponse.o IoWriter.o 
 main.o:main.cpp server.h
	g++ -c  main.cpp
HTTPServer.o:HTTPRequest.cpp server.h
	g++ -c  HTTPServer.cpp
HTTPRequest.o:HTTPRequest.cpp HTTPRequest.h
	g++ -c  HTTPRequest.cpp
IoWriter.o:IoWriter.h
	g++ -c IoWriter.cpp
HTTPResponse.o:HTTPResponse.h ERRORHEAD.h
	g++ -c -g HTTPResponse.cpp
clean:
	rm -rf *.o
