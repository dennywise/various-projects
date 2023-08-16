import threading
import socket
'''değişkenler'''
ip = input("Bağlanılacak sunucu IP'sini giriniz:")
port = input("Portu giriniz:")
alias = input('İsminizi yazın:')
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((ip, int(port)))


def client_receive(): #mesaj receive 
    while True:
        try:
            message = client.recv(1024).decode('utf-8')
            if message == "alias?":
                client.send(alias.encode('utf-8'))
            else:
                print(message)
        except:
            print('Hata!')
            client.close()
            break


def client_send(): #mesaj gönderme
    while True:
        message = f'{alias}: {input("")}'
        client.send(message.encode('utf-8'))


receive_thread = threading.Thread(target=client_receive)
receive_thread.start()


send_thread = threading.Thread(target=client.send)
send_thread.start()