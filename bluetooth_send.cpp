#include <iostream>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <unistd.h>
#include <cstring>

int main() {
    // Replace "00:11:22:33:44:55" with the MAC address of your Bluetooth device
    const char* dest = "00:11:22:33:44:55";

    // Create Bluetooth socket
    int s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    if (s < 0) {
        perror("Socket error");
        return 1;
    }

    // Set up the destination
    struct sockaddr_rc addr = {0};
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba(dest, &addr.rc_bdaddr);

    // Connect to the remote device
    int status = connect(s, (struct sockaddr *)&addr, sizeof(addr));
    if (status < 0) {
        perror("Connection error");
        close(s);
        return 1;
    }

    // Message to send
    const char* message = "Hello, Bluetooth!";

    // Send the message
    status = write(s, message, strlen(message));
    if (status < 0) {
        perror("Write error");
        close(s);
        return 1;
    }

    std::cout << "Message sent successfully!" << std::endl;

    // Close the socket
    close(s);

    return 0;
}

