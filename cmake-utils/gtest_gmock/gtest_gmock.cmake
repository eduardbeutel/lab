set(CSHELF_CODE_DIR ${CMAKE_CURRENT_LIST_DIR})

macro(cshelf_setup_gtest_gmock)
if(NOT CSHELF_SETUP_GTEST_GMOCK_STATIC_ENTERED)
set(CSHELF_SETUP_GTEST_GMOCK_STATIC_ENTERED TRUE) 
    set(CSHELF_GTEST_GMOCK_INCLUDE "${CSHELF_CODE_DIR}")
    set(CSHELF_GTEST_GMOCK_SOURCES
        "${CSHELF_CODE_DIR}/src/gtest-all.cc"
        "${CSHELF_CODE_DIR}/src/gmock-all.cc"
    ) 
    find_package(Threads)  
    include_directories(${CSHELF_GTEST_GMOCK_INCLUDE})  
endif()
endmacro()

macro(import_gtest_gmock_static)
if(NOT CSHELF_IMPORT_GTEST_GMOCK_STATIC_ENTERED)
set(CSHELF_IMPORT_GTEST_GMOCK_STATIC_ENTERED TRUE)  
    cshelf_setup_gtest_gmock()   
    add_library(gtest_gmock_static STATIC ${CSHELF_GTEST_GMOCK_SOURCES})     
    target_link_libraries (gtest_gmock_static ${CMAKE_THREAD_LIBS_INIT})
endif()
endmacro()

macro(import_gtest_gmock_gmain_static)
if(NOT CSHELF_IMPORT_GTEST_GMOCK_GMAIN_STATIC_ENTERED)
set(CSHELF_IMPORT_GTEST_GMOCK_GMAIN_STATIC_ENTERED TRUE)  
    cshelf_setup_gtest_gmock()   
    set(CSHELF_GTEST_GMOCK_GMAIN_SOURCES
        "${CSHELF_CODE_DIR}/src/gmock_main.cc"
        ${CSHELF_GTEST_GMOCK_SOURCES}
    )
    add_library(gtest_gmock_gmain_static STATIC ${CSHELF_GTEST_GMOCK_GMAIN_SOURCES})     
    target_link_libraries(gtest_gmock_gmain_static ${CMAKE_THREAD_LIBS_INIT})
endif()
endmacro()

macro(add_gtest_executable TARGET SOURCES)
    import_gtest_gmock_gmain_static()
    add_executable(${TARGET} ${SOURCES})
    target_link_libraries(${TARGET} gtest_gmock_gmain_static)
endmacro(add_gtest_executable)


