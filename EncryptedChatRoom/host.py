import socket
import threading

#!!sunucu açıldığı makinanın IP'sini alır!!
host = socket.gethostbyname(socket.gethostname())
print("IP'niz:", host)
port = input("bağlanmak istediğiniz portu giriniz:")
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, int(port)))
server.listen()
clients= []
aliases = []


def broadcast(message): #kullanıcı bağlantısı fonksiyonu
    for client in clients:
        client.send(message)


def handle_client(client): #kullanıcıları tutan fonksiyon
    while True:
        try:
            message=client.recv(1024)
            broadcast(message)
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            alias = aliases[index]
            broadcast(f'{alias} Konuşmadan ayrıldı!'.encode)
            aliases.remove(alias)
            break


def receive(): #erişim fonksiyonu
    while True:
        print('Sunucu aktif...')
        client, address = server.accept()
        print(f'{str(address)} adresiyle bağlantı kuruldu.')
        client.send('alias?'.encode('utf-8'))
        alias = client.recv(1024)
        aliases.append(alias)
        clients.append(client)
        print(f'Bu kullanıcının adı: {alias}'.encode('utf-8'))
        broadcast(f'{alias} Konuşmaya bağlantı.'.encode('utf-8'))
        client.send('Bağlandınız'.encode('utf-8'))
        thread = threading.Thread(target = handle_client, args=(client))
        thread.start()
if __name__ == "__main__":
    receive()

