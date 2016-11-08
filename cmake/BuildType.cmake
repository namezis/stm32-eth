
if( CMAKE_BUILD_TYPE )
    if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
        set(BUILD_TYPE_DEBUG TRUE)
        set(BUILD_TYPE_VALID TRUE)
    elseif( "${CMAKE_BUILD_TYPE}" STREQUAL "Release" )
        set(BUILD_TYPE_RELEASE TRUE)
        set(BUILD_TYPE_VALID TRUE)
    elseif( "${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo" )
        set(BUILD_TYPE_RELWITHDEBINFO TRUE)
        set(BUILD_TYPE_VALID TRUE)
    elseif( "${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel" )
        set(BUILD_TYPE_MINSIZEREL TRUE)
        set(BUILD_TYPE_VALID TRUE)
    else()
        set(BUILD_TYPE_VALID FALSE)
    endif()
else()
    set(BUILD_TYPE_NONE TRUE)
    set(BUILD_TYPE_VALID TRUE)
endif()


if( NOT ${BUILD_TYPE_VALID} )
    message(STATUS "Warning:\tUnknown build type: '${CMAKE_BUILD_TYPE}'")
endif()
