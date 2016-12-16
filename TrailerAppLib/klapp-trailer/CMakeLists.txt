cmake_minimum_required (VERSION 2.7)
project(I3L_TRAILER_APP)

set(CMAKE_MODULE_PATH $ENV{KIVI_CMAKE_MODULE_PATH})
include(hmiappcommon) 

if( ${PLATFORM} MATCHES "X86" )
	message("Building for host configuration....")
	set(PLATFORM_X86 1)
elseif( ${PLATFORM} MATCHES "INFO3LOW")
        message("Building for I3L Target....")
	set(PLATFORM_X86 0)
endif()

# configure a header file to pass some of the CMake settings
# to the source code. This will contain flags for options above
# configure_file (
#   "${PROJECT_SOURCE_DIR}/config.h.in"
#   "${PROJECT_BINARY_DIR}/config.h"
#)

# The version number.
set (TRAILERAPP_VERSION_MAJOR 1)
set (TRAILERAPP_VERSION_MINOR 0)
set (TRAILERAPP_VERSION_PATCH 0)

set(TRAILERAPP_VERSION_STRING ${TRAILERAPP_VERSION_MAJOR}.${TRAILERAPP_VERSION_MINOR}.${TRAILERAPP_VERSION_PATCH})
set(CMAKE_CXX_FLAGS "-Wall -DUSE_IOSTREAM -O -std=c++0x")

#find the relevant packages before we actually include the folders we need
#if (WITH_USTL)
#find_package (ustl)
#endif(WITH_USTL)
find_package (Threads)
find_package (kivi)
find_package (kapi-calsource)
find_package (klapi-appcalibration)

if(PLATFORM_X86)
include_directories(${PROJECT_SOURCE_DIR}/inc/host)
else(PLATFORM_X86)
include_directories(${PROJECT_SOURCE_DIR}/inc/target)
endif(PLATFORM_X86)

include_directories(${SYSROOT})
include_directories(${HMIAPP_COMMON_INCLUDES})
include_directories($ENV{SYSROOT}/usr)
include_directories($ENV{SYSROOT}/usr/include)
include_directories($ENV{SYSROOT}/usr/include/kivi)
include_directories($ENV{SYSROOT}/usr/include/kivi/ipc)
include_directories($ENV{SYSROOT}/usr/include/kapi-hmicore)
include_directories($ENV{SYSROOT}/usr/include/kl-hmicommon)
include_directories($ENV{SYSROOT}/usr/include/kl-lifecycle)
include_directories($ENV{SYSROOT}/usr/include/osconfig/Linux)
include_directories($ENV{SYSROOT}/usr/include/klplatform-adaptor)

set(CMAKE_CXX_FLAGS "-Wall -DUSE_IOSTREAM -O -std=c++0x")

set(LIBS
	#cap	
    	#${CMAKE_DL_LIBS} 
    	#${CMAKE_THREAD_LIBS_INIT}
	#${DBUS_LIBRARY} 
	#${KIVI_CORE_LIB} 		#for kivicore
	#${KIVI_DBUS_LIB} 		#for kividbus
)

# Including direcotries for Host Compilation
if (PLATFORM_X86)
        include_directories(${PROJECT_SOURCE_DIR}/test/unit/simulation/inc)	
	include_directories(${PROJECT_SOURCE_DIR}/inc)
# Including direcotries for Target Compilation
else(PLATFORM_X86)
	include_directories(${PROJECT_SOURCE_DIR}/inc)
endif (PLATFORM_X86)

set(KIVI_SRC_DIR $ENV{KIVI_DIR})

#Files for Host Compilation
if (PLATFORM_X86)
set(SOURCES src/TrailerFactory.cpp src/TrailerLogicManager.cpp src/TrailerScreenManager.cpp 
	    src/ITrailerLogicManager.cpp src/ITrailerScreenManager.cpp test/unit/simulation/src/TrailerSimulation.cpp)
else (PLATFORM_X86)
#Files for Target Compilation
set(SOURCES src/TrailerFactory.cpp src/TrailerLogicManager.cpp src/TrailerScreenManager.cpp 
            src/ITrailerLogicManager.cpp src/ITrailerScreenManager.cpp) 
endif (PLATFORM_X86)

#Making Trailer Library as Shared library
add_library(apptrailer SHARED ${SOURCES})
#set_target_properties(apptrailer PROPERTIES SOVERSION ${TRAILERAPP_VERSION_STRING})

#Linking Libraries with trailer app library
target_link_libraries(apptrailer ${LIBS})

# Path to install shared library
install (TARGETS apptrailer DESTINATION usr/lib/)
