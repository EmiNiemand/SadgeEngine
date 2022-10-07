cmake_minimum_required(VERSION 3.23)
project(SadgeEngine)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/Libs/SDL/include)
set(SDL2_LIB_DIR C:/Libs/SDL/lib/x64)
set(SDL2_IMAGE_INCLUDE_DIR C:/Libs/SDL_image/include)
set(SDL2_IMAGE_LIB_DIR C:/Libs/SDL_image/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})
link_directories(${SDL2_IMAGE_LIB_DIR})

add_executable(SadgeEngine main.cpp src/SadgeEngine.cpp lib/SadgeEngine.h src/SadgeActor.cpp lib/SadgeActor.h src/SadgeEngineUtils.cpp lib/SadgeEngineUtils.h src/SadgeCloud.cpp lib/SadgeCloud.h src/SadgePawn.cpp lib/SadgePawn.h src/SadgePetrFat.cpp lib/SadgePetrFat.h)

add_subdirectory(src)
add_subdirectory(lib)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image)