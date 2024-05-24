cmake_minimum_required (VERSION 3.16)

project ("SimpleGame")


# Добавьте источник в исполняемый файл этого проекта.
add_executable (SimpleGame "main.cpp"  "map.h" "view.h" "Player.h"     "Preview.h" "Outro.h" "menu.h")

set(CMAKE_CXX_STANDARD 14)

# Установите путь к библиотекам и заголовочным файлам SFML
set(SFML_DIR "C:/SFML-2.6.1-windows-vc17-64-bit/SFML-2.6.1/lib/cmake/SFML")


# Найдите компоненты SFML, которые вам необходимы
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
find_package(Freetype)
find_package(JPEG)
find_package(SFML 2 COMPONENTS window graphics system)

# Добавьте ваши исходные файлы

# Подключите SFML библиотеки к вашему проекту
target_link_libraries("SimpleGame" sfml-graphics sfml-audio)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)

set(RESOURCE_FILES  "tinystr.h" "tinyxml.h" "tinyxml.lib")
