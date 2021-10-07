#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define HOST "djxmmx.ne"  
#define PORT 17
  
// Driver code
int main() {
    struct sockaddr_in sock;
    int fd;
    char buf[2048] = {0};

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Cannot create socket\n");
        return 1;
    }
    memset(&sock, 0, sizeof(sock));
      
    sock.sin_family = AF_INET;
    sock.sin_port = htons(PORT);
    sock.sin_addr.s_addr = inet_addr("djxmmx.ne");
      
      
    sendto(fd, "", strlen(""),
        MSG_CONFIRM, (const struct sockaddr *) &sock, 
            sizeof(sock));
    printf("UDP packet sent.\n");
          
    int len;
    int n = recvfrom(fd, (char *)buf, 2048, MSG_WAITALL, (struct sockaddr *) &sock, &len);
    buf[n] = '\0';
    printf("Server response: %s\n", buf);
    close(fd);
    return 0;
}
