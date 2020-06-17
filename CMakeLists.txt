cmake_minimum_required(VERSION 3.5)

project(CustomTwitchTranscodeServer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)
find_package(Qt5Network)

add_executable(CustomTwitchTranscodeServer
  main.cpp
  stream_downloader.cpp
  stream_downloader.h
  stream_server.cpp
  stream_server.h
  client_socket.cpp
  client_socket.h
  settings.cpp
  settings.h
)
target_link_libraries(CustomTwitchTranscodeServer Qt5::Core Qt5::Network)
