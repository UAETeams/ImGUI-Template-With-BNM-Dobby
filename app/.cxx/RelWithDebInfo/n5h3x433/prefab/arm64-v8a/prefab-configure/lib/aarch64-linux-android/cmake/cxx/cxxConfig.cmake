if(NOT TARGET cxx::cxx)
add_library(cxx::cxx STATIC IMPORTED)
set_target_properties(cxx::cxx PROPERTIES
    IMPORTED_LOCATION "C:/Users/Ghani/.gradle/caches/transforms-3/5b2dcb2ddb42ea1df7bf740ba844d454/transformed/cxx-1.2.0/prefab/modules/cxx/libs/android.arm64-v8a/libcxx.a"
    INTERFACE_INCLUDE_DIRECTORIES "C:/Users/Ghani/.gradle/caches/transforms-3/5b2dcb2ddb42ea1df7bf740ba844d454/transformed/cxx-1.2.0/prefab/modules/cxx/include"
    INTERFACE_LINK_LIBRARIES ""
)
endif()

