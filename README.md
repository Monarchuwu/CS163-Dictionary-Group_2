# CS163-Dictionary-Group_2

# Cấu trúc chương trình
- data/ : nơi chứa các data
  - fonts/ : chứa fonts. Ví dụ: arial.ttf
  - images/ : chứa các ảnh
  - slang/ : chứa dataset Slang (các dataset còn lại sẽ update sau)
  - <other> : các data còn lại
- src/ : nơi chứa code
  - favouriteScreen/ : chứa code của favourite screen
  - mainScreen/ : chứa code của main screen
  - <other> : chứa main.cpp, class Constant, class Application, và các class dùng chung (ưu tiên cho vào các folder nếu có thể)

- Truy cập data từ data/ : dir là "data/..."
  - ví dụ: "data/images/black_arrow.png"
 
- Truy cập thư mục cha: "../"
  - ví dụ: class Screen ở src/, class mainScreen ở src/mainScreen/, ta include Screen trong mainScreen bằng "../Screen.h"
  - có thể dùng "../" nhiều lần để nhảy về các folder cha của cha

# Rule UI
- Mỗi Screen cần có 3 hàm:
  - `void handleEvent(const sf::Event& event);`
    - để xử lý event
    - nếu cần tương tác với màn hình, dùng data của `event`
      - ví dụ: vị trí mouse ở `event.mouseButton`
  - `void update();`
    - để update các object sau khi xử lý tất cả event
  - `void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;`
    - vẽ object ra màn hình
  - Ví dụ:
  ![image](https://github.com/Monarchuwu/CS163-Dictionary-Group_2/assets/75823146/c2d8531b-926f-4896-9c97-c864e973d149)
