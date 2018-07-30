#!/usr/bin/python3

import time,os
try:
    import pygame
except  ModuleNotFoundError:
    os.system("echo \"sudo pip3 install pygame\"")
    if os.system("sudo pip3 install pygame"):
        import pygame
    else:
        os.system("echo \"install pygame error\"")
        exit()
from pygame.locals import *
pygame.init()
screen = pygame.display.set_mode((500,500))
myfont=pygame.font.Font(None,60)
white = 255,255,255
blue = 0,0,255
textImage=myfont.render("boy",True,white)
screen.fill(blue)
screen.blit(textImage,(100,100))
pygame.display.update()
time.sleep(1)
screen.fill(white)
screen.blit(textImage,(100,100))
pygame.display.update()
