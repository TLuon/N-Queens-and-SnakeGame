🧩 NQueen & 🐍 SnakeGame (C++ Console Project)

Dự án bao gồm 2 bài lớn viết bằng C++:

1.  NQueen – Giải bài toán đặt N quân hậu trên bàn cờ sao cho không ăn
    nhau.
2.  SnakeGame – Trò chơi rắn săn mồi chạy trong CMD/Terminal.

Dự án được tổ chức rõ ràng, dễ build, dễ chạy và không dùng thư viện
ngoài.

------------------------------------------------------------------------

------------------------------------------------------------------------

🧠 1. NQueen

Backtracking + Bitmask phiên bản tối ưu.

Cách chạy:

g++ Bitmask.cpp -o nqueen.exe
./nqueen.exe

------------------------------------------------------------------------

🐍 2. SnakeGame

Game console không dùng thư viện ngoài.

Build:

g++ -I include src.cpp src.cpp src.cpp src.cpp src.cpp src.cpp -o
snake.exe

Chạy:

run.bat
hoặc
./snake.exe

------------------------------------------------------------------------


🎮 Điều khiển SnakeGame
Phím	Chức năng
W / ↑	Đi lên
S / ↓	Đi xuống
A / ←	Sang trái
D / →	Sang phải
P	Tạm dừng
R	Chơi lại khi game over

------------------------------------------------------------------------

🚀 Nâng cấp đề xuất:

-   Map mới
-   Portal
-   AI snake
-   Highscore
