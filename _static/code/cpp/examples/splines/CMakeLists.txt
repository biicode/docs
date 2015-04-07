# This CMakeLists.txt file helps defining your block building and compiling
# Include the main biicode macros and functions
# To learn more about the CMake use with biicode, visit http://docs.biicode.com/c++/building.html
# Or check the examples below


include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)

# ACTIVATING C++11 FLAG
IF(APPLE)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
ELSEIF (WIN32 OR UNIX)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ENDIF(APPLE)
ADD_BII_TARGETS()
