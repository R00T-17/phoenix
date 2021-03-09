#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

// Created By Phoenix Team // 



int main()
{
    SDL_Surface *sound=NULL,*screenb=NULL,*screen=NULL,*up2=NULL,*mute2=NULL,*down2=NULL,*fullscreen,*normal,*retour2=NULL, *image= NULL,*up=NULL,*down=NULL, *texte=NULL,*texte2=NULL,*texte3,*play=NULL,*quit=NULL,*option=NULL,*play2=NULL,*quit2=NULL,*option2=NULL,*retour=NULL,*mute=NULL;

    SDL_Rect soundpos,screenbpos,retour2pos,fullscreenpos,normalpos,uppos,downpos,mutepos,text3pos,positionecran,playpos,optionpos,quitpos,playpos2,optionpos2,quitpos2,positionTxt,positionClic,positionback,retourpos,text1pos,text2pos;
    SDL_Event event;
    TTF_Font *police=NULL,*police2=NULL;
    SDL_Color color= {0,0,0};


char menu[40];  SDL_Surface *img[1000] ;
    int continuer =1,curseur=0,c=0,i,v;
      
    // Audio // 
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {

        printf("Error init audio %s \n",Mix_GetError());
        return 1;
    }


    Mix_Music *music=NULL;
    music=Mix_LoadMUS("song.mp3");
    Mix_PlayMusic(music,-1);
    Mix_Chunk *click;
    click=Mix_LoadWAV("effect.wav");
    
         // Video 

    SDL_Init(SDL_INIT_VIDEO);
    
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL :%s\n",SDL_GetError());
        return 1;
    }
                                                                
    image=IMG_Load("back2.jpg");                                         
    play=IMG_Load("play1.png");                                         
    option=IMG_Load("options1.png");
    quit=IMG_Load("quit1.png");
    play2=IMG_Load("play2.png");
    option2=IMG_Load("options2.png");
    quit2=IMG_Load("quit2.png");
    mute=IMG_Load("mute.png");
    mute2=IMG_Load("mute2.png");
    retour=IMG_Load("retour1.png");
    retour2=IMG_Load("retour2.png");
    up=IMG_Load("up.png"); 
    up2=IMG_Load("up2.png");
    down=IMG_Load("down.png");
    down2=IMG_Load("down2.png") ;
    fullscreen=IMG_Load("fullscreen.png"); 
    normal=IMG_Load("normal.png");
    screenb=IMG_Load("screen.png");
    sound=IMG_Load("sound.png");
         retourpos.x=20;
         retourpos.y=440; 
        
         retour2pos.x=20;
         retour2pos.y=440;  
        
        positionecran.x=0;
        positionecran.y=10; 

         playpos.x=280;
         playpos.y=140;

         playpos2.x=279;
         playpos2.y=138;

        quitpos.x=280;
        quitpos.y=300;
        quitpos2.x=279;
        quitpos2.y=298;
        text1pos.x=180; 
        text1pos.y=10;
        text2pos.x=180; 
        text2pos.y=350;
        text3pos.x=250; 
        text3pos.y=10;
        soundpos.x=280; 
        soundpos.y=140;
        mutepos.x=230; 
        mutepos.y=218; 
        downpos.x=330; 
        downpos.y=218; 
        uppos.x=430; 
        uppos.y=218;  
        screenbpos.x=280; 
        screenbpos.y=320;
        fullscreenpos.x=250;
        fullscreenpos.y=400; 
        normalpos.x=380; 
        normalpos.y=400;

        positionecran.x=0;
        positionecran.y=0;
        
     // TTF //

     TTF_Init();

    police=TTF_OpenFont("blowbrush.ttf",85);
    police2=TTF_OpenFont("blowbrush.ttf",70);
    if(police==NULL)
    {
        printf("erreur font %s\n",SDL_GetError());
        return 1;
    }
    texte=TTF_RenderText_Blended(police,"     Menu ",color);

        v=64;
         screen=SDL_SetVideoMode(750,500,32,SDL_HWSURFACE );// fenetre //
        SDL_WM_SetCaption("[ MENU ]",NULL);
        int y=0;
        positionback.x=0; 
        positionback.y=0;
        while(y<75){
                 while (SDL_PollEvent(&event))
        { 
            switch(event.type)
            {
            case SDL_QUIT:
            {
                return EXIT_SUCCESS;
                break;

            }
        }
    }
sprintf(menu,"image/Layer %d.png",y);
img[y]=IMG_Load(menu); 
SDL_BlitSurface(img[y],NULL,screen,&positionback);
SDL_Delay(25);
y++;
SDL_Flip(screen);
SDL_FreeSurface(img[y]);
}
  y=1; 

     // boucle de jeu // 
    while(continuer)
    { 
           optionpos.x=280;
        optionpos.y=220;
        optionpos2.x=279;
        optionpos2.y=218;
        Mix_VolumeMusic(v);
           if(y>57){
    y=1;
}         
         sprintf(menu,"animation/back%d.png",y);
img[y]=IMG_Load(menu); 
SDL_BlitSurface(img[y],NULL,screen,&positionecran);
 y++;
SDL_Delay(10);

   
        SDL_BlitSurface(texte,NULL,screen,&text1pos);
        SDL_BlitSurface(play,NULL,screen,&playpos);
        SDL_BlitSurface(option,NULL,screen,&optionpos);
        SDL_BlitSurface(quit,NULL,screen,&quitpos);

              if (curseur==1)
        {
            SDL_BlitSurface(play2, NULL, screen, &playpos2);

        }
     
        if (curseur==2)
        {
            SDL_BlitSurface(option2, NULL, screen, &optionpos2);
              
positionback.x=50; 
positionback.y=130; 

        }

        if (curseur==3)
        {
            SDL_BlitSurface(quit2, NULL, screen, &quitpos2);

        }

        SDL_Flip(screen);
        SDL_FreeSurface(img[y]);
                 
        while (SDL_PollEvent(&event))
        { 
            switch(event.type)
            {
            case SDL_QUIT:
            {
                continuer=0;
                break;

            }
            case SDL_MOUSEMOTION:
             {
                if ((event.motion.x>playpos.x )&&(event.motion.x<playpos.x+playpos.w)&&(event.motion.y>playpos.y)&&(event.motion.y<playpos.y+playpos.h))
                {
                    curseur=1;
                    if (v>0){
                    Mix_PlayChannel(-1,click,0);
                   }
                }
                else if ((event.motion.x>optionpos.x)&&(event.motion.x<optionpos.x+optionpos.w)&&(event.motion.y>optionpos.y)&&(event.motion.y<optionpos.y+optionpos.h))
                {
                    curseur=2;
                               if (v>0){
                    Mix_PlayChannel(-1,click,0);
                   }
                }
                else if ((event.motion.x>quitpos.x)&&(event.motion.x<quitpos.x+quitpos.w)&&(event.motion.y>quitpos.y)&&(event.motion.y<quitpos.y+quitpos.h))
                {
                    curseur=3;
                               if (v>0){
                    Mix_PlayChannel(-1,click,0);
                   }

                }
                else
                    curseur=0;
                    break;

            }


            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym==SDLK_DOWN)
                {
                    c++;
                    if(c>3)
                    {
                        c=1;
                    }

                    if (c==1)
                    {
                        curseur=c;
                        Mix_PlayChannel(-1,click,0);
                    }
                    else if (c==2)
                    {
                        curseur=c;
                        Mix_PlayChannel(-1,click,0);
                    }

                    else if (c==3)
                    {
                        curseur=c;
                        Mix_PlayChannel(-1,click,0);
                    }


                }   
         

                if (event.key.keysym.sym==SDLK_UP)
                {
                    c--;
                    if(c<1)
                    {
                        c=3;
                    }
                }

                if (c==3)
                {
                    curseur=c;
                    Mix_PlayChannel(-1,click,0);

                }
                else if (c==2)
                {
                    curseur=c;
                    Mix_PlayChannel(-1,click,0);
                }
                else if (c==1)
                {
                    curseur=c;
                    Mix_PlayChannel(-1,click,0);
                }
                if(event.key.keysym.sym==SDLK_ESCAPE)
                {
                return EXIT_SUCCESS;  
                break;
                }
                 
 }
}
            }
        
                  // quit 
              
               if(curseur==3){
                switch(event.type){
                 case SDL_MOUSEBUTTONUP:
                    if (event.button.button==SDL_BUTTON_LEFT){
                     continuer=0; 
                    }
                 }                
               }
    
            


              if (curseur==2){
                     switch(event.type){
                 case SDL_MOUSEBUTTONUP:
                    if (event.button.button==SDL_BUTTON_LEFT){
                       i=0;

                    while(i==0){
                    optionpos.x=280;
                     optionpos.y=40;
                   SDL_BlitSurface(image,NULL,screen,&positionecran);
                   SDL_BlitSurface(retour,NULL,screen,&retourpos);
                   SDL_BlitSurface(mute,NULL,screen,&mutepos);
                   SDL_BlitSurface(down,NULL,screen,&downpos);
                   SDL_BlitSurface(up,NULL,screen,&uppos);
                   SDL_BlitSurface(screenb,NULL,screen,&screenbpos);
                   SDL_BlitSurface(fullscreen,NULL,screen,&fullscreenpos);
                   SDL_BlitSurface(normal,NULL,screen,&normalpos);
                    SDL_BlitSurface(option,NULL,screen,&optionpos);
                    SDL_BlitSurface(sound,NULL,screen,&soundpos);
                   SDL_Flip(screen); 
     
                     while (SDL_PollEvent(&event))
        { 
                   switch(event.type){                                    
                    case SDL_QUIT: {                                      
                         i=1; 
                        continuer=0; 
                       return  EXIT_SUCCESS;
                       break;
                    }

                    case SDL_MOUSEMOTION:
                   {
                if ((event.motion.x>retourpos.x )&&(event.motion.x<retourpos.x+retourpos.w)&&(event.motion.y>retourpos.y)&&(event.motion.y<retourpos.y+retourpos.h))
                {   
                     curseur=4; 
                     if (v>0){
                     Mix_PlayChannel(-1,click,0);
                   }
                   }
                    
                     
                 }
                 }
             }
         
              if (curseur==4){
              switch(event.type)
            {  
                    case SDL_MOUSEBUTTONUP:
                         if (event.button.button==SDL_BUTTON_LEFT){
                   i=1;
               }
           
                }
                } 

                  switch(event.type){
                     case SDL_MOUSEMOTION : {
                    if ((event.motion.x>mutepos.x )&&(event.motion.x<mutepos.x+mutepos.w)&&(event.motion.y>mutepos.y)&&(event.motion.y<mutepos.y+mutepos.h))
                {   
                     curseur=6; 
                     SDL_BlitSurface(mute2,NULL,screen,&mutepos);


                   
                   }
                   else if  ((event.motion.x>downpos.x )&&(event.motion.x<downpos.x+downpos.w)&&(event.motion.y>downpos.y)&&(event.motion.y<downpos.y+downpos.h))
                {   
                     curseur=7; 
                     SDL_BlitSurface(down2,NULL,screen,&downpos);

                      
                   }
                   else  if ((event.motion.x>uppos.x )&&(event.motion.x<uppos.x+uppos.w)&&(event.motion.y>uppos.y)&&(event.motion.y<uppos.y+uppos.h))
                {   
                     curseur=8; 
                     SDL_BlitSurface(up2,NULL,screen,&uppos);
                    
                   
                   }
                   SDL_Flip(screen);
                   SDL_Delay(150);

                     }

                  }

                  if (curseur==6){
                         switch(event.type)
            {  
                   case SDL_MOUSEBUTTONUP:
                         if (event.button.button==SDL_BUTTON_LEFT){
                   v=0;
                   Mix_VolumeMusic(v);
                   SDL_Flip(screen);
               }
           
                }

                  }

                        if (curseur==7){
                            
                         switch(event.type)
            {  
                    case SDL_MOUSEBUTTONUP:
                         if (event.button.button==SDL_BUTTON_LEFT){

                                if (v>0){
                                    v-=16; 
                                    curseur=0;
                              }

                   Mix_VolumeMusic(v); 
                   SDL_Flip(screen);
               }
                }

                  
                  } 
                         if (curseur==8){
                            
                         switch(event.type)
            {  
                    case SDL_MOUSEBUTTONUP:
                         if (event.button.button==SDL_BUTTON_LEFT){
                                if (v<128){
                                    v+=16; 
                                    curseur=0;
                              }

                   Mix_VolumeMusic(v); 
                   SDL_Flip(screen);
               }
                }

                  
                  }

                                       while (SDL_PollEvent(&event))
        {                                   switch(event.type){
                                                     case SDL_MOUSEBUTTONUP:
                                                     {
if ((event.button.x>fullscreenpos.x) && (event.button.x<fullscreenpos.x+fullscreenpos.w) && (event.button.y>fullscreenpos.y && event.button.y<fullscreenpos.y+fullscreenpos.h)&&(event.button.button == SDL_BUTTON_LEFT))
                   {
                            screen = SDL_SetVideoMode(1920,1080, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
                            if (v>0){
                            Mix_PlayChannel(-1,click,0);
                            }
                            SDL_Flip(screen);
                   }

                        else if ((event.button.x>normalpos.x) && (event.button.x<normalpos.x+normalpos.w) && (event.button.y>normalpos.y) && (event.button.y<normalpos.y+normalpos.h) && (event.button.button == SDL_BUTTON_LEFT))
                        {
                            screen=SDL_SetVideoMode(748,500,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
                            if (v>0){
                            Mix_PlayChannel(-1,click,0);
                        }
                            SDL_Flip(screen);

                        }
     
          }  
      }
  }
}
}
}

}

   if(curseur==1){
                switch(event.type){
                 case SDL_MOUSEBUTTONUP:
                    if (event.button.button==SDL_BUTTON_LEFT){
                        i=0; 
                        while (i==0){ 
                        SDL_WM_SetCaption("[ GAME ]",NULL);
                     SDL_BlitSurface(image,NULL,screen,&positionecran);
                     SDL_BlitSurface(retour,NULL,screen,&retourpos);
                     texte3=TTF_RenderText_Blended(police," GAME ",color);
                     SDL_BlitSurface(texte3,NULL,screen,&text3pos);
                     SDL_Flip(screen);



                            while (SDL_PollEvent(&event))
        { 
                   switch(event.type){
                      case SDL_QUIT: {
                           i=1; 
                           continuer=0; 
                           return EXIT_SUCCESS; 
                           break; 

                      }

                    case SDL_MOUSEMOTION:
                   {
                if ((event.motion.x>retourpos.x )&&(event.motion.x<retourpos.x+retourpos.w)&&(event.motion.y>retourpos.y)&&(event.motion.y<retourpos.y+retourpos.h))
                {   
                     curseur=5; 
                     if (v>0){
                     Mix_PlayChannel(-1,click,0);
                   }
                   }
                    
                     
                 }

                 }
             }
         
              if (curseur==5){
                        
              switch(event.type)
            {           
                    case SDL_MOUSEBUTTONUP:
                         if (event.button.button==SDL_BUTTON_LEFT){
                   i=1;
               }
           
                }
                } 
                   

                    }
                 }                
               }

           
           
}

}

               



    TTF_CloseFont(police);
    Mix_FreeMusic(music);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Quit();
     return EXIT_SUCCESS; 
    
}   