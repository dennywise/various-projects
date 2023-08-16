import socket, threading


def TCP_connect(ip, port_number, delay, output):
    TCPsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    TCPsock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    TCPsock.settimeout(delay)
    try:
        TCPsock.connect((ip, port_number))
        output[port_number] = "Portu açık"
    except:
        output[port_number] = ''



def scan_ports(host_ip, delay):

    threads = []        # Multi-Thread için
    output = {}         # Print komutları için

    # Portları taraması için threadler
    for i in range(10000):
        t = threading.Thread(target=TCP_connect, args=(host_ip, i, delay, output))
        threads.append(t)

    # Threadler
    for i in range(10000):
        threads[i].start()

    # Tüm işlemler bitene kadar ana işlemi kitle
    for i in range(10000):
        threads[i].join()

    # açık portları küçükten nüyüğe sırala
    for i in range(10000):
        if output[i] == "Portu açık":
            print(str(i) + ': ' + output[i])



def main():
    host_ip = input("IP: ")
    delay = int(input("Gecikme: "))   
    scan_ports(host_ip, delay)

if __name__ == "__main__":
    main()