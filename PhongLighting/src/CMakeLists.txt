
add_executable (PhongLighting)

target_sources(PhongLighting PRIVATE 
	PhongLighting.cpp
)

target_include_directories(PhongLighting PRIVATE
	../inc
)

#target_link_libraries(PhongLighting)
