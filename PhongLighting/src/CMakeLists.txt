

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable (PhongLighting)


add_library(GLAD "${CMAKE_CURRENT_SOURCE_DIR}/glad.c")
target_include_directories(GLAD PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../inc")
target_link_libraries(GLAD PUBLIC ${OPENGL_LIBRARIES})


target_sources(PhongLighting PRIVATE 
		PhongLighting.cpp)
target_include_directories(PhongLighting PRIVATE
		../inc
	)
target_link_libraries(PhongLighting PRIVATE glfw GLAD OpenGL::GL)
