cmake_minimum_required(VERSION 3.4.1)

set(KITTYMEMORY_PATH Memory)
file(GLOB KITTYMEMORY_SRC ${KITTYMEMORY_PATH}/*.cpp)

set(KEYSTONE_LIB ${CMAKE_CURRENT_SOURCE_DIR}/Memory/Deps/Keystone/libs-android/${CMAKE_ANDROID_ARCH_ABI}/libkeystone.a)

add_subdirectory(ByNameModding EXCLUDE_FROM_ALL)

get_property(BNM_INCLUDE_DIRECTORIES TARGET BNM PROPERTY BNM_INCLUDE_DIRECTORIES)

add_library(
             native-lib
             SHARED
             ${KITTYMEMORY_SRC}
             native-lib.cpp
             ImGui/imgui.cpp
             ImGui/imgui_impl_android.cpp
             ImGui/imgui_impl_opengl3.cpp
             ImGui/imgui_tables.cpp
             ImGui/imgui_widgets.cpp
             ImGui/imgui_demo.cpp
             ImGui/imgui_draw.cpp
        http/cpr/async.cpp
        http/cpr/auth.cpp
        http/cpr/bearer.cpp
        http/cpr/cookies.cpp
        http/cpr/cprtypes.cpp
        http/cpr/curl_container.cpp
        http/cpr/curlholder.cpp
        http/cpr/error.cpp
        http/cpr/multipart.cpp
        http/cpr/parameters.cpp
        http/cpr/payload.cpp
        http/cpr/proxies.cpp
        http/cpr/proxyauth.cpp
        http/cpr/session.cpp
        http/cpr/threadpool.cpp
        http/cpr/timeout.cpp
        http/cpr/unix_socket.cpp
        http/cpr/util.cpp
        http/cpr/response.cpp
        http/cpr/redirect.cpp
        http/cpr/interceptor.cpp
        Obfuscation/instr.cpp
        ByNameModding/src/Class.cpp
        ByNameModding/src/ClassesManagement.cpp
        ByNameModding/src/Coroutine.cpp
        ByNameModding/src/Defaults.cpp
        ByNameModding/src/Delegates.cpp
        ByNameModding/src/EventBase.cpp
        ByNameModding/src/Exceptions.cpp
        ByNameModding/src/FieldBase.cpp
        ByNameModding/src/Hooks.cpp
        ByNameModding/src/Image.cpp
        ByNameModding/src/Internals.cpp
        ByNameModding/src/Loading.cpp
        ByNameModding/src/MethodBase.cpp
        ByNameModding/src/MonoStructures.cpp
        ByNameModding/src/PropertyBase.cpp
        ByNameModding/src/UnityStructures.cpp
        ByNameModding/src/Utils.cpp)


find_library(log-lib log)
find_library(egl EGL)
find_library(android android)
find_library(GLESV2_LIB GLESv2)
find_library(LZ_LIB z)
find_package(curl REQUIRED CONFIG)
if (${ANDROID_PLATFORM_LEVEL} LESS 12)
    message(FATAL_ERROR "OpenGL 2 is not supported before API level 11 /
                      (currently using ${ANDROID_PLATFORM_LEVEL}).")
    return()
elseif (${ANDROID_PLATFORM_LEVEL} LESS 18)
    add_definitions("-DDYNAMIC_ES3")
    set(GL3STUB_SRC gl3stub.c)
    set(OPENGL_LIB GLESv2)
else ()
    set(OPENGL_LIB GLESv3)
endif (${ANDROID_PLATFORM_LEVEL} LESS 12)

    set(DOBBY_LIB ${CMAKE_CURRENT_SOURCE_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI}/libdobby.a)

target_include_directories(
        native-lib
        PUBLIC
        ${BNM_INCLUDE_DIRECTORIES}
)

target_link_libraries(
        native-lib
        ${KEYSTONE_LIB}
        BNM
        ${LZ_LIB}
        ${DOBBY_LIB}
        ${OPENGL_LIB}
        ${GLESV2_LIB}
        ${android}
        ${egl}
        ${log-lib}
        curl::curl_static)