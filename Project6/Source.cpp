//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <SDL.h>
//#include <time.h>
//#include <SDL_ttf.h>
//
//struct Circle 
//{
//	SDL_Rect rect;
//	int b;
//	int rad;
//	double angle;
//};
//
//SDL_Texture* DrawText(SDL_Window* window, SDL_Renderer* &renderer, char*text) {
//	TTF_Init();
//	SDL_Texture *textTexture;
//	TTF_Font* my_font = TTF_OpenFont("text.ttf", 100);
//	SDL_Color fore_color = { 250,250,250 };
//	SDL_Color back_color = { 0,0,0 };
//	SDL_Surface* textSurface = NULL;
//	textSurface = TTF_RenderText_Shaded(my_font, text, fore_color, back_color);
//	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//	TTF_CloseFont(my_font);
//	return textTexture;
//}
//
//void DrawCircle(SDL_Renderer* &renderer, Circle* circle)
//{
//	SDL_Surface *IMAGE = SDL_LoadBMP("1.bmp");
//	SDL_SetColorKey(IMAGE, SDL_TRUE, SDL_MapRGB(IMAGE->format, 255, 255, 255));
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, IMAGE);
//	SDL_RenderCopy(renderer, texture, NULL, &circle->rect);
//	SDL_DestroyTexture(texture);
//}
//void UpdateCircle(Circle* circle, SDL_Rect centreRect) {
//	if (circle->b == 0) return;
//	if (circle->angle > 8 * M_PI) circle->angle -= 4 * M_PI;
//	circle->rect.x = centreRect.x + circle->rad * cos(circle->angle);
//	circle->rect.y = centreRect.y + circle->rad * sin(circle->angle);
//	circle->rect.h = circle->rect.w = circle->rect.w - 10 + rand() % 20;
//	if (circle->rect.w < 50) circle->rect.h = circle->rect.w = 50;
//	if (circle->rect.w > 150) circle->rect.h = circle->rect.w = 150;
//}
//
//void GenerateCircle(Circle* circle, SDL_Rect centreRect) {
//	if (circle->b == 1) return;
//	circle->b = 1;
//	circle->rad =50 + rand() % 200;
//	circle->rect = { int(centreRect.x + circle->rad * cos(circle->angle)), int(centreRect.y + circle->rad * sin(circle->angle)) };
//	circle->rect.h = circle->rect.w = 50 + rand() % 100;
//}
//int main(int argc, char* argv[]) {
//
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_Window* window = SDL_CreateWindow("22", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
//	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 1);
//	int b = 1, k = 0, k2 = 0;
//	char *text = new char[10];
//	SDL_Event event;
//	Circle *circle = new Circle[5];
//	SDL_Surface* screenSurface = NULL;
//	SDL_Surface* textSurface = NULL;
//	SDL_Rect countRect = { 0, 0, 15, 20 };
//	SDL_Rect centreRect = { 300, 300, 0, 0 };
//	SDL_Texture *textTexture;
//	srand(time(NULL));
//	while (b) 
//	{
//		SDL_PollEvent(&event);
//		if (event.type == SDL_QUIT) b = 0;
//		if (event.button.button == SDL_BUTTON_LEFT) {
//
//			for (int i = 0; i < 5; i++) {
//				if (event.button.x >= circle[i].rect.x && event.button.x <= circle[i].rect.x + circle[i].rect.w && event.button.y >= circle[i].rect.y && event.button.y <= circle[i].rect.y + circle[i].rect.h) {
//					circle[i].b = 0;
//					k++;
//				}
//			}
//		}
//		SDL_RenderClear(renderer);
//		for (int i = 0; i < 5; i++)
//		{
//			GenerateCircle(&circle[i], centreRect);
//	
//			DrawCircle(renderer, &circle[i]);
//		}
//		k2 = k;
//		countRect.w = 0;
//		do {
//			countRect.w += 15;
//			k2 /= 10;
//		} while (k2 > 0);
//		_itoa(k, text, 10);
//		textTexture = DrawText(window, renderer, text);
//		SDL_RenderCopy(renderer, textTexture, NULL, &countRect);
//		SDL_RenderPresent(renderer);
//		SDL_Delay(10);
//	}
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit();
//	return 0;
//}
//
