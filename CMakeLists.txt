cmake_minimum_required(VERSION 3.10)
project(My3DGame)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)

# Asegúrate de que los archivos fuente estén correctamente definidos para My3DGame
add_executable(My3DGame
    src/main.cpp
    src/renderer.cpp
    src/movement.cpp
    # Otros archivos fuente si los tienes
)



# Usa pkg-config para encontrar GLFW, GLEW y Bullet
pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(GLEW REQUIRED glew)
pkg_check_modules(BULLET REQUIRED bullet)

include_directories(${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${BULLET_INCLUDE_DIRS})
link_directories(${GLFW_LIBRARY_DIRS} ${GLEW_LIBRARY_DIRS} ${BULLET_LIBRARY_DIRS})

target_link_libraries(My3DGame
    ${OPENGL_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${BULLET_LIBRARIES}
)
