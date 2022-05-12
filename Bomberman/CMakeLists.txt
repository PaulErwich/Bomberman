cmake_minimum_required(VERSION 3.20)
project(Bomberman)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
set(SOURCE_FILES src/main.cpp src/Game.h src/Game.cpp src/GameStates/GameStateBase.cpp src/GameStates/GameStateBase.h src/GameStates/GameMenu.cpp src/GameStates/GameMenu.h src/GameStates/GamePlay.cpp src/GameStates/GamePlay.h src/GameStates/GamePaused.cpp src/GameStates/GamePaused.h src/GameStates/GameOver.cpp src/GameStates/GameOver.h src/GameStates/GameWin.cpp src/GameStates/GameWin.h src/GameObjects/GameObject.cpp src/GameObjects/GameObject.h src/Extra/Helper.cpp src/Extra/Helper.h src/Extra/Vector2.cpp src/Extra/Vector2.h src/GameObjects/Level.cpp src/GameObjects/Level.h src/GameObjects/Block.cpp src/GameObjects/Block.h src/GameObjects/Entity.cpp src/GameObjects/Entity.h src/GameObjects/Powerups/Powerup.cpp src/GameObjects/Powerups/Powerup.h)
add_executable(Bomberman ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries(Bomberman sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)
