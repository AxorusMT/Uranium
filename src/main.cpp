#include <iostream>
#include <ctime>
#include <SDL2/SDL.h>
#include <glad/glad.h>


int main(int argc, char* argv[])
{
    SDL_Window* window = nullptr;
    std::srand((unsigned)time(NULL));
    float r = (float) rand()/RAND_MAX;
    float g = (float) rand()/RAND_MAX;
    float b = (float) rand()/RAND_MAX;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "cannot init sdl: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "sdl video successfully initalized! " << std::endl;
    }

    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    window = SDL_CreateWindow("First OpenGL app", 0, 0, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    SDL_GLContext context;

    context = SDL_GL_CreateContext(window);

    gladLoadGLLoader(SDL_GL_GetProcAddress);

    

    bool run = true;

    while (run)
    {
        glViewport(0,0,640,480);

        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                run = false;
            }

            if (event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        run = false;
                        break;

                    case SDLK_UP:
                        std::cout << "The up buuton was pressed!" << std::endl;
                        break;

                    case SDLK_DOWN:
                        std::cout << "The down button was pressed!" << std::endl;
                        break;

                    case SDLK_LEFT:
                        std::cout << "The left button was pressed!" << std::endl;
                        break;

                    case SDLK_RIGHT:
                        std::cout << "The right button was pressed" << std::endl;
                        break;
                }
            }


        }
        
        glClearColor(r, g, b, 1.0f);

    
        std::srand((unsigned)time(NULL));
        float r = (float) rand()/RAND_MAX;
        float g = (float) rand()/RAND_MAX;
        float b = (float) rand()/RAND_MAX;

        
        SDL_GL_SetSwapInterval(1);
        //std::cout << std::rand() << std::endl;
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        SDL_Delay(200);

        SDL_GL_SwapWindow(window);
    }

    

    SDL_DestroyWindow(window);

    return 0;
}