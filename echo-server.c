// echo-server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 5001
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // 建立 socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 設定 server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // 綁定 socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // 開始監聽
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Echo server 正在 port %d 監聽...\n", PORT);

    while (1) {
        // 接受客戶端連線
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            continue;
        }

        printf("新的客戶端已連線\n");

        // 處理客戶端資料
        while (1) {
            int n = read(client_fd, buffer, BUFFER_SIZE - 1);
            if (n <= 0) {
                printf("客戶端已斷線\n");
                break;
            }

            buffer[n] = '\0';  // 確保字串結束
            printf("收到: %s", buffer);
            
            // 回傳相同的內容
            write(client_fd, buffer, n);
        }

        close(client_fd);
    }

    close(server_fd);
    return 0;
}

