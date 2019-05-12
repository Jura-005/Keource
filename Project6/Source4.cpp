//#define _CRT_SECURE_NO_WARNINGS 
//
//#include "SDL.h" 
//#include "math.h" 
//#include "stdio.h" 
//#include<stdio.h> 
//#include<stdlib.h> 
//#include<locale.h> 
//#include <ctime> 
//#include <SDL_ttf.h> 
//void drav_shet(SDL_Window* window, SDL_Renderer* &renderer, SDL_Rect rect, int n)
//{
//	char *text = new char[10];
//	_itoa(n, text, 10);
//	TTF_Init();
//	TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);
//	SDL_Color fore_color = { 0,0,0 };
//	SDL_Color back_color = { 255,255,0 };
//	SDL_Rect rect2 = { rect.x + 15,rect.y + 10, rect.w / 3, rect.h / 3 };
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
//void draw_ball(SDL_Window* window, SDL_Renderer* &renderer, SDL_Rect rect)
//{
//	SDL_Surface *myImage = SDL_LoadBMP("1.bmp");
//	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
//	SDL_RenderCopy(renderer, texture, NULL, &rect);
//	SDL_FreeSurface(myImage);
//	SDL_DestroyTexture(texture);
//}
//
//int main(int argc, char** argv)
//{
//	srand(time(NULL));
//	setlocale(LC_ALL, "Russian");
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_Window* window = SDL_CreateWindow(u8"Окно", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
//	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
//	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//	SDL_RenderClear(renderer);
//	SDL_RenderPresent(renderer);
//	SDL_Event event;
//	bool quit = false;
//	int chirx[5];
//	int wx[5], wy[5];
//	int k = 0;
//	char *text = new char[10];
//	_itoa(k, text, 10);
//	draw_text(window, renderer, text);
//	SDL_RenderPresent(renderer);
//	SDL_Rect *ball = new SDL_Rect[5];
//	int a[5];
//	for (int i = 0; i < 5; i++)
//	{
//		int chek = 0;
//		do
//		{
//			chek = 0;
//			do
//			{
//				chirx[i] = rand();
//			} while ((chirx[i] > 80) || (chirx[i] < 30));
//			do
//			{
//				a[i] = rand();
//			} while ((a[i] > 5) || (a[i] < 1));
//			wx[i] = rand() % 720; wy[i] = rand() % 550;
//			int ax, ay;
//			int pointx = 0, pointy = 0;
//			for (int j = 0; j < i; j++)
//			{
//				for (ax = wx[j]; ax <= wx[j] + chirx[j]; ax++)
//				{
//					for (ay = wx[i]; ay <= wx[i] + chirx[i]; ay++)
//					{
//						if (ax == ay)
//							pointx = 1;
//					}
//				}
//			}
//			for (int j = 0; j < i; j++)
//			{
//				for (ax = wy[j]; ax <= wy[j] + chirx[j] / 2 + 13; ax++)
//				{
//					for (ay = wy[i]; ay <= wy[i] + chirx[i] / 2 + 13; ay++)
//					{
//						if (ax == ay)
//							pointy = 1;
//					}
//				}
//			}
//			if (pointx + pointy == 2)
//				chek = 1;
//		} while (chek != 0);
//		ball[i] = { wx[i], wy[i] ,chirx[i] ,chirx[i] / 2 + 13 };
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		draw_ball(window, renderer, ball[i]);
//		drav_shet(window, renderer, ball[i], a[i]);
//	}
//
//	while (!quit)
//	{
//		SDL_PollEvent(&event);
//		if (event.type == SDL_QUIT)
//			quit = true;
//		_itoa(k, text, 10);
//		draw_text(window, renderer, text);
//		SDL_RenderPresent(renderer);
//		if (event.button.button == SDL_BUTTON_LEFT)
//			for (int i = 0; i < 5; i++)
//			{
//				if (event.button.x >= ball[i].x &&
//					event.button.x <= ball[i].x + ball[i].w &&
//					event.button.y >= ball[i].y && event.button.y <= ball[i].y
//					+ ball[i].h)
//				{
//					k += a[i];
//					ball[i].w = 10;
//					ball[i].h = 10;
//					SDL_RenderClear(renderer);
//					SDL_RenderPresent(renderer);
//					SDL_Delay(1000);
//					for (int j = 0; j <5 ; j++)
//					{
//						draw_ball(window, renderer, ball[j]);
//						drav_shet(window, renderer, ball[j], a[j]);
//					}
//				
//					SDL_RenderPresent(renderer);
//					SDL_Delay(1000);
//					int chek = 0;
//					do
//					{
//						chek = 0;
//						do
//						{
//							chirx[i] = rand();
//						} while ((chirx[i] > 80) || (chirx[i] < 30));
//						do
//						{
//							a[i] = rand();
//						} while ((a[i] > 5) || (a[i] < 1));
//						wx[i] = rand() % 720; wy[i] = rand() % 550;
//						int ax, ay;
//						int pointx = 0, pointy = 0;
//						for (int j = 0; j < i; j++)
//						{
//							for (ax = wx[j]; ax <= wx[j] + chirx[j]; ax++)
//							{
//								for (ay = wx[i]; ay <= wx[i] + chirx[i]; ay++)
//								{
//									if (ax == ay)
//										pointx = 1;
//								}
//							}
//						}
//						for (int j = 0; j < i; j++)
//						{
//							for (ax = wy[j]; ax <= wy[j] + chirx[j] / 2 + 10; ax++)
//							{
//								for (ay = wy[i]; ay <= wy[i] + chirx[i] / 2 + 10; ay++)
//								{
//									if (ax == ay)
//										pointy = 1;
//								}
//							}
//						}
//						if (pointx + pointy == 2)
//							chek = 1;
//					} while (chek != 0);
//					ball[i] = { wx[i], wy[i] ,chirx[i] ,chirx[i] / 2 + 10 };
//					draw_ball(window, renderer, ball[i]);
//					drav_shet(window, renderer, ball[i], a[i]);
//					SDL_RenderPresent(renderer);
//				}
//				_itoa(k, text, 10);
//				draw_text(window, renderer, text);
//				SDL_RenderPresent(renderer);
//			}
//	}
//	SDL_Delay(1000);
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit;
//	return 0;
//}