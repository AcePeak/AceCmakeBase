# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project(AceCmakeBase)

# 是否开启Coveralls支持，默认不支持
option(COVERALLS "Turn on coveralls support" OFF)

# 设置modulepath包括子模块
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} 
	${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake)

# 如果开启Coveralls，调用子模块内容
if (COVERALLS)
  SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
  SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
  #SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage -lgcov")
endif()

# 设置全局默认路径
set(PROJ_SRC_PATH ${PROJECT_SOURCE_DIR}/src/)
set(PROJ_TEST_PATH ${PROJECT_SOURCE_DIR}/test/)

#添加子目录
add_subdirectory(src)
add_subdirectory(test)