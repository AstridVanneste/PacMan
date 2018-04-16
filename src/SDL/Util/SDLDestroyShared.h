#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

//https://blog.galowicz.de/2016/02/21/automatic_resource_release_with_sdl/
namespace SDL
{
	static void SDL_Del(SDL_Window* window)
	{
		SDL_DestroyWindow(window);
	}

	static void SDL_Del(SDL_Renderer* renderer)
	{
		SDL_DestroyRenderer(renderer);
	}

	static void SDL_Del(SDL_Surface* surface)
	{
		SDL_FreeSurface(surface);
	}

	static void SDL_Del(SDL_Texture* texture)
	{
		SDL_DestroyTexture(texture);
	}

	static void SDL_Del(TTF_Font* font)
	{
		TTF_CloseFont(font);
	}

	template <typename T>
	shared_ptr<T> SDL_shared(T *t)
	{
		return std::shared_ptr<T>(t, [](T *t)
			{
				SDL_Del(t);
			});
	}

}
