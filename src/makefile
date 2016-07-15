web_server:main.o HTTPServer.o HTTPRequest.o HTTPGetRequest.o HTTPResponse.o
	g++ -o web_server main.o HTTPServer.o HTTPRequest.o HTTPGetRequest.o HTTPResponse.o
main.o:main.cc server.h
	g++ -c main.cpp
HTTPServer.o:HTTPRequest.cpp server.h
	g++ -c HTTPServer.cpp
HTTPRequest.o:HTTPRequest.cpp HTTPRequest.h
	g++ -c HTTPRequest.cpp
HTTPResponse.o:HTTPResponse.h
	g++ -c HTTPResponse.cpp
clean:
	rm -rf *.o
