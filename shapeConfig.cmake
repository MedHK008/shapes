get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

set(shape_INCLUDE_DIRS "${PACKAGE_PREFIX_DIR}/include")
set(shape_LIBRARIES "${PACKAGE_PREFIX_DIR}/lib/libshape.so")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(shape DEFAULT_MSG
    shape_INCLUDE_DIRS
    shape_LIBRARIES)