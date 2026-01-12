/*
** EPITECH PROJECT, 2025
** R-Type
** File description:
** InitActionInput
*/

#include "InitActionInput.hpp"

#include "CoreEvents.hpp"

std::unordered_map<std::string, ActionBinding> getActionBindings()
{
    return {{"MoveUp",
             {.onPress =
                  [](Registry& r) {
                      r.publish(EventUp{true});
                  },
              .onRelease =
                  [](Registry& r) {
                      r.publish(EventUp{false});
                  }}},
            {"MoveDown",
             {.onPress =
                  [](Registry& r) {
                      r.publish(EventDown{true});
                  },
              .onRelease =
                  [](Registry& r) {
                      r.publish(EventDown{false});
                  }}},
            {"MoveLeft",
             {.onPress =
                  [](Registry& r) {
                      r.publish(EventLeft{true});
                  },
              .onRelease =
                  [](Registry& r) {
                      r.publish(EventLeft{false});
                  }}},
            {"MoveRight",
             {.onPress =
                  [](Registry& r) {
                      r.publish(EventRight{true});
                  },
              .onRelease =
                  [](Registry& r) {
                      r.publish(EventRight{false});
                  }}},
            {"ExitGame",
             {[](Registry& registry) {
                  registry.publish(EventGameExit{});
              },
              nullptr}},
            {"LeftClick",
             {.onPress = nullptr,
              .onRelease =
                  [](Registry& r) {
                      r.publish(EventLeftClick{});
                  }}},
            {"Shoot",
             {// ! Maybe change but currently neeed network id at the time of binding
              nullptr, nullptr}}};
}