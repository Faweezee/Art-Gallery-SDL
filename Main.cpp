#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("3D ART GALLERY", 1280, 720, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    // Surface stored on the CPU
    // Texture stored on the GPU
    SDL_Surface* bg = IMG_Load("../../Users/USER/Downloads/sdl_gallery_bg1.jpg");
    SDL_Surface* frame = IMG_Load("C:/Users/USER/Downloads/sdl_frame4.1-removebg-preview.png");
    SDL_Surface* blender_img1 = IMG_Load("../../Users/USER/Desktop/SCHOOL/200lvl - 2/PAU-CSC 212 - Computer Graphics (CSC)/Software-Engineering-Group-3-BLENDER-FILES/OldSchoolGarage2.png");
    SDL_Surface* blender_img2 = IMG_Load("");
    SDL_Surface* opengl = IMG_Load("C:/Users/USER/Downloads/openGL_image.jpeg");

    SDL_Texture* bg_texture = SDL_CreateTextureFromSurface(renderer, bg);
    SDL_Texture* frame_texture = SDL_CreateTextureFromSurface(renderer, frame);
    SDL_Texture* img1_texture = SDL_CreateTextureFromSurface(renderer, blender_img1);
    SDL_Texture* img2_texture = SDL_CreateTextureFromSurface(renderer, blender_img2);
    SDL_Texture* opengl_texture = SDL_CreateTextureFromSurface(renderer, opengl);

    SDL_DestroySurface(bg);
    SDL_DestroySurface(frame);
    SDL_DestroySurface(blender_img1);
    SDL_DestroySurface(blender_img2);
    SDL_DestroySurface(opengl);

    SDL_FRect backgroundImg = { 0,0,1280,720 };

    SDL_FRect blenderImg1frame = { 55,265,335,195 };
    SDL_FRect blenderImg2frame = { 895,265,335,195 };
    SDL_FRect openGLImgframe = { 475,265,335,195 };

    SDL_FRect blenderImg1 = { 60,270,320,180 };
    SDL_FRect blenderImg2 = { 900,270,320,180 };
    SDL_FRect openGLImg = { 480,270,320,180 };


    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) running = false;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, bg_texture, NULL, &backgroundImg);

        SDL_RenderTexture(renderer, img2_texture, NULL, &blenderImg1);
        SDL_RenderTexture(renderer, frame_texture, NULL, &blenderImg1frame);

        SDL_RenderTexture(renderer, img1_texture, NULL, &blenderImg2);
        SDL_RenderTexture(renderer, frame_texture, NULL, &blenderImg2frame);

        SDL_RenderTexture(renderer, opengl_texture, NULL, &openGLImg);
        SDL_RenderTexture(renderer, frame_texture, NULL, &openGLImgframe);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}