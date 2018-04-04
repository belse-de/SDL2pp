/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
//#include <SDL.h>
#include <SDL2/SDL.h>
#include <stdio.h>
//typedef byte uint8_t;
//2-6 -> 2,3,4,5,6 =>6+1 - 2
#define ASCII_PRINTABLES 0x5F
//uint8_t CharBitmaps_16x8[0x5F][16]
uint8_t ASCII[ASCII_PRINTABLES][8]=
{ 
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Space => ASCII 0x20
  { 0x60, 0x60, 0x60, 0x60, 0x60, 0x00, 0x60, 0x00 }, // ! 
  { 0xA0, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // "
  { 0x00, 0x50, 0xF8, 0x50, 0xF8, 0x50, 0x00, 0x00 }, // #
  { 0x20, 0x78, 0xA0, 0x70, 0x28, 0xF0, 0x20, 0x00 }, // $
  { 0xC0, 0xC8, 0x10, 0x20, 0x40, 0x98, 0x18, 0x00 }, // %
  { 0x40, 0xA0, 0xA0, 0x40, 0xA8, 0x90, 0x68, 0x00 }, // &
  { 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // '
  { 0x10, 0x20, 0x40, 0x40, 0x40, 0x20, 0x10, 0x00 }, // (
  { 0x40, 0x20, 0x10, 0x10, 0x10, 0x20, 0x40, 0x00 }, // )
  { 0x00, 0x00, 0x50, 0x20, 0x50, 0x00, 0x00, 0x00 }, // *
  { 0x00, 0x20, 0x20, 0xF8, 0x20, 0x20, 0x00, 0x00 }, // +
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00 }, // ,
  { 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00 }, // -
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x00 }, // .
  { 0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00 }, // /
////////////////////// Zahlen ////////////////////////
  { 0x70, 0x88, 0x98, 0xA8, 0xC8, 0x88, 0x70, 0x00 }, // 0  => ASCII 0x30
  { 0x20, 0x60, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00 }, // 1
  { 0x70, 0x88, 0x08, 0x10, 0x20, 0x40, 0xF8, 0x00 }, // 2
  { 0x70, 0x88, 0x08, 0x30, 0x08, 0x88, 0x70, 0x00 }, // 3
  { 0x10, 0x30, 0x50, 0x90, 0xF8, 0x10, 0x10, 0x00 }, // 4
  { 0xF8, 0x80, 0xF0, 0x08, 0x08, 0x88, 0x70, 0x00 }, // 5
  { 0x30, 0x40, 0x80, 0xF0, 0x88, 0x88, 0x70, 0x00 }, // 6
  { 0xF8, 0x88, 0x08, 0x10, 0x10, 0x20, 0x20, 0x00 }, // 7
//    { 0xF8, 0x08, 0x10, 0x20, 0x40, 0x40, 0x40, 0x00 }, // 7
  { 0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x70, 0x00 }, // 8
  { 0x70, 0x88, 0x88, 0x78, 0x08, 0x10, 0x60, 0x00 }, // 9
//////////////////////////////////////////////////////
  { 0x00, 0x30, 0x30, 0x00, 0x30, 0x30, 0x00, 0x00 }, // :
  { 0x00, 0x30, 0x30, 0x00, 0x10, 0x20, 0x00, 0x00 }, // ;
  { 0x10, 0x20, 0x40, 0x80, 0x40, 0x20, 0x10, 0x00 }, // <
  { 0x00, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x00, 0x00 }, // =
  { 0x80, 0x40, 0x20, 0x10, 0x20, 0x40, 0x80, 0x00 }, // >
  { 0x70, 0x88, 0x08, 0x10, 0x20, 0x00, 0x20, 0x00 }, // ?
  { 0x00, 0x70, 0x88, 0xA8, 0x98, 0x60, 0x00, 0x00 }, // @
////////////// Großbuchstaben ////////////////////////
  { 0x70, 0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x00 }, // A  => ASCII 0x41
  { 0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0xF0, 0x00 }, // B
  { 0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70, 0x00 }, // C
  { 0xE0, 0x90, 0x88, 0x88, 0x88, 0x90, 0xE0, 0x00 }, // D
  { 0xF8, 0x80, 0x80, 0xF8, 0x80, 0x80, 0xF8, 0x00 }, // E
  { 0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0x80, 0x00 }, // F
  { 0x70, 0x88, 0x80, 0xB8, 0x88, 0x88, 0x78, 0x00 }, // G
  { 0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88, 0x00 }, // H
  { 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00 }, // I
  { 0x38, 0x08, 0x08, 0x08, 0x08, 0x48, 0x30, 0x00 }, // J
  { 0x88, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x88, 0x00 }, // K
  { 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xF8, 0x00 }, // L
  { 0x88, 0xD8, 0xA8, 0xA8, 0x88, 0x88, 0x88, 0x00 }, // M
  { 0x88, 0x88, 0xC8, 0xA8, 0x98, 0x88, 0x88, 0x00 }, // N
  { 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00 }, // O
  { 0xF0, 0x88, 0x88, 0xF0, 0x80, 0x80, 0x80, 0x00 }, // P
  { 0x70, 0x88, 0x88, 0x88, 0xA8, 0x90, 0x68, 0x00 }, // Q
  { 0xF0, 0x88, 0x88, 0xF0, 0xA0, 0x90, 0x88, 0x00 }, // R
  { 0x78, 0x80, 0x80, 0x70, 0x08, 0x08, 0xF0, 0x00 }, // S
  { 0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00 }, // T
  { 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00 }, // U
  { 0x88, 0x88, 0x88, 0x88, 0x88, 0x50, 0x20, 0x00 }, // V
  { 0x88, 0x88, 0x88, 0xA8, 0xA8, 0xA8, 0x50, 0x00 }, // W
  { 0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x00 }, // X
  { 0x88, 0x88, 0x88, 0x50, 0x20, 0x20, 0x20, 0x00 }, // J
  { 0xF8, 0x88, 0x10, 0x20, 0x40, 0x88, 0xF8, 0x00 }, // Z
//////////////////////////////////////////////////////
  { 0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x30, 0x00 }, // [
  { 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00 }, // '\\'
  { 0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 0x60, 0x00 }, // ]
  { 0x20, 0x50, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00 }, // ^
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00 }, // _
  { 0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // `
////////////// Kleinbuchstaben ///////////////////////
  { 0x00, 0x00, 0x68, 0x98, 0x88, 0x88, 0x78, 0x00 }, // a  => ASCII 0x61
  { 0x80, 0x80, 0xB0, 0xC8, 0x88, 0x88, 0xF0, 0x00 }, // b
  { 0x00, 0x00, 0x70, 0x80, 0x80, 0x88, 0x70, 0x00 }, // c
  { 0x08, 0x08, 0x68, 0x98, 0x88, 0x88, 0x78, 0x00 }, // d
  { 0x00, 0x00, 0x70, 0x88, 0xF8, 0x80, 0x70, 0x00 }, // e
  { 0x30, 0x48, 0x40, 0xE0, 0x40, 0x40, 0x40, 0x00 }, // f
  { 0x00, 0x78, 0x88, 0x88, 0x78, 0x08, 0x38, 0x00 }, // g
  { 0x80, 0x80, 0xB0, 0xC8, 0x88, 0x88, 0x88, 0x00 }, // h
  { 0x20, 0x00, 0x60, 0x20, 0x20, 0x20, 0x70, 0x00 }, // i
  { 0x10, 0x00, 0x30, 0x10, 0x10, 0x90, 0x60, 0x00 }, // j
  { 0x80, 0x80, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x00 }, // k
  { 0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00 }, // l
  { 0x00, 0x00, 0xD0, 0xA8, 0xA8, 0x88, 0x88, 0x00 }, // m
  { 0x00, 0x00, 0xB0, 0xC8, 0x88, 0x88, 0x88, 0x00 }, // n
  { 0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00 }, // o
  { 0x00, 0x00, 0xF0, 0x88, 0xF0, 0x80, 0x80, 0x00 }, // p
  { 0x00, 0x00, 0x68, 0x98, 0x78, 0x08, 0x08, 0x00 }, // q
  { 0x00, 0x00, 0xB0, 0xC0, 0x80, 0x80, 0x80, 0x00 }, // r
  { 0x00, 0x00, 0x70, 0x80, 0x70, 0x08, 0xF0, 0x00 }, // s
  { 0x40, 0x40, 0xE0, 0x40, 0x40, 0x48, 0x30, 0x00 }, // t
  { 0x00, 0x00, 0x88, 0x88, 0x88, 0x98, 0x68, 0x00 }, // u
  { 0x00, 0x00, 0x88, 0x88, 0x88, 0x50, 0x20, 0x00 }, // v
  { 0x00, 0x00, 0x88, 0x88, 0xA8, 0xA8, 0x50, 0x00 }, // w
  { 0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00 }, // x
  { 0x00, 0x00, 0x88, 0x88, 0x78, 0x08, 0x70, 0x00 }, // y
  { 0x00, 0x00, 0xF8, 0x10, 0x20, 0x40, 0xF8, 0x00 }, // z
//////////////////////////////////////////////////////
  { 0x10, 0x20, 0x20, 0x40, 0x20, 0x20, 0x10, 0x00 }, //  {
  { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00 }, //  |
  { 0x40, 0x20, 0x20, 0x10, 0x20, 0x20, 0x40, 0x00 }, //  }
  { 0x00, 0x50, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00 }, //  ~
};

//Screen dimension constants
const int SCREEN_WIDTH  = 320;
const int SCREEN_HEIGHT = 240;


//Starts up SDL and creates window
bool init();
//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window   *gWindow   = nullptr;
SDL_Renderer *gRenderer = nullptr;
SDL_Texture  *gTexture  = nullptr;


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", 
		    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		    SCREEN_WIDTH, SCREEN_HEIGHT, 
		    SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN );
		if( gWindow == nullptr )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
			if( gRenderer == nullptr )
		  {
			  printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
			  success = false;
		  }
		  else
		  {
		    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" ) ) {
          printf("Warning: Linear texture filtering not enabled!\n");
        }
        else
        {
          SDL_RenderSetLogicalSize(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);
        }
        
			  gTexture  = SDL_CreateTexture(gRenderer, 
			      SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
			  if( gTexture == nullptr )
		    {
			    printf( "Texture could not be created! SDL_Error: %s\n", SDL_GetError() );
			    success = false;
		    }
		    else
		    {
		      SDL_SetTextureBlendMode( gTexture, SDL_BLENDMODE_BLEND);
		    }
		  }

		}
	}

	return success;
}

void close()
{
  SDL_DestroyTexture(gTexture);
  gTexture = nullptr;
  SDL_DestroyRenderer(gRenderer);
  gRenderer = nullptr;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

int main( void )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
	  //CharBitmaps_16x8
	  SDL_Texture  *char_tex  = 
	      SDL_CreateTexture(gRenderer, 
	      SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 
	      8*ASCII_PRINTABLES, 8);
	  SDL_SetTextureBlendMode( char_tex, SDL_BLENDMODE_BLEND);
	  SDL_SetRenderTarget(gRenderer, char_tex);
	  SDL_SetRenderDrawColor(gRenderer, 0x55, 0x55, 0x55, 0x33); //  0x88, 0x55, 0x00, 0xFF);
    SDL_RenderClear(gRenderer);
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);//0x11, 0xAA, 0x33, 0xFF); //  0x00, 0x33, 0x66, 0xFF);
    
    for(int c=0; c<ASCII_PRINTABLES; c++)
    {
	    for(int y=0; y<8; y++)
	    {
	      uint8_t current_row = ASCII[c][y];
	      for(int x=0; x<8; x++)
	      {
	        uint8_t current_bit = ((1u<<(7-x))&current_row);
	        if(current_bit) {
	          SDL_RenderDrawPoint(gRenderer, x+c*8, y);
	        }
	      }
	    }
	  }
	  
	  
	  
	  bool running = true;
    while (running) {
      SDL_Event event;
      SDL_PollEvent(&event);
      if(event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
        printf("QUIT\n");
        running = false;
        break;
      }

	  
	    SDL_SetRenderTarget(gRenderer, gTexture);
      SDL_SetRenderDrawColor(gRenderer, 0x22, 0x22, 0x22, 0xFF); //  0x88, 0x44, 0x00, 0xFF);
      SDL_RenderClear(gRenderer);
      SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
      SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
      SDL_Rect src_rect;src_rect.x=0;src_rect.y=0;src_rect.w=8;src_rect.h=8;
      SDL_Rect dst_rect;dst_rect.x=0;dst_rect.y=0;dst_rect.w=8;dst_rect.h=8;
      
      for(int c=0; c<ASCII_PRINTABLES; c++)
      {
        src_rect.x = c*8;
        dst_rect.x = (c*8)%(32*8);
        dst_rect.y = ((c*8)/(32*8))*8;
        SDL_RenderCopy(gRenderer, char_tex, &src_rect, &dst_rect);
        
      }

      SDL_SetRenderTarget(gRenderer, nullptr);
      SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
      SDL_RenderClear(gRenderer);
      SDL_RenderCopy(gRenderer, gTexture, nullptr, nullptr);
      SDL_RenderPresent(gRenderer);

			//Wait two seconds
			SDL_Delay( 1000/25 );
		}
		
		SDL_DestroyTexture(char_tex);
	}

	//Free resources and close SDL
	close();

	return 0;
}

