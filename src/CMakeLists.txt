# Get all directories in current directory
file(GLOB ALL_DIRS "${CMAKE_CURRENT_LIST_DIR}/*")

# Loop through all directories and add those that begin with a number
foreach(DIR ${ALL_DIRS})
    if(IS_DIRECTORY ${DIR})
        get_filename_component(DIR_NAME ${DIR} NAME)
        if(DIR_NAME MATCHES "^[0-9].*")
            list(APPEND TASK_DIRS ${DIR})
        endif()
    endif()
endforeach()

set(TASK_DIRS "${TASK_DIRS}" PARENT_SCOPE)