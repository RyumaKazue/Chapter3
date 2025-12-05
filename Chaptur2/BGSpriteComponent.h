#pragma once
#include "SpriteComponent.h"
#include "Vector2.h"
#include <vector>

class BGSpriteComponent :
    public SpriteComponent
{
public:
    BGSpriteComponent(class Actor* actor, int drawOrder = 10);
    void SetTextures(const std::vector <SDL_Texture*> textures);
    void Update(float deltaTime) override;
    void Draw(SDL_Renderer* renderer) override;
    void SetScrollSpeed(int scrollSpeed) { mScrollSpeed = scrollSpeed; };
    void SetScreenSize(const int width, const int height) { mScreenSize = Vector2(width, height); }
 private:
    struct BGTexture{
        SDL_Texture* texture;
        Vector2 offset;
    };

    std::vector<BGTexture> mBGTextures;
    Vector2 mScreenSize;
    int mScrollSpeed;
};

