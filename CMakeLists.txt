cmake_minimum_required(VERSION 3.16)

# Set the project name
project(std_algo VERSION 0.0)

# Colorized Output Setup
if(NOT WIN32)
  string(ASCII 27 Esc)
  set(Reset 		"${Esc}[m")
  set(Bold  		"${Esc}[1m")
  set(Red         	"${Esc}[31m")
  set(Green       	"${Esc}[32m")
  set(Blue        	"${Esc}[34m")
  set(Cyan        	"${Esc}[36m")
  set(Magenta     	"${Esc}[35m")
  set(Yellow      	"${Esc}[33m")
  set(White       	"${Esc}[37m")
  set(BoldRed     	"${Esc}[1;31m")
  set(BoldGreen   	"${Esc}[1;32m")
  set(BoldBlue    	"${Esc}[1;34m")
  set(BoldCyan    	"${Esc}[1;36m")
  set(BoldMagenta 	"${Esc}[1;35m")
  set(BoldYellow  	"${Esc}[1;33m")
  set(BoldWhite   	"${Esc}[1;37m")
endif()

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message("${Blue}Building std_algo library to ${PROJECT_BINARY_DIR}${Reset}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/)
add_library(${PROJECT_NAME}
    src/sort.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)


# Installation commands
message("${Blue}Installing std_algo library to ${CMAKE_INSTALL_PREFIX}${Reset}")

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}_targets
    DESTINATION lib
)

install(FILES
    ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/sort.h
    DESTINATION include/${PROJECT_NAME}
)

install(EXPORT ${PROJECT_NAME}_targets
    FILE ${PROJECT_NAME}_targets.cmake
    DESTINATION lib/cmake/${PROJECT_NAME})

include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "lib/cmake/example"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION "${std_algo_VERSION_MAJOR}.${std_algo_VERSION_MINOR}"
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION lib/cmake/${PROJECT_NAME}
)


# Uninstall target. To run it just run: make uninstall
if(NOT TARGET uninstall)
    configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
	IMMEDIATE @ONLY
    )

    add_custom_target(uninstall
	COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

