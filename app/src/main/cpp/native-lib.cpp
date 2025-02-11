#include <EGL/egl.h> // need to make a common.h that contains all these headers cuz this is nasty
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLES2/gl2platform.h>
#include <fstream>
#include <sstream>
#include "nlohmann/json.hpp"
#include "http/cpr/cpr.h"
#include "Misc/Logging.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_android.h"
#include "ImGui/imgui_impl_opengl3.h"
#include "Obfuscation/Obfuscate.h"
#include <stdio.h>
#include <android/native_window_jni.h>
#include <jni.h>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <dlfcn.h>
#include "Misc/JNIStuff.h"
#include "Misc/FileWrapper.h"
#include "Misc/Utils.h"
#include <BNM/Utils.hpp>
#include "ByNameModding/src/private/Internals.hpp"
#include "Memory/KittyScanner.hpp"
#include "Obfuscation/Custom_Obfuscate.h"
#include "Unity/Unity.h"
#include "Misc/FunctionPointers.h"
#include "Hooking/Hooks.h"
#include "Misc/ImGuiStuff.h"
#include "Menu.h"
#include "Hooking/JNIHooks.h"
#include "Unity/Screen.h"
#include "Memory/KittyMemory.hpp"
#include "Unity/Input.h"
// the private version held by certain polarmodders has image loading and a lot more


KittyScanner::ElfScanner g_il2cppELF{};

void *KittyMemoryFinder(const char *name, void *data) {
    auto &scanner = *(KittyScanner::ElfScanner *) data;
    // auto &scanner = g_il2cppELF;
    return (void *) scanner.findSymbol(name);
}

void Load_BNM_Finder()
{
    BNM::Loading::SetMethodFinder(KittyMemoryFinder, (void *) &g_il2cppELF);

    //BNM::Loading::AllowedLateInitHook();

    g_il2cppELF = KittyScanner::ElfScanner::createWithPath("libil2cpp.so");

    auto result = BNM::Loading::TryLoadByUsersFinder();
    BNM_LOG_DEBUG("07: %d", (int) result);
}

EGLBoolean (*old_eglSwapBuffers)(...);
EGLBoolean new_eglSwapBuffers(EGLDisplay _display, EGLSurface _surface) {
    SetupImGui();
    Menu::DrawImGui();

    return old_eglSwapBuffers(_display, _surface);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void * reserved)
{
    jvm = vm;
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);

    BNM::Loading::TryLoadByJNI(env);

    return JNI_VERSION_1_6;
}

void *hack_thread(void *)
{
    using namespace BNM;

    do {
        sleep(1);
    } while (!IsLoaded());
    AttachIl2Cpp(); // this is required when you use bynamemodding functions
    Unity::Screen::Setup();

    Unity::Input::Setup();

    Pointers::LoadPointers();
    DetachIl2Cpp(); // remember to detach when you are done using bynamemodding functions
    return NULL;
}
__attribute__((constructor))
void lib_main()
{
    auto eglhandle = dlopen(OBFUSCATE("libEGL.so"), RTLD_LAZY);
    const char *dlopen_error = dlerror();
    if (dlopen_error)
    {
        eglhandle = dlopen(OBFUSCATE("libunity.so"), RTLD_LAZY); // I have no idea if this works it was just to me that it would fix crashes so I did it really quickly
    }
    auto eglSwapBuffers = dlsym(eglhandle, OBFUSCATE("eglSwapBuffers"));
    const char *dlsym_error = dlerror();
    if (dlsym_error)
    {
        LOGE(OBFUSCATE("Cannot load symbol 'eglSwapBuffers': %s"), dlsym_error);
    } else
    {
        hook(eglSwapBuffers, (void *) new_eglSwapBuffers, (void **) &old_eglSwapBuffers);
    }

    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}
