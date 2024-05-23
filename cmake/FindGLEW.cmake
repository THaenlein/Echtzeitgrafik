# - Try to find Glew
# Once done, this will define
#
# GLEW_FOUND - system has Glew
# GLEW_INCLUDE_DIR - the Glew include directories
# GLEW_LIBRARIES - link these to use Glew
FIND_PATH( GLEW_INCLUDE_DIR GL/glew.h
	/usr/include
	/usr/local/include
	/opt/local/include
	"${CMAKE_SOURCE_DIR}/include"
)
FIND_LIBRARY( GLEW_LIBRARY glew32s
	/usr/lib64
	/usr/lib
	/usr/local/lib
	/opt/local/lib
	"${CMAKE_SOURCE_DIR}/lib"
)
IF(GLEW_INCLUDE_DIR AND GLEW_LIBRARY)
	SET( GLEW_FOUND TRUE )
	SET( GLEW_LIBRARIES ${GLEW_LIBRARY} )
ENDIF(GLEW_INCLUDE_DIR AND GLEW_LIBRARY)
IF(GLEW_FOUND)
	IF(NOT GLEW_FIND_QUIETLY)
	MESSAGE(STATUS "Found GLEW: ${GLEW_LIBRARY}")
	ENDIF(NOT GLEW_FIND_QUIETLY)
ELSE(GLEW_FOUND)
	IF(GLEW_FIND_REQUIRED)
	MESSAGE(FATAL_ERROR "Could not find libGLEW")
	ENDIF(GLEW_FIND_REQUIRED)
ENDIF(GLEW_FOUND)
