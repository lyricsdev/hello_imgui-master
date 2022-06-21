cmake_minimum_required(VERSION 3.5)
#	set standard required to ensure that you get 
#	the same version of C++ on every platform
#	as some environments default to older dialects 
#	of C++ and some do not.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project (cross-platform-hello C CXX)
add_definitions( -DCURL_STATICLIB )
add_executable(${CMAKE_PROJECT_NAME} fizzbuzz.cpp "bytes.h")

set(CURL_LIBRARY "-lcurl")
set(GLAD_PREFIX
    "${CMAKE_CURRENT_SOURCE_DIR}/external/glad/glad"
    CACHE STRING "Path to glad"
)
set(GLFW_PREFIX
    "${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/"
    CACHE STRING "Path to glad"
)
set(DEAR_IMGUI_PREFIX
    "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/"
    CACHE STRING "Path to Dear ImGui"
)
set( CURL_LIBRARY ${CMAKE_SOURCE_DIR}/build/lib )
set( CURL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include )
set( OPENGL_gl_LIBRARY ${CMAKE_SOURCE_DIR}/external/glad )

find_package( CURL )
find_package(OpenGL REQUIRED)
 include_directories(
        "${CMAKE_CURRENT_SOURCE_DIR}/external"
    )
include_directories( ${CURL_INCLUDE_DIRS} )
link_directories( ${CURL_LIBRARIES} )

# glad
if (USING_CONAN)
    find_package(glad CONFIG REQUIRED)
else()
    add_library(glad "${GLAD_PREFIX}/src/glad.c" "bytes.h")
    include_directories(
        "${GLAD_PREFIX}/include"
    )
endif()

if(USING_CONAN)#OR (NOT WIN32))
    find_package(glfw3 CONFIG REQUIRED)
else()
    #find_library(glfw glfw3 PATHS "${GLFW_PREFIX}/lib")
    set(GLFW_BUILD_EXAMPLES OFF)
    set(GLFW_BUILD_TESTS OFF)
    set(GLFW_BUILD_DOCS OFF)
    add_subdirectory(${GLFW_PREFIX})
    include_directories(
        "${GLFW_PREFIX}/include"
    )
    # target_link_libraries(${CMAKE_PROJECT_NAME}
    #     PRIVATE
    #         ${glfw}
    # )
endif()
      list(APPEND ghuipizda
        ${DEAR_IMGUI_PREFIX}/imgui.cpp
        ${DEAR_IMGUI_PREFIX}/imgui_draw.cpp
        ${DEAR_IMGUI_PREFIX}/imgui_tables.cpp
        ${DEAR_IMGUI_PREFIX}/imgui_widgets.cpp
        ${DEAR_IMGUI_PREFIX}/backends/imgui_impl_glfw.cpp
        ${DEAR_IMGUI_PREFIX}/backends/imgui_impl_opengl3.cpp
        ${DEAR_IMGUI_PREFIX}/imgui_demo.cpp
    )
target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        ${ghuipizda}
)
target_link_libraries(cross-platform-hello 
PRIVATE
        ${sources}        
        ${OPENGL_gl_LIBRARY}
        glad
        glfw
)

