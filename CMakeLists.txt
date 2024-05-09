cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("SimpleGame")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (SimpleGame "SimpleGame.cpp" "SimpleGame.h" "Constants.h" "Character.h" "Character.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SimpleGame PROPERTY CXX_STANDARD 20)
endif()


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