#include "game.h"


//=================================================
// Funcao OnEvent
//-------------------------------------------------
// Responsavel por manusear os eventos que ocorrem
// na janela do jogo. (mouse, teclado etc)
//=================================================

void OnEvent(SDL_Event* _event)
{
    // Checa o tipo de evento
    switch(_event->type)
    {
        // Caso haja evento com o mouse
        case SDL_MOUSEMOTION:
        {
            int x, y;
            SDL_GetMouseState( &x, &y);
            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        {
            // Checa se houve click e o tipo dele
            int x, y;
            SDL_GetMouseState( &x, &y);
            //checkClick(x, y);
        }
        break;

        // Caso encerre a aplicacao
        case SDL_QUIT:
            _Running = false;
             MenuOn = false;;
            break;

        // Caso pressione alguma tecla
        case SDL_KEYDOWN:
        {
            switch( _event->key.keysym.sym )
            {
                // Tecla ESC (Encerra aplicacao)
                case SDLK_ESCAPE:
                {
                        MenuOn = true;
                }
                break;

                case SDLK_UP:
                    if (_gPad1rect.y >= 10)
                        _gPad1rect.y -= 20;
                break;

                case SDLK_DOWN:
                if (_gPad1rect.y <= 600)
                    _gPad1rect.y += 20;
                break;
            }
            break;
        } // fim KEYDOWN

    } // fim _event->type

}


//=================================================
// Funcao OnMenuEvent
//-------------------------------------------------
// Responsavel por manusear os eventos que ocorrem
// no menu do jogo. (mouse, teclado etc)
//=================================================

void OnMenuEvent(SDL_Event* _event)
{
    // Checa o tipo de evento
    switch(_event->type)
    {
        // Caso haja evento com o mouse
        case SDL_MOUSEMOTION:
        {
            int x, y;
            SDL_GetMouseState( &x, &y);
            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        {
            // Checa se houve click e o tipo dele
            int x, y;
            SDL_GetMouseState( &x, &y);
            //checkClick(x, y);
        }
        break;

        // Caso encerre a aplicacao
        case SDL_QUIT:
            _Running = false;
             MenuOn = false;;
            break;

        // Caso pressione alguma tecla
        case SDL_KEYDOWN:
        {
            switch( _event->key.keysym.sym )
            {
                // Tecla ESC (Encerra aplicacao)
                case SDLK_ESCAPE:
                {
                    if(MenuOn)
                        MenuOn = false;
                    else
                        MenuOn = true;
                }
                break;

                case SDLK_UP:
                    if (_gBolaMenurect.y >= 10)
                    {
                        if (_gBolaMenurect.y <= 240)
                            _gBolaMenurect.y = 570;
                        else
                            _gBolaMenurect.y -= 110;
                    }
                break;

                case SDLK_DOWN:
                    if (_gBolaMenurect.y <= 600)
                    {
                        if (_gBolaMenurect.y >= 570)
                            _gBolaMenurect.y = 240;
                        else
                            _gBolaMenurect.y += 110;
                    }
                break;

                case SDLK_RETURN:
                    if (_gBolaMenurect.y <= 240)
                        MenuOn = false;
                    else if (_gBolaMenurect.y >= 540)
                    {
                        _Running = false;
                        MenuOn = false;
                    }
            }
            break;
        } // fim KEYDOWN

    } // fim _event->type

}
