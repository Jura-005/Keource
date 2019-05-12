//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <SDL.h>
//#include <time.h>
//#include <SDL_ttf.h>
//
////Некоторые константы нашего окна
//const int SCREEN_WIDTH = 600;//ширина
//const int SCREEN_HEIGHT = 600;//высота
//
//static SDL_Surface *IMAGE = SDL_LoadBMP("1.bmp");
//
////ЛР23
//
////задание 1
//
////структура шара
//struct Circle {
//	SDL_Rect rect;//координаты
//	int b;//проверка рисования шара
//	int rad;//радиус траектории
//	double speed;//скорость шара
//	double angle;//положение шара относительно центра координат
//};
////возвращает шрифт из text
//SDL_Texture* DrawText(SDL_Window* window, SDL_Renderer* &renderer, char*text) {
//	TTF_Init();//инициализация работы с текстом
//	SDL_Texture *textTexture;
//	TTF_Font* my_font = TTF_OpenFont("text.ttf", 100);//загрузка шрифта
//	if (my_font == NULL) {//проверка загрузки шрифта
//		printf_s("%s\n", TTF_GetError());
//		getchar();
//		getchar();
//	}
//	SDL_Color fore_color = { 250,250,250 };//цвет шрифта
//	SDL_Color back_color = { 0,0,0 };//фон шрифта
//	SDL_Surface* textSurface = NULL;
//	textSurface = TTF_RenderText_Shaded(my_font, text, fore_color, back_color);//создание области прориовки шрифта
//	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//	TTF_CloseFont(my_font);
//	return textTexture;
//}
////рисование шара
//void DrawCircle(SDL_Renderer* &renderer, Circle* circle)
//{
//	if (circle->b == 0) return;
//	SDL_SetColorKey(IMAGE, SDL_TRUE, SDL_MapRGB(IMAGE->format, 255, 255, 255));
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, IMAGE);
//	SDL_RenderCopy(renderer, texture, NULL, &circle->rect);
//	SDL_DestroyTexture(texture);
//}
////генерация шара
//void GenerateCircle(Circle* circle, SDL_Rect centreRect) {
//	if (circle->b == 1) return;
//	circle->b = 1;
//	circle->rad = 50 + rand() % 200;
//	circle->speed = (-25 + rand() % 50) / 100.0;
//	circle->angle = rand() % int(M_PI * 4);
//	circle->rect = { int(centreRect.x + circle->rad * cos(circle->angle)), int(centreRect.y + circle->rad * sin(circle->angle)) };
//	circle->rect.h = circle->rect.w = 50 + rand() % 100;
//}
////обновление позиции шара
//void UpdateCircle(Circle* circle, SDL_Rect centreRect) {
//	if (circle->b == 0) return;
//	circle->angle += circle->speed;
//	if (circle->angle > 8 * M_PI) circle->angle -= 4 * M_PI;
//	circle->rect.x = centreRect.x + circle->rad * cos(circle->angle);
//	circle->rect.y = centreRect.y + circle->rad * sin(circle->angle);
//	circle->rect.h = circle->rect.w = circle->rect.w - 10 + rand() % 20;
//	if (circle->rect.w < 50) circle->rect.h = circle->rect.w = 50;
//	if (circle->rect.w > 150) circle->rect.h = circle->rect.w = 150;
//}
//
//int main(int argc, char* argv[]) {
//
//	int b = 1;
//	char *text = new char[10];
//	int k = 0;
//	int k2 = 0;
//	SDL_Event event;
//	Circle *circle = new Circle[5];
//	SDL_Window* window = NULL;
//	SDL_Renderer* renderer;
//	SDL_Surface* screenSurface = NULL;
//	SDL_Surface* textSurface = NULL;
//	SDL_Rect countRect = { 0, 0, 15, 20 };
//	SDL_Rect centreRect = { 300, 300, 0, 0 };
//	SDL_Texture *textTexture;
//	srand(time(NULL));
//
//
//	////Включим SDL
//	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//		printf("SDL не смог запуститься! SDL_Error: %s\n", SDL_GetError());
//		getchar();
//		getchar();
//		return 1;
//	}
//	//Создаем окно
//	window = SDL_CreateWindow(u8"Шульга", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//	if (window == NULL) {
//		printf("Окно не может быть создано! SDL_Error: %s\n", SDL_GetError());
//		SDL_Quit();
//		getchar();
//		getchar();
//		return 2;
//	}
//	//Создаем рисовальщик
//	renderer = SDL_CreateRenderer(window, -1, 0);
//	if (renderer == NULL) {
//		printf("Renderer не может быть создан! SDL_Error: %s\n", SDL_GetError());
//		SDL_DestroyWindow(window);
//		SDL_Quit();
//		getchar();
//		getchar();
//		return 3;
//	}
//
//	//основной цикл
//	while (b) {
//		//close app
//		SDL_PollEvent(&event);
//		if (event.type == SDL_QUIT) b = 0;
//
//		//обработка нажатия ЛКМ
//		if (event.button.button == SDL_BUTTON_LEFT) {
//
//			for (int i = 0; i < 5; i++) {
//				if (event.button.x >= circle[i].rect.x && event.button.x <= circle[i].rect.x + circle[i].rect.w && event.button.y >= circle[i].rect.y && event.button.y <= circle[i].rect.y + circle[i].rect.h) {
//					circle[i].b = 0;
//					k++;
//				}
//			}
//		}
//		//обработка фона
//		SDL_RenderClear(renderer);
//
//		//обработка кругов
//		for (int i = 0; i < 5; i++)
//		{
//			GenerateCircle(&circle[i], centreRect);
//			UpdateCircle(&circle[i], centreRect);
//			DrawCircle(renderer, &circle[i]);
//		}
//		//подсчет ширины строки счетчика нажатий на круги
//		k2 = k;
//		countRect.w = 0;
//		do {
//			countRect.w += 15;
//			k2 /= 10;
//		} while (k2 > 0);
//
//		//обработка текста
//		_itoa(k, text, 10);
//		textTexture = DrawText(window, renderer, text);
//		SDL_RenderCopy(renderer, textTexture, NULL, &countRect);
//
//		SDL_RenderPresent(renderer);
//
//		SDL_Delay(10);
//	}
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit();
//	return 0;
//}