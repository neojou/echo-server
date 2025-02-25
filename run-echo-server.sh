#!/bin/bash

# 檢查是否提供了參數 $1，若無則使用預設 port 5001
if [ -z "$1" ]; then
    PORT=5001
else
    PORT=$1
fi

# 執行 Kotlin JAR 檔案並傳入 port 參數
java -jar EchoServer.jar $PORT

