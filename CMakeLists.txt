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

#main source file
set(main_src ${src_dir}/main.cpp)

#content source files
set(content_sources ${src_dir}/Content)
set(text_cnt_src ${content_sources}/TextContent.cpp)

#board source files
set(board_sources ${src_dir}/BoardSources)
set(board_src ${board_sources}/Board.cpp)
set(board_man_src ${board_sources}/BoardManager.cpp)
set(board_tree_src ${board_sources}/BoardTree.cpp)

#visualizer source files
set(console_visint_src ${src_dir}/ConsoleVisInt)
set(console_vis_src ${console_visint_src}/ConsoleVisualizer.cpp)
set(cons_inter_src ${console_visint_src}/ConsoleInterface.cpp)

set(file_vis_sources ${src_dir}/FileVisualizer)
set(file_vis_src ${file_vis_sources}/FileVisualizer.cpp)

#inner structure source files
set(inner_structure_src ${src_dir}/InnerStructure)
set(project_src ${inner_structure_src}/Project.cpp)
set(proj_man_src ${inner_structure_src}/ProjectManager.cpp)
set(app_src ${inner_structure_src}/Application.cpp)
set(proj_loader_src ${inner_structure_src}/ProjectLoader.cpp)

#creating targets
add_executable(MainTarget ${main_src})

add_library(TextContent ${text_cnt_src})
add_library(Board ${board_src})
add_library(ConsoleVisualizer ${console_vis_src})
add_library(BoardManager ${board_man_src})
add_library(Project ${project_src})
add_library(BoardTree ${board_tree_src})
add_library(ProjectManager ${proj_man_src})
add_library(Application ${app_src})
add_library(ConsoleInterface ${cons_inter_src})
add_library(FileVisualizer ${file_vis_src})
add_library(ProjectLoader ${proj_loader_src})
#linking targets
target_link_libraries(MainTarget 
    ${GTKMM_LIBRARIES}  )

target_link_libraries(MainTarget TextContent)
target_link_libraries(MainTarget Board)
target_link_libraries(MainTarget ConsoleVisualizer)
target_link_libraries(MainTarget BoardManager)
target_link_libraries(MainTarget BoardTree)
target_link_libraries(MainTarget Project)
target_link_libraries(MainTarget ProjectManager)
target_link_libraries(MainTarget Application)
target_link_libraries(MainTarget ConsoleInterface)
target_link_libraries(MainTarget FileVisualizer)

target_link_libraries(ProjectManager Project)
target_link_libraries(ProjectManager BoardTree)
target_link_libraries(ProjectManager ProjectLoader)
target_link_libraries(Project BoardTree)

target_link_libraries(ConsoleVisualizer TextContent)

target_link_libraries(BoardTree Board)
