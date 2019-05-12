//////вставка картинки
////void kartinka(SDL_Window* window, SDL_Renderer* renderer)
////{
////	SDL_Surface* screenSurface = NULL;
////	screenSurface = SDL_GetWindowSurface(window);
////	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));
////	SDL_Surface *myImage = SDL_LoadBMP("2.bmp");
////	if (myImage == NULL)
////	{
////		printf_s("error");
////	}
////	SDL_Rect dest;
////	dest.x = 1200 - myImage->w;
////	dest.y = 720 - myImage->h;
////	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
////	SDL_BlitSurface(myImage, NULL, screenSurface, &dest);
////	SDL_UpdateWindowSurface(window);
////}
////
//////прорисовка сетки 
////void setka(SDL_Window* window, SDL_Renderer* renderer, int t)
////{
////	for (int i = 0; i <= 10000; i += t)
////	{
////		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
////		SDL_RenderDrawLine(renderer, 0 + i, t - i, t * 250 + i, t * 251 - i);
////	}
////	for (int i = 0; i <= 10000; i += t)
////	{
////		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
////		SDL_RenderDrawLine(renderer, 0 - i, t + i, t * 250 - i, t * 251 + i);
////	}
////
////	for (int i = 0; i <= 20000; i += t)
////	{
////		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
////		SDL_RenderDrawLine(renderer, t*-130 + i, t * 3 + i, t * 3 + i, t*-130 + i);
////
////	}
////}