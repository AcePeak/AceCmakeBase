# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project(AceCmakeBase)

# 是否开启Coveralls支持，默认不支持
option(COVERALLS "Turn on coveralls support" OFF)

# 是否上传Coveralls结果，默认上传
option(COVERALLS_UPLOAD "Upload the generated coveralls json" ON)

# 设置modulepath包括子模块
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} 
	${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake)

# 如果开启Coveralls，调用子模块内容
if (COVERALLS)
	include(Coveralls)
	coveralls_turn_on_coverage()
endif()

# 设置全局默认路径
set(PROJ_SRC_PATH ${PROJECT_SOURCE_DIR}/src/)
set(PROJ_TEST_PATH ${PROJECT_SOURCE_DIR}/test/)

#添加子目录
add_subdirectory(src)
add_subdirectory(test)