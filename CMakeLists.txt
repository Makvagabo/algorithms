cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)

project(algorithms)

set(LIB_TYPE SHARED)
set(TEST_LINKS)
set(MAIN_EXE main.cpp)

if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    set(LIB_TYPE STATIC)
    set(TEST_LINKS gtest gtest_main)
    set(MAIN_EXE main_test.cpp)
    set(GOOGLE_TEST_DIR ${PROJECT_SOURCE_DIR}/lib/googletest)

    if (NOT EXISTS ${GOOGLE_TEST_DIR})
        # Download and unpack googletest at configure time
        configure_file(CMakeLists.txt.in ${GOOGLE_TEST_DIR}/download/CMakeLists.txt)
        execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${GOOGLE_TEST_DIR}/download)
        if (result)
            message(FATAL_ERROR "CMake step for googletest failed: ${result}")
        endif ()
        execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${GOOGLE_TEST_DIR}/download)
        if (result)
            message(FATAL_ERROR "Build step for googletest failed: ${result}")
        endif ()
    endif ()
    # Prevent overriding the parent project's compiler/linker
    # settings on Windows
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # Add googletest directly to our build. This defines
    # the gtest and gtest_main targets.
    add_subdirectory(${GOOGLE_TEST_DIR}/src
            ${GOOGLE_TEST_DIR}/build
            EXCLUDE_FROM_ALL)

    # The gtest/gtest_main targets carry header search path
    # dependencies automatically when using CMake 2.8.11 or
    # later. Otherwise we have to add them here ourselves.
    # ! Don't work for me
    # if (CMAKE_VERSION VERSION_LESS 2.8.11)
        include_directories("${gtest_SOURCE_DIR}/include")
    # endif ()
endif ()

set(BASEPATH "${CMAKE_SOURCE_DIR}/src")
include_directories("${BASEPATH}")

set(${PROJECT_NAME}_LIBS)
file(GLOB CHAPTERS "${BASEPATH}/*")
list(FILTER CHAPTERS EXCLUDE REGEX [.])
foreach(VALUE IN LISTS CHAPTERS)
    get_filename_component(DIR ${VALUE} NAME)
    list(APPEND ${PROJECT_NAME}_LIBS ${DIR})

    file(GLOB CHAPTER_H "${VALUE}/*.h")
    file(GLOB CHAPTER_SRC "${VALUE}/*.[ch]pp")
    file(GLOB CHAPTER_SRC_LIST ${CHAPTER_H} ${CHAPTER_SRC} ${CHAPTER_TEST})

    add_library(${DIR} ${LIB_TYPE} ${CHAPTER_SRC_LIST})
endforeach()

add_executable(${PROJECT_NAME} ${MAIN_EXE})

target_link_libraries(${PROJECT_NAME} ${TEST_LINKS} ${${PROJECT_NAME}_LIBS})