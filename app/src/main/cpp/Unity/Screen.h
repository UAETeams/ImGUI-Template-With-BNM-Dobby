#pragma once
#include <BNM/Class.hpp>

using namespace BNM::Structures::Unity;
using namespace BNM::Structures::Mono;
using namespace BNM;

namespace Unity
{
    namespace Screen
    {
        static BNM::Class Screen;
        static BNM::Property<int> Height;
        static BNM::Property<int> Width;
        static bool is_done = false;

        void Setup()
        {
            Screen = BNM::Class("UnityEngine", "Screen");
            Height = Screen.GetProperty("height");
            Width = Screen.GetProperty("width");
            is_done = true;
        }
    }
}