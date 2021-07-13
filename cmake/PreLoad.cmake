# -----------------------------------------------------------------------------
#  Cmake preload file, for generator setting
#  File Name       :  PreLoad.cmake
#  Generator       :  Ninja
#  Author          :  shibo jiang  
#  Instructions    :  Initial file.             2020/12/19                 V0.1
# 
# -----------------------------------------------------------------------------

# use Ninja as generator MinGW Makefiles
set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)
# do not check asm compiler
set(CMAKE_ASM_COMPILER_ID_RUN TRUE CACHE INTERNAL "" FORCE)