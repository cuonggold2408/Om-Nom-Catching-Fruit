# Project Game of CuongGold
- Em chào mọi người ạ. Em xin tự giới thiệu em tên là Nguyễn Quang Cường, sinh viên K67 của Trường Đại Học Công Nghệ ĐHQGHN. Đây là dự án game đầu tiên của em, game Om-Nom-Catching-Fruit lấy ý tưởng nhân vật từ game Cut the Rope (Cắt dây thừng) là một trò chơi điện tử thể loại giải đố dựa trên vật lý nhiều phần của nhà phát triển Nga ZeptoLab thiết kế cho nhiều dạng máy và thiết bị chơi,game thay về lấy ý tưởng cắt kẹo thì thay bằng hoa quả rơi để cho bé Om Nom hứng. 
- Game sử dụng ngôn ngữ C++ và thư viện SDL2
## TỔNG QUAN
a) Các nguồn để hoành thành game 
- Viết Code: tham khảo lazyfoo và phanmemphattriengame123az.
- Music: https://www.freesoundeffects.com/ và tự tải ở các web khác nữa.

b) Luật chơi
- Di chuyển Om Nom và nhấn SPACE ăn hoa quả rơi
- Ăn hoa quả +5 điểm, ăn ngôi sao +10 điểm
- Ăn bom thì sẽ bị chia đôi điểm và trừ 1 mạng đến khi ăn đủ 3 quả bom đồng nghĩa với việc đã hết mạng thì sẽ game over.

c) Một số tính năng hay được phát triển thêm
- Đối với hoa quả và ngôi sao thì Om Nom phải nhấn SPACE để Om Nom há mồm thì mới ăn được.
- Đối với bom thì Om Nom chỉ cần chạm vào bom là sẽ tự ăn chứ không cần há mồm.
- Đối với việc giữ SPACE thì sẽ bị trừ điểm (lưu ý: điểm trừ rất nhanh nhé ^^).
- Khi đạt mức 100 điểm thì hoa quả,ngôi sao và bom sẽ rơi nhanh hơn.

d) Cấu trúc của Game
- Game được chia ra làm 4 module và main.cpp để chạy game:
  - (CommonFunc.h , CommonFunc.cpp): Khởi tạo các đối tượng biến chung và các hàng chung.
  - (BaseObject.h, BaseOject.cpp): các hàm cơ sở cho đối tượng.
  - (MainObject.h, MainObject.cpp): khởi tạo các thông số của Om Nom, các hàm di chuyển của Om Nom.
  - (FruitObject.h. FruitObject.cpp): khởi tạo các thông số của đối tượng hoa quả, các hàm rơi, tốc độ rơi, reset hoa quả.
  - main.cpp: hàm xử lý chính, chạy các file con và gồm: hàm menu, hàm gameover, ghi điểm số.
  
  ## MÔ TẢ 
  - Menu
  
    ![a](https://user-images.githubusercontent.com/124696095/235312880-665249dc-6b08-4a7b-add4-232b0082c1ac.png)
    
  - Màn hình chơi
    
    
    ![b](https://user-images.githubusercontent.com/124696095/235313169-d7e3777b-b203-4b04-9f61-06fd6ec03b12.png) ![c](https://user-images.githubusercontent.com/124696095/235313177-b6c40ad3-a47a-44fc-b7b0-0da11ad97c54.png)
    
  - Kết thúc Game
    
    
    ![d](https://user-images.githubusercontent.com/124696095/235313232-d784d249-2da2-4ed9-804d-3c96b280a2fc.png)



  
