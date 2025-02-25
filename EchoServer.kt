// EchoServer.kt
import java.net.ServerSocket
import java.io.PrintWriter
import java.io.BufferedReader
import java.io.InputStreamReader

fun main(args: Array<String>) {

    // 檢查是否有提供 port 參數，若無則使用預設值 5000
    val port = if (args.isNotEmpty()) {
        try {
            args[0].toInt()
        } catch (e: NumberFormatException) {
            println("無效的 port 號碼，使用預設 port 5000")
            5000
        }
    } else {
        5000
    }

    // 驗證 port 號碼範圍
    if (port !in 1..65535) {
        println("Port 號碼必須在 1-65535 之間，使用預設 port 5000")
        return
    }

    val serverSocket = ServerSocket(port)
    println("Echo server 正在 port $port 監聽...")

    try {
        while (true) {
            // 接受客戶端連線
            val clientSocket = serverSocket.accept()
            println("新的客戶端已連線")

            // 處理客戶端資料
            try {
                val input = BufferedReader(InputStreamReader(clientSocket.getInputStream()))
                val output = PrintWriter(clientSocket.getOutputStream(), true)

                while (true) {
                    val line = input.readLine() ?: break
                    println("收到: $line")
                    output.println(line) // 回傳相同的內容
                }
            } catch (e: Exception) {
                println("客戶端已斷線: ${e.message}")
            } finally {
                clientSocket.close()
            }
        }
    } catch (e: Exception) {
        println("Server 錯誤: ${e.message}")
    } finally {
        serverSocket.close()
    }
}

