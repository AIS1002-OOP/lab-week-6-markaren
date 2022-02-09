set(publicHeaderDir ${PROJECT_SOURCE_DIR}/include)

set(publicHeaders
        "${publicHeaderDir}/ais1002/real_random_generator.hpp"
        "${publicHeaderDir}/ais1002/vector3.hpp"
        "${publicHeaderDir}/ais1002/matrix4.hpp"
        )

set(sources
        ais1002/matrix4.cpp
        ais1002/vector3.cpp
        )

add_library(ais1002_lib ${sources} ${publicHeaders})
target_include_directories(ais1002_lib PUBLIC ${publicHeaderDir})
