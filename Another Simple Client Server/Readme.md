# Client and Server program
The purpose of this project is to send and receive file by two programs.
Sever.c is written to send file and client.c is supposed to receive file.It is
written on C.

# How to use
  - open up a terminal in a linux enviroment
  - go to client_server folder
  - Type the word make. It will build the project (make sure your environment
    is ready for C programming language)
  - go to server folder and type ./server 5000 where 5000 is the port (you can
    put other available ports here.)
  - leave it running
  - open up another terminal 
  - got to client_server/client folder
  - type ../client 127.0.0.1 5000 first.txt where 127.0.0.1 is the address for
    localhost, 5000 is the port number, and first.txt is the file we are
requesting from server program.
  - If the transaction is successfull, the client program will say "File
    transffered successfully"
  - Both server and client program can close by pressing ctrl+c.
