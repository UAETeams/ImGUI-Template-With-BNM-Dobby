//
// Created by letha on 9/4/2021.
// Updated by Tomie on 3/27/2023
//
#include <BNM/Class.hpp>
#include <BNM/Property.hpp>
#include <BNM/Method.hpp>

#ifndef IMGUIANDROID_FUNCTIONPOINTERS_H
#define IMGUIANDROID_FUNCTIONPOINTERS_H

using namespace BNM::Structures::Unity;

namespace Pointers {

    BNM::Class GameObject;
    BNM::Property<void *> GameObject_Transform;

    BNM::Class Transform;
    BNM::Property<Vector3> Transform_Position;

    BNM::Class Camera;
    BNM::Method<Vector3 *> Camera_WorldToScreenPoint;
    BNM::Property<Vector3> Camera_Main;

    void LoadPointers() {
        GameObject = BNM::Class("UnityEngine", "GameObject");
        GameObject_Transform = GameObject.GetProperty("transform");

        Transform = BNM::Class("UnityEngine", "Transform");
        Transform_Position = Transform.GetProperty("position");

        Camera = BNM::Class("UnityEngine", "Camera");
        Camera_WorldToScreenPoint = Camera.GetMethod("WorldToScreenPoint", 1);
        Camera_Main = Camera.GetProperty("main");
    }
}
#endif IMGUIANDROID_FUNCTIONPOINTERS_H
