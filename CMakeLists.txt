# CMakeList.txt : CMake project for ImGui-Standalone-Demo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ImGui-Standalone-Demo")

# Add source to this project's executable.
add_executable (ImGui-Standalone-Demo "ImGui-Standalone-Demo.cpp" )

include ( "FindOpenGL" )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory ( glfw )

target_compile_definitions ( ImGui-Standalone-Demo
	PUBLIC
	IMGUI_DEFINE_MATH_OPERATORS
)

target_include_directories ( ImGui-Standalone-Demo 
	PUBLIC
	"imgui"
	"imgui/backends"
	"imgui/misc/cpp"
	"imgui-filebrowser"
)

target_sources ( ImGui-Standalone-Demo 
	PRIVATE
	"imgui/imgui.cpp"
	"imgui/imgui_demo.cpp"
	"imgui/imgui_draw.cpp"
	"imgui/imgui_widgets.cpp"
	"imgui/imgui_tables.cpp"
	"imgui/misc/cpp/imgui_stdlib.cpp"
	"imgui/backends/imgui_impl_opengl3.cpp"
	"imgui/backends/imgui_impl_glfw.cpp"
 )

target_link_libraries ( ImGui-Standalone-Demo 
	PRIVATE 
	OpenGL::GL
	glfw
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ImGui-Standalone-Demo PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
