
# Setup the coveralls target and tell it to gather
# coverage data for all the lib sources.
if (COVERALLS)
	coveralls_setup(
        "../src/" 
        ${COVERALLS_UPLOAD}                 
        "${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake")
endif()

# Add a test for the library.
enable_testing()

include_directories ("../src/sample")

add_executable(sample_regress
				${PROJ_TEST_PATH}/TEST_sample.cpp)

target_link_libraries(sample_regress sample)

add_test(sample ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sample_regress)
