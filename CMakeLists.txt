cmake_minimum_required(VERSION 4.1)
project(Cthis)
# 設定 C++ 標準為 20
set(CMAKE_CXX_STANDARD 20)
# 強制要求編譯器必須支援此版本，若不支援則報錯
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")




file(GLOB files *.cpp)

# 對於每一個找到的 .cpp 檔案，都自動建立一個同名的執行檔
foreach(file ${files})
    # 去掉副檔名，取得檔案名稱（例如 test1）
    get_filename_component(name ${file} NAME_WE)
    # 將其定義為獨立的執行目標
    add_executable(${name} ${file}
            )
endforeach()