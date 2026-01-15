#pragma once

#include <any>
#include <string>
#include <unordered_map>
#include <vector>

#include "IAssetLoader.hpp"
#include "IAudio.hpp"
#include "IKeyMapping.hpp"
#include "IRender.hpp"
#include "raylib.h"

namespace Graphic
{
    class Raylib : public Graphic::IAudio,
                   public Graphic::IKeyMapping,
                   public Graphic::IRender,
                   public Graphic::IAssetLoader
    {
        public:
            Raylib();
            ~Raylib();

            /**
             * @brief Initialize the window with given dimensions and title
             *
             * @param width Width of the window
             * @param height Height of the window
             * @param title Title of the window
             */
            void initWindow(int width, int height, std::string const& title) override;

            void closeWindow() override;
            /**
             * @brief Clear the window with a default background color
             *
             */
            void clearWindow() override;

            /**
             * @brief Display the contents of the window
             *
             */
            void displayWindow() override;

            /**
             * @brief Add a key mapping to an action
             *
             * @param key The key to map
             * @param action The action to associate with the key
             */
            void addKeyMapping(int key, std::function<void(Registry&)> action) override;

            /**
             * @brief Add a key released mapping to an action
             *
             * @param key
             * @param action
             */
            void addKeyReleasedMapping(int key, std::function<void(Registry&)> action) override;

            /**
             * @brief Check if the window should close
             *
             * @return true
             * @return false
             */
            bool windowShouldClose() const override;

            /**
             * @brief Add a texture from a file path with a given name and section size
             *
             * @param spritePath  The file path to the texture
             * @param spriteName The name to associate with the texture
             * @param sectionSize The size of the texture section
             */
            void addTexture(std::string const& spritePath, std::string const& spriteName,
                            std::pair<unsigned int, unsigned int> sectionSize) override;

            /**
             * @brief Add a font from a file path with a given name
             *
             * @param fontPath The file path to the font
             * @param fontName The name to associate with the font
             */
            void addFont(std::string const& fontPath, std::string const& fontName) override;

            /**
             * @brief Render a sprite at a given position using a specific section of the texture
             *
             * @param spriteName The name of the texture to render
             * @param position The position to render the sprite at
             * @param spriteSection The section of the texture to use
             * @param sectionSize The size of the texture section
             */
            void renderSprite(std::string const& spriteName, std::pair<float, float> position,
                              std::pair<float, float> spriteSection, std::pair<unsigned int, unsigned int> sectionSize,
                              std::pair<float, float> scale) override;

            /**
             * @brief Render text at a given position with specified font, size, and color
             * @param content The text content to render
             * @param fontName The name of the font to use
             * @param position The (x, y) position to render the text
             * @param size The font size
             * @param color The color of the text as an (R, G, B, A) tuple
             */
            void renderText(const std::string& content, const std::string& fontName, std::pair<float, float> position,
                            int size, std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> color, float spacing) override;

            /**
             * @brief Add a sound from a file path with a given name
             *
             * @param soundPath The file path to the sound
             * @param soundName The name to associate with the sound
             */
            void addSound(std::string const& soundPath, std::string const& soundName) override;

            /**
             * @brief Play a sound by its associated name
             *
             * @param soundName The name of the sound to play
             */
            void playSound(std::string const& soundName) override;

            /**
             * @brief Stop a sound by its associated name
             *
             * @param soundName The name of the sound to stop
             */
            void stopSound(std::string const& soundName) override;

            /**
             * @brief Set volume for a sound by its associated name
             *
             * @param soundName The name of the sound to set volume
             * @param volume The volume level to set maximum 1.0
             */
            void setVolumeSound(std::string const& soundName, float volume) override;

            /**
             * @brief Add a music from a file path with a given name
             *
             * @param musicPath The file path to the music
             * @param musicName The name to associate with the music
             */
            void addMusic(std::string const& musicPath, std::string const& musicName) override;

            /**
             * @brief Play music by its associated name
             *
             * @param musicName The name of the music to play
             */
            void playMusic(std::string const& musicName) override;

            /**
             * @brief Stop music by its associated name
             *
             * @param musicName The name of the music to stop
             */
            void stopMusic(std::string const& musicName) override;

            /**
             * @brief Set volume for a music by its associated name
             *
             * @param musicName The name of the music to set volume
             * @param volume The volume level to set maximum 1.0
             */
            void setVolumeMusic(std::string const& musicName, float volume) override;

            /**
             * @brief Get the Keymap object
             *
             * @return std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>>
             */
            std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>>
            getKeymap() const override;

            /**
             * @brief Get the Key Released Map object
             *
             * @return std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>>
             */
            std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>>
            getKeyReleasedMap() const override;

            /**
             * @brief Get the Key Down Function object
             *
             * @return std::function<bool(int)>
             */
            std::function<bool(int)> getKeyDownFunc() const override;

            /**
             * @brief Get the Key Released Function object
             *
             * @return std::function<bool(int)>
             */
            std::function<bool(int)> getKeyReleasedFunc() const override;

            /**
             * @brief Convert a string representation of a key to its corresponding key code
             *
             * @param keyString The string representation of the key
             * @return int The corresponding key code
             */
            int stringtoKeyCode(const std::string& keyString) const override;

            /**
             * @brief Clear all key mappings
             *
             */
            void clearKeyMappings() override;

            /**
             * @brief Clear all key released mappings
             *
             */
            void clearKeyReleasedMappings() override;

            /**
             * @brief Get the current mouse position
             *
             * @return std::pair<float, float> The (x, y) coordinates of the mouse
             */
            std::pair<float, float> getMousePosition() const override;

            /**
             * @brief Get the current window size
             * @return std::pair<float, float> The (width, height) of the window
             */
            std::pair<float, float> getWindowSize() const;

        private:
            /**
             * @brief A map storing textures with their associated names
             *
             */
            std::unordered_map<std::string, Texture2D> _textures;

            /**
             * @brief A map storing fonts with their associated names
             */
            std::unordered_map<std::string, Font> _fonts;

            /**
             * @brief A map storing sounds with their associated names
             *
             */
            std::unordered_map<std::string, Sound> _sounds;

            /**
             * @brief A map storing musics with their associated names
             *
             */
            std::unordered_map<std::string, Music> _musics;

            /**
             * @brief A map storing key mappings to actions
             *
             */
            std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> _keymap;

            /**
             * @brief A map storing key released mappings to actions
             *
             */
            std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> _keyReleasedMap;
    };
} // namespace Graphic
