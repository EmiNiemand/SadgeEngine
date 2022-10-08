//
// Created by szymo on 07/10/2022.
//

#include "../lib/SadgeEngineUtils.h"

SDL_Texture *Sadge::SadgeEngineUtils::CreateTexture(std::string path, SDL_Renderer *renderer) {
    //The final texture
    SDL_Texture* NewTexture = nullptr;

    //Load image at specified path
    SDL_Surface* LoadedSurface = IMG_Load( path.c_str() );
    if( LoadedSurface == nullptr )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        NewTexture = SDL_CreateTextureFromSurface( renderer, LoadedSurface );
        if( NewTexture == nullptr )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( LoadedSurface );
    }

    return NewTexture;
}

SDL_Rect Sadge::SadgeEngineUtils::CreateRect(int width, int height, int x, int y) {
    SDL_Rect Rect;
    Rect.w = width;
    Rect.h = height;
    Rect.x = x;
    Rect.y = y;
    return Rect;
}
