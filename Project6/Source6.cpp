//#define _CRT_SECURE_NO_WARNINGS 
//#define kol 1
//#define SCREEN_WIDTH  1280
//#define SCREEN_HEIGHT  720
//#include "SDL.h" 
//#include "math.h" 
//#include "stdio.h" 
//#include<stdio.h> 
//#include<stdlib.h> 
//#include<locale.h> 
//#include <ctime> 
//#include <conio.h> 
//#include <SDL_ttf.h> 
//typedef struct Color
//{
//	int r, g, b;
//}color;
//// прорисока закрашшеного ромба рандомного цвета 
//void random_romb_color(SDL_Window* window, SDL_Renderer* renderer,  SDL_Rect rect, int t)
//{
//		SDL_SetRenderDrawColor(renderer, 125, 50,100, 0);
//	
//	
//			for (int i = 0; i < t; i++)
//			{
//
//				SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.w, rect.h);
//				rect.x++;
//				rect.y++;
//				rect = { rect.x,rect.y,rect.x + t,rect.y - t };
//			}
//}
////прорисовка i количество ромбов различных цветов 
//void romb_color(SDL_Window* window, SDL_Renderer* renderer, int t)
//{
//	for (int i = 0; i < kol; i++)
//	{
//		int x[kol], y[kol];
//		x[i] = rand() % 1000; y[i] = rand() % 600;
//		SDL_Rect rect = { x[i],y[i],x[i] + t,y[i] - t };
//		random_romb_color(window, renderer, rect, t);
//	}
//}
////ф-я создает ромб из координаты x и y размером t
//void romb(SDL_Renderer*renderer, SDL_Rect rect, int t)
//{
//	SDL_SetRenderDrawColor(renderer, 128,128, 128, 0);
//	for (int i = 0; i < t; i++)
//	{
//		SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.w, rect.h);
//		rect.x++;
//		rect.y++;
//		rect = { rect.x,rect.y,rect.x + t,rect.y - t };
//	}
//}
//void romb1(SDL_Window* window,SDL_Renderer*renderer, SDL_Rect rect, int t, Color color[])
//{
//		SDL_SetRenderDrawColor(renderer,color->r, color->g, color->b, 0);
//		for (int i = 0; i < t; i++)
//		{
//
//			SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.w, rect.h);
//			rect.x++;
//			rect.y++;
//			rect = { rect.x,rect.y,rect.x + t,rect.y - t };
//		}
//}
////создает игровое поле 
//void map_ren(SDL_Window* window, SDL_Renderer* renderer, int t,Color color[])
//{
//	//random_color(window, renderer, color);
//	int map[1000][2];
//	FILE*tf;
//	int i;
//	fopen_s(&tf, "map.txt", "r");
//	fscanf_s(tf, "%d", &i);
//	for (int j = 1; j <= i; j++)
//	{
//		fscanf_s(tf, "%d %d ", &map[j][0], &map[j][1]);
//	}
//	fclose(tf);
//	
//	for (int j = 1; j <= i; j++)
//	{
//
//		SDL_Rect rect = { map[j][0] , map[j][1] , map[j][0] + t , map[j][1] - t };
//		romb(renderer, rect, t);
//	}
//	int k = 0;
//	for (int j = rand()%20; j <= i; j+=9)
//	{
//		k++;	
//		SDL_Rect rect = { map[j][0] , map[j][1] , map[j][0] + t , map[j][1] - t };
//		if (k<=kol)
//		romb1(window,renderer, rect, t,&color[k-1]);
//	}
//	int j = rand() % i;
//	SDL_Rect rect1 = { map[j][0],map[j][1],map[j][0] + t,map[j][1] - t };
//	random_romb_color(window, renderer, rect1, t);
//	SDL_RenderPresent(renderer);
//}
//
//////ф-я создает на игровой области пользовательскую карту x и y начальные координаты первого ромба
//void map_create(SDL_Window*window, SDL_Renderer*renderer, SDL_Rect rect, int x, int y, int t)
//{
//	int map[1000][2];
//	int i = 1;
//	int k = 0;
//	int p = 1;
//	map[i][0] = x;
//	map[i][1] = y;
//	SDL_Event event;
//	bool quit = false;
//	while (!quit)
//	{
//		for (int j = 1; j <= p; j++)
//		{
//			if (map[j][0] == x && map[j][1] == y)
//				k++;
//		}
//		if (k == 0)
//		{
//			i++;
//			map[i][0] = x;
//			map[i][1] = y;
//
//		}
//		k = 0;
//		SDL_PollEvent(&event);
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_UP) && (x > t) && (y > 2 * t))
//		{
//			p++;
//			x = x - t; y = y - t;
//			SDL_Rect rect = { x,y,x + t,y - t };
//			romb(renderer, rect, t);
//			SDL_Delay(200);
//		}
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_DOWN) && (x < 1120 - 2 * t) && (y < 560 - 2 * t))
//		{
//			p++;
//			x = x + t; y = y + t;
//			SDL_Rect rect = { x,y,x + t,y - t };
//			romb(renderer, rect, t);
//			SDL_Delay(200);
//		}
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_LEFT) && (x > t) && (y < 560 - 2 * t))
//		{
//			p++;
//			x = x - t; y = y + t;
//			SDL_Rect rect = { x,y,x + t,y - t };
//			romb(renderer, rect, t);
//			SDL_Delay(200);
//		}
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RIGHT) && (x < 1120 - 2 * t) && (y > 2 * t))
//		{
//			p++;
//			x = x + t; y = y - t;
//			SDL_Rect rect = { x,y,x + t,y - t };
//			romb(renderer, rect, t);
//			SDL_Delay(200);
//		}
//		SDL_RenderPresent(renderer);
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_1))
//			quit = true;
//	}
//	FILE*tf;
//	fopen_s(&tf, "map.txt", "w");
//	fprintf(tf, "%d\n", i);
//	for (int j = 1; j <= i; j++)
//	{
//		fprintf(tf, "%d %d\n ", map[j][0], map[j][1]);
//	}
//	fclose(tf);
//
//}
//
//int main(int argc, char** argv)
//{
//	srand(time(NULL));
//	setlocale(LC_ALL, "Russian");
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_Window* window = SDL_CreateWindow(u8"Создователь полей", 7, 29, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 1);
//	SDL_SetRenderDrawColor(renderer, 0, 0,0, 0);
//	SDL_RenderClear(renderer);
//	SDL_RenderPresent(renderer);
//	int t = 50;
//	int x = 50, y = 100;
//	SDL_Rect rect = { x,y,x + t,y - t };
//	Color color[9] = { 255,0,0,0,255,0,0,0,255,255,128,0,255,0,128,128,0,255,255,128,255,
//	128,255,255	,255,255,128 };
//	map_ren(window, renderer, t, color);
//
//	//romb1(window,renderer, rect, t, r);
//	//romb(renderer, rect, t);
//	//map_create(window, renderer, rect, x, y, t);
//	//random_romb_color(window, renderer, rect, t);
//	//romb_color( window,  renderer, t);
//	//setka(window, renderer, t);
//	SDL_Event event;
//	bool quit = false;
//	while (!quit)
//	{
//		SDL_PollEvent(&event);
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_2))
//		{
//			break;
//		}
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_3))
//		{
//			
//			map_ren(window, renderer, t, color);
//	
//		}
//		
//		
//	}
//	SDL_RenderPresent(renderer);
//	/*SDL_Delay(10000);*/
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit;
//	return 0;
//}