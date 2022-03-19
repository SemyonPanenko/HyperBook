cmake_minimum_required(VERSION 3.16)

project(HyperBook)

#finding and linking gtkmm
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0) 

link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

#setting project variables
set(src_dir ${PROJECT_SOURCE_DIR}/sources)
set(header_dir ${PROJECT_SOURCE_DIR}/headers)

include_directories(${PROJECT_SOURCE_DIR})

set(main_src ${src_dir}/main.cpp)
set(text_cnt_src ${src_dir}/TextContent.cpp)
set(board_src ${src_dir}/Board.cpp)
set(console_vis_src ${src_dir}/ConsoleVisualizer.cpp)

#creating targets
add_executable(MainTarget ${main_src})
add_library(TextContent ${text_cnt_src})
add_library(Board ${board_src})
add_library(ConsoleVisualizer ${console_vis_src})


#linking targets
target_link_libraries(MainTarget 
    ${GTKMM_LIBRARIES}  )

target_link_libraries(MainTarget TextContent)
target_link_libraries(MainTarget Board)
target_link_libraries(MainTarget ConsoleVisualizer)

