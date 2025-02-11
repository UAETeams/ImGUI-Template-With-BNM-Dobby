 # ImGui Unity Template based on PolarMod ImGUI Template

ImGui Template that works with Dobby and BNM
   ![image](https://github.com/user-attachments/assets/0a1babbe-8170-4959-954d-de10de245736)

# List of Features
  1. Added latest version of BNM with support upto Unity 6.0.0.0f.
  2: Added latest version of KittyMemory hook.

# How to inject / implement
  1. Extract the lib from your deired Architecture or simply `armeabi-v7a`
  2. Place your lib in correct path of the game.
  3. Load your Lib from `onCreate` of your Game's Mainactivity or UnityPlayerActivity

# How to inject / implement
  1. Extract the lib from your deired Architecture or simply `armeabi-v7a`
  2. Place your lib in correct path of the game.
  3. Load your Lib from `onCreate` of your Game's Mainactivity or UnityPlayerActivity
  
 The main activity of Unity is: ```com/unity/player/UnityPlayerActivity```
   
   ```
   const-string v0, "native-lib"

   invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V
   ```
  Having Doubt?
 ![image](https://user-images.githubusercontent.com/80401984/145727071-26bb7d51-ae83-4fdc-94f5-aa3b9421ed4b.png)

# Recomendations

1. This Project Currently Uses CMake So Better you Use AndroidIDE or Android studio 
2. AIDE i will never recommend to use cause it's systems are not so good at all
3. If you find bugs relating to this project, simply mention on the same repo so that we can improve it

# Notice:
 I am not in any race of releasing first or last but yes i provide the cleaniest sources with proper credit of creators , those who dont have much mind let them keep it doing (your ego is useless in front of this world )
 
# Credits
* PolarMods/PolarImGUI - https://github.com/Polarmods/PolarImGui/tree/main
* Jackknobel/Ocornut - IMGUI : https://github.com/ocornut/imgui
* vvb2060 - DobbyHook - https://github.com/vvb2060/dobby-android
* Ztz - IMGUI template https://github.com/ZTzTopia
* xo1337 - Layout Base : https://www.youtube.com/watch?v=Sn3q7LjG-kA

