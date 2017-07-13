
# ===================================================================================
#  The Tesseract CMake configuration file
#
#  Usage from an external project:
#    In your CMakeLists.txt, add these lines:
#
#    FIND_PACKAGE(Tesseract REQUIRED)
#    TARGET_LINK_LIBRARIES(MY_TARGET_NAME ${Tesseract_LIBS})
#
#    This file will define the following variables:
#      - Tesseract_LIBS                     : The list of libraries to link against.
#      - Tesseract_LIB_DIR                  : The directory(es) where lib files are. Calling 
#                                             LINK_DIRECTORIES with this path is NOT needed.
#      - Tesseract_INCLUDE_DIRS             : The Tesseract include directories.
#      - Tesseract_VERSION                  : The version of this Tesseract build. Example: "2.4.0"
#      - Tesseract_VERSION_MAJOR            : Major version part of Tesseract_VERSION. Example: "2"
#      - Tesseract_VERSION_MINOR            : Minor version part of Tesseract_VERSION. Example: "4"
#      - Tesseract_VERSION_PATCH            : Patch version part of Tesseract_VERSION. Example: "0"
#
#    Advanced variables:
#      - Tesseract_CONFIG_PATH
#
# ===================================================================================

set(Tesseract_VERSION_MAJOR 3)
set(Tesseract_VERSION_MINOR 4)
set(Tesseract_VERSION_PATCH 1)
set(Tesseract_VERSION ${Tesseract_VERSION_MAJOR}.${Tesseract_VERSION_MINOR}.${Tesseract_VERSION_PATCH})

get_filename_component(Tesseract_CONFIG_PATH "${CMAKE_CURRENT_LIST_FILE}" PATH CACHE)
set(Tesseract_LIB_DIR "${Tesseract_CONFIG_PATH}/lib")
set(Tesseract_INCLUDE_DIRS "${Tesseract_CONFIG_PATH}/include")

set(Tesseract_LIBS_DBG "liblept171d.lib" "libtesseract304d.lib")
set(Tesseract_LIBS_OPT "liblept171.lib" "libtesseract304.lib")
foreach(__tesslib ${Tesseract_LIBS_DBG})
  list(APPEND Tesseract_LIBS debug "${Tesseract_LIB_DIR}/${__tesslib}")
endforeach()
foreach(__tesslib ${Tesseract_LIBS_OPT})
  list(APPEND Tesseract_LIBS optimized "${Tesseract_LIB_DIR}/${__tesslib}")
endforeach()

set(Tesseract_FOUND TRUE CACHE BOOL "" FORCE)
