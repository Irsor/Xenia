cmake_minimum_required(VERSION 3.30)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Xenia")

find_package(fmt CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

# Add source to this project's executable.
add_executable (Xenia "src/main.cpp" )

target_link_libraries(Xenia PRIVATE fmt::fmt)
target_link_libraries(Xenia PRIVATE glfw)

set_property(TARGET Xenia PROPERTY CXX_STANDARD 23)