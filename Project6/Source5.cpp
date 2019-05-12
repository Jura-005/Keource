//#define _CRT_SECURE_NO_WARNINGS
//
//#include "math.h"
//#include <iostream>
//#include <SDL.h>
//#include <time.h>
//#include <SDL_ttf.h>
//#include "stdlib.h"
//
//typedef struct Ball
//{
//	int x, y, w, h;
//	SDL_Rect rect;
//	int b;
//	int rad;
//	int  angle;
//}ball;
//void drav_shet(SDL_Window* window, SDL_Renderer* &renderer, Ball *ball, int n)
//{
//	char *text = new char[10];
//	_itoa(n, text, 10);
//	TTF_Init();
//	TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);
//	SDL_Color fore_color = { 0,0,0 };
//	SDL_Color back_color = { 255,255,0 };
//	SDL_Rect rect2 = { ball->x + 15, ball->y + 10,  ball->w / 3,  ball->h / 3 };
//	SDL_Surface* textSurface = NULL;
//	textSurface = TTF_RenderText_Shaded(my_font, text, fore_color, back_color);
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
//	SDL_RenderCopy(renderer, texture, NULL, &rect2);
//	SDL_DestroyTexture(texture);
//	TTF_CloseFont(my_font);
//	TTF_Quit();
//}
//void draw_text(SDL_Window* window, SDL_Renderer* &renderer, char*text)
//{
//	TTF_Init();
//	TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);
//	SDL_Color fore_color = { 130,140,50 };
//	SDL_Color back_color = { 0,0,0 };
//	SDL_Surface* textSurface = NULL;
//	textSurface = TTF_RenderText_Shaded(my_font, text, fore_color, back_color);
//	SDL_Rect rect = { 0,0, 30, 30 };
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
//	SDL_RenderCopy(renderer, texture, NULL, &rect);
//	SDL_DestroyTexture(texture);
//	TTF_CloseFont(my_font);
//	TTF_Quit();
//}
//
//void draw_ball(SDL_Renderer* &renderer, Ball *ball)
//{
//
//	SDL_Surface *myImage = SDL_LoadBMP("1.bmp");
//	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
//	SDL_RenderCopy(renderer, texture, NULL, &ball->rect);
//}
//void GenerateCircle(Ball *ball, SDL_Rect centreRect, SDL_Renderer* &renderer, SDL_Rect  countRect)
//{
//
//	if (ball->b == 1) return;
//	ball->b = 1;
//	ball->rad = 50 + rand() % 200;
//	ball->angle = rand() % int(M_PI * 4);
//	ball->rect = { int(centreRect.x + ball->rad * cos(ball->angle)) ,int(centreRect.y + ball->rad * sin(ball->angle)) };
//	ball->rect.h = ball->rect.w = 50 + rand() % 100;
//}
//
//
//int main(int argc, char* argv[])
//{
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_Window* window = SDL_CreateWindow(u8"Окно", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
//	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 1);
//	SDL_Event event;
//	bool quit = false;
//	int k = 0, k2 = 0;
//	srand(time(NULL));
//	char *text = new char[10];
//	Ball *ball = new Ball[5];
//	_itoa(k, text, 10);
//	draw_text(window, renderer, text);
//	SDL_RenderPresent(renderer);
//	SDL_Rect Rect = { 50, 0, 100,100 };
//	SDL_Rect countRect = { 0, 0, 15, 20 };
//	SDL_Rect centreRect = { 300, 300, 0, 0 };
//	int a[5];
//
//	for (int i = 0; i < 5; i++)
//	{
//		do
//		{
//			a[i] = rand() % 10;
//		} while ((a[i] > 5) || (a[i] < 1));
//		SDL_Rect countRect = { rand() % 200,rand() % 300 ,50 + 10 * i,50 + 10 * i };
//		ball[i] = { rand() % 200,rand() % 300 ,50 + 10 * i,50 + 10 * i };
//		draw_ball(renderer, &ball[i]);
//
//		SDL_RenderPresent(renderer);
//	}
//
//	while (!quit)
//	{
//		SDL_PollEvent(&event);
//		if (event.type == SDL_QUIT)
//			quit = true;
//
//
//		if (event.button.button == SDL_BUTTON_LEFT)
//		{
//			for (int i = 0; i < 5; i++)
//			{
//
//				if (event.button.x >= ball[i].rect.x && event.button.x <= ball[i].rect.x + ball[i].rect.w
//					&& event.button.y >= ball[i].rect.y && event.button.y <= ball[i].rect.y + ball[i].rect.h)
//
//				{
//					k += a[i];
//					ball[i].b = 0;
//					ball[i].rect.w = 0;
//					ball[i].rect.h = 0;
//
//
//				}
//
//			}
//		}
//		SDL_RenderClear(renderer);
//		for (int i = 0; i < 5; i++)
//		{
//			draw_ball(renderer, &ball[i]);
//			drav_shet(window, renderer, &ball[i], a[i]);
//			GenerateCircle(&ball[i], centreRect, renderer, countRect);
//			SDL_RenderPresent(renderer);
//		}
//
//		k2 = k;
//		countRect.w = 0;
//		do {
//			countRect.w += 15;
//			k2 /= 10;
//		} while (k2 > 0);
//		_itoa(k, text, 10);
//		draw_text(window, renderer, text);
//		SDL_RenderPresent(renderer);
//
//		SDL_Delay(20);
//	}
//	system("pause");
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit();
//	return 0;
//}