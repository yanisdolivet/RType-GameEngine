#include "graphic/Raylib.hpp"

#include <iostream>

Graphic::Raylib::Raylib()
{
    SetTraceLogLevel(LOG_NONE);
    SetExitKey(KEY_NULL);

    InitAudioDevice();
    this->_keymap         = std::make_shared<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>>();
    this->_keyReleasedMap = std::make_shared<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>>();
}

Graphic::Raylib::~Raylib()
{
    for (auto& [name, texture] : this->_textures) {
        UnloadTexture(texture);
    }
    for (auto& [name, sound] : this->_sounds) {
        UnloadSound(sound);
    }
    for (auto& [name, music] : this->_musics) {
        UnloadMusicStream(music);
    }
    for (auto& [name, font] : this->_fonts) {
        UnloadFont(font);
    }
    CloseAudioDevice();
    CloseWindow();
}

void Graphic::Raylib::initWindow(int width, int height, std::string const& title)
{
    InitWindow(width, height, title.c_str());
}

void Graphic::Raylib::closeWindow()
{
    CloseWindow();
}

void Graphic::Raylib::clearWindow()
{
    BeginDrawing();
    ClearBackground(BLACK);
}

void Graphic::Raylib::displayWindow()
{
    EndDrawing();
}

bool Graphic::Raylib::windowShouldClose() const
{
    return WindowShouldClose();
}

void Graphic::Raylib::addKeyMapping(int key, std::function<void(Registry&)> action)
{
    this->_keymap->operator[](key).push_back(action);
}

void Graphic::Raylib::addKeyReleasedMapping(int key, std::function<void(Registry&)> action)
{
    this->_keyReleasedMap->operator[](key).push_back(action);
}

void Graphic::Raylib::addTexture(std::string const& spritePath, std::string const& spriteName,
                                 std::pair<unsigned int, unsigned int> sectionSize)
{
    if (this->_textures.find(spriteName) == this->_textures.end()) {
        this->_textures[spriteName] = LoadTexture(spritePath.c_str());
        if (this->_textures[spriteName].id == 0) {
            unsigned int w        = sectionSize.first ? sectionSize.first : 64;
            unsigned int h        = sectionSize.second ? sectionSize.second : 64;
            Color purple          = {255, 0, 255, 255};
            Image img             = GenImageChecked((int)w, (int)h, 4, 4, BLACK, purple);
            Texture2D placeholder = LoadTextureFromImage(img);
            UnloadImage(img);
            this->_textures[spriteName] = placeholder;
        }
    }
}

void Graphic::Raylib::addFont(std::string const& fontPath, std::string const& fontName)
{
    if (this->_fonts.find(fontName) == this->_fonts.end()) {
        this->_fonts[fontName] = LoadFont(fontPath.c_str());
    }
}

void Graphic::Raylib::renderSprite(std::string const& spriteName, std::pair<float, float> position,
                                   std::pair<float, float> spriteSection,
                                   std::pair<unsigned int, unsigned int> sectionSize, std::pair<float, float> scale)
{
    if (this->_textures.find(spriteName) == this->_textures.end()) {
        unsigned int w        = sectionSize.first == 0 ? 64 : sectionSize.first;
        unsigned int h        = sectionSize.second == 0 ? 64 : sectionSize.second;
        Color purple          = {255, 0, 255, 255};
        Image img             = GenImageChecked((int)w, (int)h, 8, 8, BLACK, purple);
        Texture2D placeholder = LoadTextureFromImage(img);
        UnloadImage(img);
        this->_textures[spriteName] = placeholder;
    }

    const Texture2D& texture = this->_textures[spriteName];

    if (sectionSize.first == 0 || sectionSize.second == 0) {
        DrawTexture(texture, (int)position.first, (int)position.second, WHITE);
        return;
    }
    float frameW = (float)sectionSize.first;
    float frameH = (float)sectionSize.second;

    Rectangle sourceRect;
    sourceRect         = {spriteSection.first, spriteSection.second, frameW, frameH};
    Rectangle destRect = {position.first, position.second, frameW * scale.first, frameH * scale.second};
    DrawTexturePro(texture, sourceRect, destRect, {0.f, 0.f}, 0.f, WHITE);
}

void Graphic::Raylib::renderText(const std::string& content, const std::string& fontName,
                                 std::pair<float, float> position, int size,
                                 std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> color, float spacing)
{
    Vector2 pos     = {position.first, position.second};
    Color textColor = {std::get<0>(color), std::get<1>(color), std::get<2>(color), std::get<3>(color)};

    if (this->_fonts.find(fontName) == this->_fonts.end()) {
        // Font not found
        DrawText(content.c_str(), pos.x, pos.y, size, textColor);
        return;
    }
    const Font& font = this->_fonts[fontName];
    DrawTextEx(font, content.c_str(), pos, size, spacing, textColor);
}

void Graphic::Raylib::addSound(std::string const& soundPath, std::string const& soundName)
{
    if (this->_sounds.find(soundName) == this->_sounds.end()) {
        this->_sounds[soundName] = LoadSound(soundPath.c_str());
    }
}

void Graphic::Raylib::playSound(std::string const& soundName)
{
    if (this->_sounds.find(soundName) != this->_sounds.end()) {
        PlaySound(this->_sounds[soundName]);
    }
}

void Graphic::Raylib::stopSound(std::string const& soundName)
{
    if (this->_sounds.find(soundName) != this->_sounds.end()) {
        StopSound(this->_sounds[soundName]);
    }
}

void Graphic::Raylib::setVolumeSound(std::string const& soundName, float volume)
{
    if (this->_sounds.find(soundName) != this->_sounds.end()) {
        SetSoundVolume(this->_sounds[soundName], volume);
    }
}

void Graphic::Raylib::addMusic(std::string const& musicPath, std::string const& musicName)
{
    if (this->_musics.find(musicName) == this->_musics.end()) {
        this->_musics[musicName] = LoadMusicStream(musicPath.c_str());
    }
}

void Graphic::Raylib::playMusic(std::string const& musicName)
{
    if (this->_musics.find(musicName) != this->_musics.end()) {
        PlayMusicStream(this->_musics[musicName]);
    }
}

void Graphic::Raylib::stopMusic(std::string const& musicName)
{
    if (this->_musics.find(musicName) != this->_musics.end()) {
        StopMusicStream(this->_musics[musicName]);
    }
}

void Graphic::Raylib::setVolumeMusic(std::string const& musicName, float volume)
{
    if (this->_musics.find(musicName) != this->_musics.end()) {
        SetMusicVolume(this->_musics[musicName], volume);
    }
}

std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>> Graphic::Raylib::getKeymap() const
{
    return this->_keymap;
}

std::shared_ptr<std::unordered_map<int, std::vector<std::function<void(Registry&)>>>>
Graphic::Raylib::getKeyReleasedMap() const
{
    return this->_keyReleasedMap;
}

std::function<bool(int)> Graphic::Raylib::getKeyDownFunc() const
{
    return [](int key) {
        // Check if the key is a mouse button
        if (key >= MOUSE_BUTTON_LEFT && key <= MOUSE_BUTTON_FORWARD) {
            return IsMouseButtonDown(key);
        }
        return IsKeyDown(key);
    };
}

std::function<bool(int)> Graphic::Raylib::getKeyReleasedFunc() const
{
    return [](int key) {
        // Check if the key is a mouse button
        if (key >= MOUSE_BUTTON_LEFT && key <= MOUSE_BUTTON_FORWARD) {
            return IsMouseButtonReleased(key);
        }
        return IsKeyReleased(key);
    };
}

int Graphic::Raylib::stringtoKeyCode(const std::string& keyString) const
{
    static const std::unordered_map<std::string, int> keyMap = {{"KEY_A", KEY_A},
                                                                {"KEY_B", KEY_B},
                                                                {"KEY_C", KEY_C},
                                                                {"KEY_D", KEY_D},
                                                                {"KEY_Q", KEY_Q},
                                                                {"KEY_S", KEY_S},
                                                                {"KEY_W", KEY_W},
                                                                {"KEY_Z", KEY_Z},
                                                                {"SPACE", KEY_SPACE},
                                                                {"KEY_ESCAPE", KEY_ESCAPE},
                                                                {"KEY_UP", KEY_UP},
                                                                {"KEY_DOWN", KEY_DOWN},
                                                                {"KEY_LEFT", KEY_LEFT},
                                                                {"KEY_RIGHT", KEY_RIGHT},
                                                                {"LEFTCLICK", MOUSE_BUTTON_LEFT},
                                                                {"MOUSE_RIGHT_BUTTON", MOUSE_BUTTON_RIGHT}};

    auto it = keyMap.find(keyString);
    if (it == keyMap.end())
        throw std::runtime_error("Raylib: unknown key '" + keyString + "'");

    return it->second;
}

void Graphic::Raylib::clearKeyMappings()
{
    this->_keymap->clear();
}

void Graphic::Raylib::clearKeyReleasedMappings()
{
    this->_keyReleasedMap->clear();
}

std::pair<float, float> Graphic::Raylib::getMousePosition() const
{
    Vector2 mousePos = GetMousePosition();
    return std::make_pair(mousePos.x, mousePos.y);
}

std::pair<float, float> Graphic::Raylib::getWindowSize() const
{
    return std::make_pair((float)GetScreenWidth(), (float)GetScreenHeight());
}
