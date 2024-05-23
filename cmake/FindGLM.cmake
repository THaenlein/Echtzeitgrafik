# - Try to find GLM
# Once done, this will define
#
# GLM_FOUND - system has GLM
# GLM_INCLUDE_DIR - the GLM include directories
FIND_PATH( GLM_INCLUDE_DIR glm/glm.hpp
	/usr/include
	/usr/local/include
	/opt/local/include
	"${CMAKE_SOURCE_DIR}/include"
)
IF(GLM_INCLUDE_DIR)
	SET( GLM_FOUND TRUE )
ENDIF(GLM_INCLUDE_DIR)
IF(GLM_FOUND)
	IF(NOT GLM_FIND_QUIETLY)
	MESSAGE(STATUS "Found GLM: ${GLM_INCLUDE_DIR}")
	ENDIF(NOT GLM_FIND_QUIETLY)
ELSE(GLM_FOUND)
	IF(GLM_FIND_REQUIRED)
	MESSAGE(FATAL_ERROR "Could not find GLM include directories")
	ENDIF(GLM_FIND_REQUIRED)
ENDIF(GLM_FOUND)
