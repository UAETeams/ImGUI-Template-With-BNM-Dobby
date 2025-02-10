if(NOT TARGET dobby::dobby)
add_library(dobby::dobby STATIC IMPORTED)
set_target_properties(dobby::dobby PROPERTIES
    IMPORTED_LOCATION "C:/Users/Ghani/.gradle/caches/transforms-3/633fc6be940266cfde4e43ab831750a5/transformed/dobby-1.2/prefab/modules/dobby/libs/android.armeabi-v7a/libdobby.a"
    INTERFACE_INCLUDE_DIRECTORIES "C:/Users/Ghani/.gradle/caches/transforms-3/633fc6be940266cfde4e43ab831750a5/transformed/dobby-1.2/prefab/modules/dobby/include"
    INTERFACE_LINK_LIBRARIES ""
)
endif()

