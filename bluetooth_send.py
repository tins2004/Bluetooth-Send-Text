import socket

def connect():
    # Bluetooth device information
    server_mac_address = '24:0A:C4:29:67:CA'  # MAC address of the Bluetooth device

    # Create a Bluetooth socket
    sock = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)

    # Connect to a Bluetooth device
    sock.connect((server_mac_address, 1))
    print("Connected to Bluetooth device")

    try:
        while True:
            # Send data
            message = input("Enter message: ")
            if message == "END":
                break
            sock.send(message.encode('utf-8'))
            print("Sent:", message)

            # Receive data from Bluetooth device
            data = sock.recv(1024)
            print("Received:", data.decode('utf-8'))

    finally:
        # Close the connection
        sock.close()

connect()
