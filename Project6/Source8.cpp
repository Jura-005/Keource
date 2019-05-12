#define _CRT_SECURE_NO_WARNINGS 
#define kol 8
#include "SDL.h" 
#include "math.h" 
#include "stdio.h" 
#include<stdio.h> 
#include<stdlib.h> 
#include<locale.h> 
#include <ctime> 
#include <conio.h> 
#include <SDL_ttf.h> 
typedef struct Color
{
	int r, g, b;
}color;
//��������� ���������� ����
void kartinka_start_menu(SDL_Window* window, SDL_Renderer* &renderer)
{
	SDL_Surface *myImage = SDL_LoadBMP("FON1.bmp");
	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
	SDL_Rect rect = { 0,0,1280,720 };
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_FreeSurface(myImage);
	SDL_DestroyTexture(texture);
}
//��������� �������� ����
void kartinka_start(SDL_Window* window, SDL_Renderer* &renderer)
{
	SDL_Surface *myImage = SDL_LoadBMP("Menu_game.bmp");
	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
	SDL_Rect rect = { 0,0,1280,720 };
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_FreeSurface(myImage);
	SDL_DestroyTexture(texture);
}
/*�-� ��������� ���������� ��� ���������� ������ ����
��������� ����� k - ���-�� ������ �������*/
int znakomesto(int k)
{
	int a = 0;
	do
	{
		k = k / 10;
		a++;
	} while (k > 0);
	return a;
}
//��������� ���� �� ������� ����
//k-����� ��� ������, i-������� �����
void pokaz_4icel(SDL_Window*window, SDL_Renderer* &renderer, int k, int i)
{
	int a;
	int b;
	b = znakomesto(k);
	a = 6 - b;
	char *text = new char[10];
	_itoa(k, text, 10);
	TTF_Init();
	TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);
	SDL_Color fore_color = { 0,0,0 };
	SDL_Color back_color = { 255,255,255 };
	SDL_Rect *rect = new SDL_Rect[3];
	//������
	rect[1] = { 1129 + 23 * a,79,23 * b,40 };
	//���
	rect[2] = { 1129 + 23 * a,199,23 * b,40 };
	//������
	rect[3] = { 1129 + 23 * a,317,23 * b,40 };
	SDL_Surface* textSurface = NULL;
	textSurface = TTF_RenderText_Shaded(my_font, text, fore_color, back_color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_RenderCopy(renderer, texture, NULL, &rect[i]);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(my_font);
	TTF_Quit();
}
void random_romb_color(SDL_Window* window, SDL_Renderer* renderer,  SDL_Rect rect, int t)
{
		SDL_SetRenderDrawColor(renderer, 125, 50,100, 0);
	
	
			for (int i = 0; i < t; i++)
			{

				SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.w, rect.h);
				rect.x++;
				rect.y++;
				rect = { rect.x,rect.y,rect.x + t,rect.y - t };
			}
}
void romb_color(SDL_Window* window, SDL_Renderer* renderer, int t)
{
	for (int i = 0; i < kol; i++)
	{
		int x[kol], y[kol];
		x[i] = rand() % 1000; y[i] = rand() % 600;
		SDL_Rect rect = { x[i],y[i],x[i] + t,y[i] - t };
		random_romb_color(window, renderer, rect, t);
	}
}
void romb1(SDL_Window* window, SDL_Renderer*renderer, SDL_Rect rect, int t, Color color[])
{
		SDL_SetRenderDrawColor(renderer,color->r, color->g, color->b, 0);
		for (int i = 0; i < t; i++)
		{

			SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.w, rect.h);
			rect.x++;
			rect.y++;
			rect = { rect.x,rect.y,rect.x + t,rect.y - t };
		}
}
//�-� ������� ���� �� ���������� x � y �������� t
void romb(SDL_Renderer*renderer, SDL_Rect rect, int t)
{
	SDL_SetRenderDrawColor(renderer, 128, 128, 128, 0);
	for (int i = 0; i < t; i++)
	{
		SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.w, rect.h);
		rect.x++;
		rect.y++;
		rect = { rect.x,rect.y,rect.x + t,rect.y - t };
	}
}
//������� ������� ���� 
//t-���������� ������������ �����
void map_ren(SDL_Window* window, SDL_Renderer* renderer, int t, Color color[])
{

	int map[1000][2];
	FILE*tf;
	int i;
	fopen_s(&tf, "map.txt", "r");
	fscanf_s(tf, "%d", &i);
	for (int j = 1; j <= i; j++)
	{
		fscanf_s(tf, "%d %d ", &map[j][0], &map[j][1]);
	}
	fclose(tf);
	
	for (int j = 1; j <= i; j++)
	{

		SDL_Rect rect = { map[j][0] , map[j][1] , map[j][0] + t , map[j][1] - t };
		romb(renderer, rect, t);
	}
	int k = 0;
	for (int j = rand()%20; j <= i; j+=9)
	{
		k++;	
		SDL_Rect rect = { map[j][0] , map[j][1] , map[j][0] + t , map[j][1] - t };
		if (k<=kol)
		romb1(window,renderer, rect, t,&color[k-1]);
	}
	int j = rand() % i;
	SDL_Rect rect1 = { map[j][0],map[j][1],map[j][0] + t,map[j][1] - t };
	random_romb_color(window, renderer, rect1, t);
	SDL_RenderPresent(renderer);
}
void map_create(SDL_Window*window, SDL_Renderer*renderer, SDL_Rect rect, int x, int y, int t)
{
	int map[1000][2];
	int i = 1;
	int k = 0;
	int p = 1;
	map[i][0] = x;
	map[i][1] = y;
	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		for (int j = 1; j <= p; j++)
		{
			if (map[j][0] == x && map[j][1] == y)
				k++;
		}
		if (k == 0)
		{
			i++;
			map[i][0] = x;
			map[i][1] = y;

		}
		k = 0;
		SDL_PollEvent(&event);
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_UP) && (x > t) && (y > 2 * t))
		{
			p++;
			x = x - t; y = y - t;
			SDL_Rect rect = { x,y,x + t,y - t };
			romb(renderer, rect, t);
			SDL_Delay(200);
		}
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_DOWN) && (x < 1120 - 2 * t) && (y < 560 - 2 * t))
		{
			p++;
			x = x + t; y = y + t;
			SDL_Rect rect = { x,y,x + t,y - t };
			romb(renderer, rect, t);
			SDL_Delay(200);
		}
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_LEFT) && (x > t) && (y < 560 - 2 * t))
		{
			p++;
			x = x - t; y = y + t;
			SDL_Rect rect = { x,y,x + t,y - t };
			romb(renderer, rect, t);
			SDL_Delay(200);
		}
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RIGHT) && (x < 1120 - 2 * t) && (y > 2 * t))
		{
			p++;
			x = x + t; y = y - t;
			SDL_Rect rect = { x,y,x + t,y - t };
			romb(renderer, rect, t);
			SDL_Delay(200);
		}
		SDL_RenderPresent(renderer);
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_1))
			quit = true;
	}
	FILE*tf;
	fopen_s(&tf, "map.txt", "w");
	fprintf(tf, "%d\n", i);
	for (int j = 1; j <= i; j++)
	{
		fprintf(tf, "%d %d\n ", map[j][0], map[j][1]);
	}
	fclose(tf);

}

//������� ��������� ����� ����� 
void obvodka(SDL_Renderer* renderer, int x, int y, int t)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderDrawLine(renderer, x, y, x + t, y - t);
	SDL_RenderDrawLine(renderer, x, y, x + t, y + t);
	SDL_RenderDrawLine(renderer, x + t, y - t, x + t + t, y);
	SDL_RenderDrawLine(renderer, x + t, y + t, x + t + t, y);
}
//��������� ���������, k-����� ������ r-���������
void ind_sost(SDL_Renderer* renderer, int k, int r)
{
	//���������� �����
	SDL_Rect *cord_color = new SDL_Rect[10];
	cord_color[1] = { 1169,385,8,8 };
	cord_color[2] = { 1169,414,8,8 };
	cord_color[3] = { 1169,442,8,8 };
	cord_color[4] = { 1169,471,8,8 };
	cord_color[5] = { 1169,498,8, 8 };
	cord_color[6] = { 1237,385,8,8 };
	cord_color[7] = { 1237,412,8,8 };
	cord_color[8] = { 1237,441,8,8 };
	cord_color[9] = { 1237,470,8,8 };
	if (r == 0)
	{
		SDL_Surface *myImage = SDL_LoadBMP("ind_st0.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord_color[k]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (r == 1)
	{
		SDL_Surface *myImage = SDL_LoadBMP("ind_st1.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord_color[k]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (r == 2)
	{
		SDL_Surface *myImage = SDL_LoadBMP("ind_st2.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord_color[k]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
}
//������ ���-�� ��������
struct Resyrs
{
	int gold; int eat; int metl;
};
int main(int argc, char** argv)

{
	int t = 50;
	int x = 50, y = 100;
	SDL_Rect rect = { x,y,x + t,y - t };
	Color color[9] = { 255,0,0,0,255,0,0,0,255,255,128,0,255,0,128,128,0,255,255,128,255,
	128,255,255	,255,255,128 };
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(u8"����", 7, 29, 1280, 720, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 1);
	SDL_Event event;
	//������ ��������� �����/////////////////////////////////
	SDL_Rect *start = new SDL_Rect[2];
	//���������� ������
	start[0] = { 426,173,432,108 };
	//���������� �����
	start[1] = { 489,563,309,112 };
	//���������� ����� �����
	//������� ��������////////////////////////////////////////////////
	Resyrs Player_res[10];
	for (int i = 0; i < 10; i++)
	{
		Player_res[i].gold = 10;
		Player_res[i].eat = 10;
		Player_res[i].metl = 10;
	}
	//������ ��������////////////////////////////////////////////

	//����� ������////////////////////////////////////////////////////

	//��������� ����� ��������///////////////////////////////////////////////
	//1-� ����� ����� ������, 2-� ����� � ����� ������ ������� ���������
	//0-�����������
	//1-�����
	//2-����
	int Player_sost[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Player_sost[i][j] = 0;
		}
	}
	//���������� �����////////////////////////////////////////
	int map[1000][2];
	int kole;
	FILE*tf;
	fopen_s(&tf, "map.txt", "r");
	fscanf_s(tf, "%d", &kole);
	for (int i = 1; i <= kole; i++)
	{
		fscanf_s(tf, "%d %d ", &map[i][0], &map[i][1]);
	}
	fclose(tf);
	
	//������ ��������� ����////////////////////////////////////////////
	bool quit = false;
	while (!quit)
	{
		//��������� ���������� ����////////////////////////////
		kartinka_start_menu(window, renderer);
		SDL_RenderPresent(renderer);
		SDL_PollEvent(&event);
		if (event.button.button == SDL_BUTTON_LEFT)
		{
		

			for (int i = 0; i < 2; i++)
			{
				if (event.button.x >= start[0].x && event.button.x <= start[0].x + start[0].w && event.button.y >= start[0].y && event.button.y <= start[0].y + start[0].h)
				{
					//������� ����/////////////////////////////
					while (!quit)
					{
						
						//��������� ���� ��������������
						kartinka_start(window, renderer);
						//����� ����
						map_ren(window, renderer, t, color);
						system("pause");
						//��������� �������� �� �����
						pokaz_4icel(window, renderer, Player_res[0].gold, 1);
						pokaz_4icel(window, renderer, Player_res[0].eat, 2);
						pokaz_4icel(window, renderer, Player_res[0].metl, 3);
						//��������� ��������� � �� ��������
						for (int j = 1; j < 10; j++)
						{
							ind_sost(renderer, j, Player_sost[0][j]);
						}
						//���������///////////////
						SDL_RenderPresent(renderer);
						//��������� ���//////////////////////////////////////////////////
						if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 1125 && event.button.x <= 1276 && event.button.y >= 566 && event.button.y <= 716))
						{
							//���� ���������� �����
						}
						//��������� ����� ��� �������
						for (int j = 1; j <= kol; j++)
						{
							if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= map[j][0] && event.button.x <= map[j][0] + 2 * t&&event.button.y >= map[j][1] - t && event.button.y <= map[j][1] + t))
							{
								obvodka(renderer, map[j][0], map[j][1], t);
								//������ �� ������ ����////////////////
								//�������
								//��������
								//�������������
							}
						}

					}
				}
				//������ ������////////////////////////////////////////////
				if (event.button.x >= start[1].x && event.button.x <= start[1].x + start[1].w && event.button.y >= start[1].y && event.button.y <= start[1].y + start[1].h)
					quit = true;
			}
		}
	
		if (event.type == SDL_QUIT)
			quit = true;
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit;
	return 0;
}