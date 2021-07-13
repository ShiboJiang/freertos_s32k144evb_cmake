# -----------------------------------------------------------------------------
#  Cmake File for cross paltform build
#  File Name      :  CMakeLists.txt
#  CMake Version  :  V3.17.2
#  Author         :  shibo jiang  
#  Instructions   :  Initial file.             2020/12/19                 V0.1
# 
# -----------------------------------------------------------------------------

# user config -----------------------------------------------------------------
# whehter use debug mode, ON/OFF
option(CMAKE_DEBUG "Whether use debug type" ON)
include(${CMAKE_CURRENT_SOURCE_DIR}/gcc_arm_eabi_toolchain.cmake)
set(CMAKE_TOOLCHAIN_FILE "gcc_arm_eabi_toolchain.cmake")
set(target_name "S32K144EVB_LED")

# .h .c .cpp folder ,can auto recursive find source code
set(src_folder  "../Generated_Code"
                "../SDK"
                "../Sources"
                "../Project_Settings"
                "C:/NXP/S32DS_ARM_v2.2/S32DS/build_tools/gcc_v6.3/gcc-6.3-arm32-eabi/include")

# append src (*.c *.h ...) setting.
set(src_files "")

# asm file list
list(APPEND CMAKE_ASM_SOURCE_FILE_EXTENSIONS S asm inc)
set(asm_files "../Project_Settings/Startup_Code/Startup_S32K144.S")
SET_SOURCE_FILES_PROPERTIES(${asm_files} PROPERTIES LANGUAGE ASM)

# .a .o .obj .so .lib files folder , can not recursive find
set(lib_folder "")

# link file ,for embeded platform and cross platform complie
# 此处需注意，链接脚本在链接过程中才开始产生作用，而之前源码目录设定在 cmake 加载并生成
# ninja rules时开始作用，所以在 build目录下 ，使用cmake .. 加载源码生成构建器时，路径
# 使用一层返回 ../ ，含义为从 cmake 文件夹开始向上返回， 而在使用 cmake --build . 进行
# 构建时，需要设定链接脚本相对路径为 两层返回 ../../ ，含义为从 build 文件夹下进行向上
# 查找。
set(link_file "../../Project_Settings/Linker_Files/S32K1xx_flash.ld")

# User defined in pre-compile
add_definitions(-D CPU_S32K144HFT0VLLT)
add_definitions(-D USING_OS_FREERTOS)
add_definitions(-D S32K)
add_definitions(-D DEV_ERROR_DETECT)

# system config ,do not change or change it carefully--------------------------
# set minimum cmake version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
message(STATUS "Target name is set to ${target_name}")
message(STATUS "Generator is set to ${CMAKE_GENERATOR}")

# project name and language
project(${target_name}_prj LANGUAGES C CXX ASM)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

message(STATUS "src subfolder name:")
# funciton declation for recursively find file
MACRO(SUBDIRLIST result curdir)
  SET(dirlist "")
  SET(spec_dir_index "")
  SET(ignore_dir_index "")
  LIST(APPEND dirlist ${curdir})
  FILE(GLOB_RECURSE children LIST_DIRECTORIES true ${curdir}/*)
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${child})
      # use specific folder name to judge
      # STRING(REGEX REPLACE ".*/" "" sub_folder ${child})
      SET(spec_dir_index -1)
      SET(ignore_dir_index -1)
      # only have file ,then add folder to list 
      FILE(GLOB tp_files ${child}/*.*)
      IF(tp_files)
        LIST(APPEND dirlist ${child})
      ELSE()
        # message("******** 3 This folder has no files, do not add to list!*** ${child}")
      ENDIF()
        # message("child_folder = ${child}")
        # message("sub_folder = ${sub_folder}")
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

# debug code ------------------------------------------------------------------
# set(temp_ignore_flg "")
# list(FIND src_ignore "test" temp_ignore_flg)
# message("temp_ignore_flg = ${temp_ignore_flg}")
# set(src_spec_len "")
# list(LENGTH src_spec src_spec_len)
# message("src_spec_len = ${src_spec_len}")
# if(src_spec)
#   message("src_spec ok")
# else()
#   message("src_spec not ok")
# endif()
# if(src_ignore)
#   message("src_ignore ok")
# else()
#   message("src_ignore not ok")
# endif()
# ----------------------------------------------------------------------------- 

# project file and folder
set(SUBDIRS "")
foreach(sub_src_folder ${src_folder})
  SUBDIRLIST(TEMP_SUBDIRS ${sub_src_folder})
  list(APPEND SUBDIRS ${SUBDIRS} ${TEMP_SUBDIRS})
  # include_directories(${sub_dir})
  # aux_source_directory(${sub_dir} temp_src_list)
  # message(${temp_src_list})
endforeach()
# remove dupulicate file and print src file
list(REMOVE_DUPLICATES SUBDIRS)
# add src folder and include folder
set(src_list "")
# set(file_no "")
message("\n#### source file list: ####")
foreach(sub_dir ${SUBDIRS})
  set(temp_src_list "")
  include_directories(${sub_dir})
  aux_source_directory(${sub_dir} temp_src_list)
  # list(APPEND src_list ${src_list} ${temp_src_list})
  foreach(tp_file ${temp_src_list})
    # list(APPEND src_list ${src_list} ${tp_file})
    # message(${tp_file})
    set(src_list ${src_list} ${tp_file})
  endforeach()
endforeach()

# combine asm files
if(asm_files)
  message(STATUS "Project contain asm files: ")
  set(src_list ${src_list} ${asm_files})
  foreach(tp_file ${asm_files})
    # message(${tp_file})
  endforeach()
endif()
# combine append src files
if(src_files)
  message(STATUS "Project contain append src files: ")
  set(src_list ${src_list} ${src_files})
  foreach(tp_file ${src_files})
    # message(${tp_file})
  endforeach()
endif()
# get source file number
list(LENGTH src_list files_no)
message(STATUS "source files no. = ${files_no}")

# set out file
set(EXECUTABLE ${target_name}.elf)
add_executable(${EXECUTABLE} ${src_list})
# target_compile_definitions(${EXECUTABLE} PRIVATE
#                             ${C_OPTIONS})
# target_compile_options(${EXECUTABLE} PRIVATE
#                         ${C_OPTIONS})
target_link_options(${EXECUTABLE} PRIVATE
                    -T ${link_file})
# debug -----------------------------------------------------------------------
# message(STATUS "C_OPTIONS:  ${C_OPTIONS}")
# message(STATUS "LD_OPTIONS:  ${LD_OPTIONS}")
# message(STATUS "${CMAKE_C_LINK_EXECUTABLE}")
# -----------------------------------------------------------------------------

# get lib files
if (lib_folder)
  message("\n#### Extern Lib Files ####")
  foreach(lib_dir ${lib_folder})
    # add lib folder path 
    link_directories(${lib_dir})
    # add lib files to 
    file(GLOB lib_a_files "${lib_dir}/*.a")
    file(GLOB lib_o_files "${lib_dir}/*.o")
    file(GLOB lib_obj_files "${lib_dir}/*.obj")
    file(GLOB lib_so_files "${lib_dir}/*.so")
    file(GLOB lib_lib_files "${lib_dir}/*.lib")
    list(APPEND lib_files ${lib_a_files} 
                          ${lib_obj_files}
                          ${lib_o_files}
                          ${lib_so_files}
                          ${lib_lib_files})
    # message(STATUS "Lib folder: ${lib_dir}")
  endforeach()
  # report files
  # foreach(tp_file ${lib_files})
    # message(${tp_file})
  # endforeach()
  list(LENGTH lib_files lib_files_no)
  message(STATUS "lib files no. = ${lib_files_no}")
  # link lib to excute
  target_link_libraries(${EXECUTABLE}
                        ${lib_files})
else()
  # target_link_libraries(${target_name}_lib ${target_name})
endif()

# Post build ------------------------------------------------------------------
# Print executable size
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND ${CMAKE_GSIZE_TOOL} ${EXECUTABLE}
        COMMAND echo [Work done! Generated ${target_name}.elf])
# Create hex s19 file
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND ${CMAKE_GSREC_TOOL} -O srec ${EXECUTABLE} ${target_name}.s19
        COMMAND ${CMAKE_GSREC_TOOL} -O ihex ${EXECUTABLE} ${target_name}.hex
        COMMAND echo [Work done! Generated ${target_name}.hex ${target_name}.s19])

# end of file -----------------------------------------------------------------