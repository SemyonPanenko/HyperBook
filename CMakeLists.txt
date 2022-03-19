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

#creating targets
add_executable(MainTarget ${main_src})


#linking targets
target_link_libraries(MainTarget 
    ${GTKMM_LIBRARIES}  )

